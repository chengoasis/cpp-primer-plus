# 《C++ Primer Plus》学习笔记与代码实现

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://en.cppreference.com/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Linux-Ubuntu.svg)](https://ubuntu.com/)

## 📖 项目简介

本项目是我系统学习 **《C++ Primer Plus》（第6版）** 的代码仓库，包含：
- 📝 书中所有代码清单的实现
- ✏️ 每章课后习题的解答
- 📚 个人学习笔记与总结

## 🖥️ 开发环境

| 项目     | 版本                |
| -------- | ------------------- |
| 操作系统 | Ubuntu 22.04        |
| 编译器   | g++ 12.3.0          |
| C++ 标准 | C++17 / C++20       |
| 构建工具 | Make / 命令行       |
| 硬件     | NVIDIA RTX 6000 × 2 |

## 📂 目录结构

```tex
cpp-primer-plus/
├── chapter02/         # 第2章：开始学习C++
│   ├── 2.1_hello.cpp      # 代码清单 2.1
│   ├── exercise_1.cpp     # 课后习题 1
│   └── README.md          # 本章笔记（可选）
├── chapter03/         # 第3章：处理数据
├── chapter04/         # 第4章：复合类型
├── ...
└── chapter18/         # 第18章：探讨C++新标准
```

## 🚀 快速开始

### 编译并运行单个程序

```bash
cd chapter02
g++ -std=c++17 -o hello 2.1_hello.cpp
./hello
```

### 批量编译本章所有程序（使用 Make）

```bash
cd chapter02
make          # 编译所有 .cpp 文件
make clean    # 清理可执行文件
```