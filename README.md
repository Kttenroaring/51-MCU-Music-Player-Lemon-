# 🍋 51 MCU Music Player - 《Lemon》 全栈开发项目
## 基于 STC89C52RC 的软硬一体化音乐演奏系统

[简体中文](#cn-项目简介) | [English](#us-introduction)

---

## 🚀 CN 项目简介
本项目不仅是一个嵌入式软件工程，更是一个完整的**硬件产品原型**。从底层 **8051 内核驱动**到 **PCB 电路设计**，实现了米津玄师《Lemon》副歌旋律的精确还原与实物化呈现。

### 🎬 演示与成果 (Results)
* **软件输出**：定时器 T0 驱动无源蜂鸣器输出高保真方波。
* **硬件呈现**：自主设计并打样的专属 PCB 板，具备完善的电源管理与驱动电路。

---

### 🛠️ 全栈职责 (Full-Stack Responsibilities)

#### 1️⃣ 硬件工程 (Hardware Engineering)
* **原理图设计**：基于 Altium Designer 绘制，集成 STC89C52 核心最小系统与低功耗驱动模块。
* **PCB 布局**：双层板设计，优化信号回路，确保高频信号在音频输出时的稳定性。
* **DFM 优化**：导出完整 Gerber 与 BOM 表，具备可量产性。

#### 2️⃣ 嵌入式开发 (Embedded Firmware)
* **精确频率控制**：建立音阶频率映射表（FREQH/L），实现多八度音域切换。
* **中断算法**：利用定时器中断实现非阻塞式的乐谱数据解析。
* **代码优化**：针对 8051 有限的 Flash 空间进行空间压缩，确保系统实时性。

---

### 🧠 技术栈 (Tech Stack)
* **EDA 工具**: Altium Designer (Schematic & PCB Design)
* **IDE**: Keil uVision 5 (C51)
* **核心技术**: 定时器中断模拟 PWM, 频率查表法, PCB 信号完整性优化。

---

## 🌐 US Introduction
A full-stack embedded solution featuring an **STC89C52RC** MCU. This project covers the entire lifecycle from **Circuit Design (PCB)** to **Firmware Development**.

### 🔧 Engineering Highlights
* **Integrated Design**: Includes custom PCB layouts and optimized schematics in the `Hardware/` directory.
* **Firmware Precision**: Real-time melody synthesis using Timer-driven square wave generation.
* **Production Ready**: Optimized for DFM (Design for Manufacturing) standards.
