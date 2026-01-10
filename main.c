#include <reg52.h> 
#define uchar unsigned char 
#define uint unsigned int 
 
sbit beep = P3^6;  // ????? 
 
// ???(?8???8?) 
code uchar FREQH[] = { 
		0xF3, 0xF3, 0xF1, 0xF5, 0xF6, 0xF7, 0xF8,  // ??????1-7(?6,?7,?5)
    0xF9, 0xF9, 0xFA, 0xFA, 0xFB, 0xFB, 0xFC,  // ??1-7 
    0xFC, 0xFD, 0xFD, 0xFD, 0xFD, 0xFE        // ??1-5 
}; 
 
code uchar FREQL[] = { 
    0xC1, 0xC1, 0x7D, 0xB6, 0xD0, 0xD1, 0xB6,  // ??????1-7
    0x21, 0xE1, 0x8C, 0xD8, 0x68, 0xE9, 0x5B,  // ??1-7 
    0x8F, 0xEE, 0x44, 0x6B, 0xB4, 0xF4        // ??1-5 
}; 
 
// ??????:??(1-7), ??(0=??,1=??,2=??), ??(1=??,2=??,4=?) 
code uchar music[] = { 
    // ??? 2321?613521 
    2,1,1,  3,1,1,  2,1,1,  1,1,1,  6,0,1,  // 2321?6(??) 
    1,1,2,  3,1,1,  5,1,2,  2,1,1,  1,1,2,  // 13521 
    
    // ??? (????) 
    2,1,1,  3,1,1,  2,1,1,  1,1,1,  6,0,1, 
    1,1,2,  3,1,1,  5,1,2,  2,1,1,  1,1,2, 
    
    // ??? 2321?6135655?175352 
    2,1,1,  3,1,1,  2,1,1,  1,1,1,  6,0,1,  // 2321?6(??) 
    1,1,2,  3,1,1,  5,1,2,  6,1,1,  5,1,2,  // 13565 
    5,1,1,  1,2,2,  7,1,1,  5,1,2,  3,1,1,  // 5?1753 
    5,1,2,  2,1,4,  // 52 
    
    // ??? (????) 
    2,1,1,  3,1,1,  2,1,1,  1,1,1,  6,0,1, 
    1,1,2,  3,1,1,  5,1,2,  2,1,1,  1,1,2, 
    
    // ??? 23432?71 
    2,1,1,  3,1,1,  4,1,1,  3,1,2,  2,1,1,  // 23432 
    7,0,2,  1,1,4,  // ?71 
    
    // ??? 1?7?6?7121?5?3?5?62?711 
    1,1,1,  7,0,1,  6,0,1,  7,0,2,  1,1,2,  // 1?7?6?71 
    2,1,2,  1,1,2,  5,0,2,  3,0,2,  5,0,2,  // 21?5?3?5 
    6,0,2,  2,1,2,  7,0,2,  1,1,2,  1,1,4,  // ?62?711 
    
    // ???? 
    0,0,0  
}; 
 
uchar timer0h, timer0l; 
uint base_duration = 160;  // ??????(ms) 
 
// ???? 
void delay(uint ms) { 
    uint i,j; 
    for(i=0;i<ms;i++) 
        for(j=0;j<120;j++); 
} 
 
// ?????? 
void init_timer() { 
    TMOD = 0x01;  // ???0??1 
    EA = 1;       // ???? 
    ET0 = 1;      // ????0?? 
} 
 
// ?????? 
void play_note(uchar note, uchar octave, uchar duration_type) { 
    uchar index; 
    uint duration; 
    
    duration = base_duration * duration_type; 
    
    if(note == 0) { // ??? 
        TR0 = 0; 
        beep = 1; 
        delay(duration); 
        return; 
    } 
    
    index = (note-1) + (octave*7);  // ?????? 
    timer0h = FREQH[index]; 
    timer0l = FREQL[index]; 
    
    TH0 = timer0h; 
    TL0 = timer0l; 
    TR0 = 1; 
    delay(duration); 
    TR0 = 0; 
} 
 
// ??? 
void main() { 
    uchar i; 
    init_timer(); 
    i = 0; 
    
    while(1) { 
        while(music[i] || music[i+1] || music[i+2]) { 
            play_note(music[i], music[i+1], music[i+2]); 
            i += 3; 
        } 
        i = 0; 
        delay(2000); // ????? 
    } 
} 
 
// ????????? 
void timer0_isr() interrupt 1 { 
    TH0 = timer0h; 
    TL0 = timer0l; 
    beep = ~beep; 
} 