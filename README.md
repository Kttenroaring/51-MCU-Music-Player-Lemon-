# STC89C52 Embedded Audio & Hardware Prototype 🎶

一个基于 8051 内核的全栈硬件项目，实现从 PCB 设计到固件开发的完整闭环。
A full-stack hardware project based on 8051 core, realizing a complete closed-loop from PCB design to firmware development.

[简体中文](#-简体中文) | [English](#-english)

---

## 🇨🇳 简体中文

### 📋 项目简介
本项目是一个嵌入式硬件原型系统。通过 **STC89C52RC** 微控制器精确控制定时器频率，驱动无源蜂鸣器实现音频信号的合成与实物化呈现。

### 🛠️ 技术栈
- **EDA 工具**: Altium Designer (原理图与 PCB 设计)
- **IDE**: Keil uVision 5 (C51 固件开发)
- **核心技术**: 定时器中断模拟 PWM, 频率查表法, PCB 信号完整性优化

### 🎬 演示与成果 (Results)
![Lemon Demo](lemon_demo.mp4)

### ✨ 核心特性

#### 1️⃣ 硬件工程 (Hardware Engineering)
- **原理图设计**: 集成 STC89C52 最小系统与低功耗三极管驱动模块。
- **PCB 布局**: 双层板设计，优化信号回路，确保音频输出时的信号稳定性。
- **生产准备**: 导出完整 Gerber 与 BOM 表，符合 **DFM (面向制造的设计)** 规范。

#### 2️⃣ 嵌入式固件 (Embedded Firmware)
- **高精度频率控制**: 建立 16 位定时器重装载值映射表，覆盖多八度音域。
- **非阻塞式调度**: 利用定时器 T0 中断实现乐谱解析，保证系统实时性。
- **代码优化**: 针对 8051 存储空间进行优化，压缩数据结构以减少 Flash 占用。

### 🚀 快速上手
1. **硬件**: 参考 `/Hardware` 目录下的原理图进行焊接或打样。
2. **软件**: 使用 Keil 5 打开 `/Firmware` 文件夹中的工程文件，编译生成 `.hex`。
3. **烧录**: 使用 STC-ISP 工具将固件下载至单片机。

---

## 🇺🇸 English

### 📋 Introduction
This project is an integrated embedded hardware prototype. It utilizes the **STC89C52RC** MCU to precisely control timer frequencies, driving a passive buzzer to achieve real-time melody synthesis.

### 🛠️ Tech Stack
- **EDA Tools**: Altium Designer (Schematic & PCB Design)
- **IDE**: Keil uVision 5 (C51 Firmware Development)
- **Key Tech**: Timer Interrupt PWM Simulation, Frequency Look-up Table, Signal Integrity Optimization.

### ✨ Key Features

#### 1️⃣ Hardware Engineering
- **Schematic Design**: Features an STC89C52 minimal system and a low-power transistor driver module.
- **PCB Layout**: 2-layer board design with optimized signal loops for stable audio output.
- **Production Ready**: Full Gerber and BOM export, following **DFM (Design for Manufacturing)** standards.

#### 2️⃣ Embedded Firmware
- **Precision Frequency Control**: 16-bit timer reload mapping table covering multi-octave ranges.
- **Non-blocking Scheduling**: Real-time melody parsing via Timer T0 interrupt logic.
- **Resource Optimization**: Optimized data structures to minimize Flash footprint on the 8051 architecture.

### 🚀 Quick Start
1. **Hardware**: Refer to the schematics in the `/Hardware` directory for PCB fabrication.
2. **Software**: Open the project in `/Firmware` using Keil 5 and build the `.hex` file.
3. **Flashing**: Use the STC-ISP tool to download the firmware to your microcontroller.

---

## 📄 License
MIT License - see LICENSE file for details

## ⭐ Support
如果这个项目对你有帮助，欢迎点个 Star！
If you find this project helpful, please consider giving it a star!
