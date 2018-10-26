CC = gcc -m32 -g # 指定gcc和目标机器 -g为gdb提供符号
LD = ld -m elf_i386 # 指定ld和目标文件格式
AS = nasm -f elf -g # 使用nasm作为汇编器 -g为gdb提供符号
qemu = D:\qemu\qemu-system-i386 -m 16 # qemu启动地址 指定内存大小

CFLAGS = -c -fno-builtin -ffreestanding -nostdlib
# 只编译不链接 不承认内建函数 可独立运行(必须) 无标准库
KERNEL_LDFLAGS = -e start -Ttext-seg=0x100000

# makefile 生成obj的目录
OBJDIR = objs
# 自动遍历kernel目录下的所有.c文件并自动添加目录和.o后缀
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(wildcard *.c))
# 指定内核所需.o文件

all: kernel
# 测试这个简单内核
	${qemu} -kernel kernel.elf
kernel: kernelhead $(OBJS)
# .o文件由ld进行elf_i386格式链接并生成内核文件
	${LD} ${KERNEL_LDFLAGS} ${OBJS} $(OBJDIR)/kernelhead.o -o kernel.elf
$(OBJDIR)/%.o: %.c
# 使用指定gcc的flag去编译本目录下的所有.c文件并把bin作为输出，头文件作为函数定义
	${CC} ${CFLAGS} -Iinclude $< -o $@
kernelhead: kernel.s
	${AS} kernel.s -o $(OBJDIR)/kernelhead.o
gdb: kernel
# 因技术原因debug使用bat脚本
	.\debug.bat
clean:
#清理目录
	rm -f ${OBJS} $(OBJDIR)/kernelhead.o kernel.elf