#include <reg52.h> 

typedef unsigned char uchar;
typedef unsigned int  uint;

/* 硬件接口定义 */
sbit beep = P3^6;  // 蜂鸣器连接至P3.6口

/**
 * 音高频率表（定时器初值控制）
 * 原理：通过定时器产生方波，改变方波频率从而改变音调
 */
// 低音1-7，中音1-7，高音1-5 的定时器重装载高位 (TH0)
code uchar FREQH[] = { 
    0xF3, 0xF3, 0xF1, 0xF5, 0xF6, 0xF7, 0xF8,  // 低音区
    0xF9, 0xF9, 0xFA, 0xFA, 0xFB, 0xFB, 0xFC,  // 中音区 
    0xFC, 0xFD, 0xFD, 0xFD, 0xFD, 0xFE         // 高音区 
}; 

// 低音1-7，中音1-7，高音1-5 的定时器重装载低位 (TL0)
code uchar FREQL[] = { 
    0xC1, 0xC1, 0x7D, 0xB6, 0xD0, 0xD1, 0xB6,  
    0x21, 0xE1, 0x8C, 0xD8, 0x68, 0xE9, 0x5B,  
    0x8F, 0xEE, 0x44, 0x6B, 0xB4, 0xF4        
}; 

/**
 * 乐谱数据：米津玄师 - 《Lemon》
 * 数据组织格式：音符(1-7), 音域(0=低, 1=中, 2=高), 节拍(1=1/4拍, 2=1/2拍, 4=整拍)
 */
code uchar music[] = { 
    // 前奏部分: 2321(低6)13521 
    2,1,1,  3,1,1,  2,1,1,  1,1,1,  6,0,1,  
    1,1,2,  3,1,1,  5,1,2,  2,1,1,  1,1,2,  
    
    // 重复段落
    2,1,1,  3,1,1,  2,1,1,  1,1,1,  6,0,1,  
    1,1,2,  3,1,1,  5,1,2,  2,1,1,  1,1,2,  
    
    // 过渡段: 2321(低6)135655(高1)75352 
    2,1,1,  3,1,1,  2,1,1,  1,1,1,  6,0,1,  
    1,1,2,  3,1,1,  5,1,2,  6,1,1,  5,1,2,  
    5,1,1,  1,2,2,  7,1,1,  5,1,2,  3,1,1,  
    5,1,2,  2,1,4,  
    
    // 重复段落
    2,1,1,  3,1,1,  2,1,1,  1,1,1,  6,0,1,  
    1,1,2,  3,1,1,  5,1,2,  2,1,1,  1,1,2,  
    
    // 23432(低7)1 
    2,1,1,  3,1,1,  4,1,1,  3,1,2,  2,1,1,  
    7,0,2,  1,1,4,  
    
    // 1(低7)(低6)(低7)121(低5)(低3)(低5)(低6)2(低7)11 
    1,1,1,  7,0,1,  6,0,1,  7,0,2,  1,1,2,  
    2,1,2,  1,1,2,  5,0,2,  3,0,2,  5,0,2,  
    6,0,2,  2,1,2,  7,0,2,  1,1,2,  1,1,4,  
    
    0,0,0  // 乐谱结束标志
}; 

/* 全局变量：定时器计数值及基准速度 */
uchar timer0h, timer0l; 
uint base_duration = 160;  // 基准节拍延时(ms) 

/**
 * 软件延时函数
 */
void delay(uint ms) { 
    uint i, j; 
    for(i=0; i<ms; i++) 
        for(j=0; j<120; j++); 
} 

/**
 * 定时器0初始化
 * 模式：16位定时模式
 */
void init_timer() { 
    TMOD = 0x01;  // 设置定时器0为模式1 (16位)
    EA = 1;       // 开启总中断 
    ET0 = 1;      // 开启定时器0中断 
} 

/**
 * 播放指定音符
 * @param note 音符序号(1-7)
 * @param octave 音域选择
 * @param duration_type 节拍长度
 */
void play_note(uchar note, uchar octave, uchar duration_type) { 
    uchar index; 
    uint duration; 
    
    duration = base_duration * duration_type; 
    
    if(note == 0) { // 处理休止符 
        TR0 = 0; 
        beep = 1; 
        delay(duration); 
        return; 
    } 
    
    // 计算频率表索引并加载计数值 
    index = (note-1) + (octave*7);  
    timer0h = FREQH[index]; 
    timer0l = FREQL[index]; 
    
    TH0 = timer0h; 
    TL0 = timer0l; 
    TR0 = 1;      // 开启定时器，开始发声
    delay(duration); 
    TR0 = 0;      // 停止发声
} 

void main() { 
    uchar i; 
    init_timer(); 
    i = 0; 
    
    while(1) { 
        // 循环解析乐谱数组
        while(music[i] || music[i+1] || music[i+2]) { 
            play_note(music[i], music[i+1], music[i+2]); 
            i += 3; 
        } 
        i = 0;        // 循环播放
        delay(2000);  // 曲终停顿2秒 
    } 
} 

/**
 * 定时器0中断服务程序
 * 翻转IO口状态产生方波信号
 */
void timer0_isr() interrupt 1 { 
    TH0 = timer0h; 
    TL0 = timer0l; 
    beep = ~beep;  // 翻转电平产生声音
}

