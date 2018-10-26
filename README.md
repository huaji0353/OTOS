# 项目简介

尝试从头开始编写一个玩具操作系统，偏简单化设计与编写，力求最简达成目标.

## 项目进度

### 已完成:
+ multiboot
+ grub引导
+ DMA写convideo
+ 协同式多任务
+ 键盘io
+ 内核debuger调试器

### 计划中:
+ 抢占式多任务
+ 分页
+ 用户空间(elf/pe)
+ 进程调度
+ 多进程/多线程

### 后期计划:
+ 页缓冲区设计(page cache)
+ 驱动程序(ACPI,,PS2 Mouse & Keyboard,CMOS,USB,SATA,EVGA...)
+ 文件系统(ext2,fat16/32)
+ 实现自己的libcrt并移植newlib及其少数软件
+ Shell
+ GUIshell
+ etc....

### 内核功能
#### Boot
#### Kernel
#### FileSystem 
#### Drivers

## 编译要求

### 你需要完整的配置好以下套件包
+ nasm
+ gcc-cross(gcc,ld)
+ binutils(objcopy,)
+ qemu

## 如何开始

配置好编译环境后，你可以尝试使用以下指令编译运行本项目:

	git clone https://github.com/huaji0353/osdev.git
	cd osdev/kernel
	make

## reference

[helloworld!](https://www.zhihu.com/question/49580321/answer/117038530 "参考链接")

[c+asm混编](http://www.cnblogs.com/helloweworld/p/4847662.html "参考链接")

[c与asm互相调用](https://www.jianshu.com/p/6d12a7689d3d "参考链接")

[多任务入门](https://www.jianshu.com/p/56a68185c1f7 "参考链接")
