# 51 MCU Music Player - 《Lemon》米津玄師 🍋
# 基于 STC89C52RC 的单片机音乐演奏器

[简体中文](#cn-项目简介) | [English](#us-introduction)

---

## ## CN 项目简介

本项目是基于 **STC89C52RC** 单片机开发的嵌入式音乐播放器。通过对底层定时器寄存器的精确配置，成功还原了米津玄师名曲《Lemon》的旋律。

### 🎬 演奏演示 (Video Demo)

<div align

https://github.com/user-attachments/assets/39c7959e-0a05-45df-8639-a5bf24537deb

="center">
 
  <p><b>实物演示：单片机驱动无源蜂鸣器演奏《Lemon》</b></p>
</div>

### 🛠️ 角色与职责 (Sole Developer)
* **嵌入式编程**：负责定时器 T0 中断驱动开发，实现不同频率方波的输出。
* **数据算法**：建立音阶频率映射表（FREQH/L），并将乐谱转换为 {音符, 八度, 节拍} 数据结构。
* **硬件调优**：针对 89C52RC 的 RAM 与 Flash 空间进行代码优化，确保播放流畅。

### 🧠 技术栈 (Tech Stack)
* **硬件**: STC89C52RC (8051 Architecture)
* **语言**: C语言 (Keil uVision 5)
* **核心技术**: 定时器中断控制 (Timer Interrupt), PWM频率模拟, 查表法算法。

---

## ## US Introduction
An embedded music player implemented on **STC89C52RC** MCU, featuring the song **"Lemon" by Kenshi Yonezu**.

### 🧠 Key Technical Highlights
* **Precision Timing**: Utilizes Timer 0 interrupt to generate precise square waves for each musical note.
* **Octave Control**: Supports Low, Middle, and High octaves by mapping frequencies to timer reload values.
* **Lightweight Design**: Optimized for 8051 memory constraints, providing a stable real-time playback experience.
