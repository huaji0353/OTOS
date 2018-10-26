;kernel.s 内核的汇编函数调用定义
[BITS 32]			; 以32位编译

section .text
	; multiboot 引导规范
	align 4
	dd 0x1BADB002	; multiboot magic域，必须为此值
	dd 0x00			; multiboot flag域, GRUB启动时是否要做一些特殊操作
	dd - (0x1BADB002 + 0x00) ; multiboot checksum域，校验上面两个域是否正确

[GLOBAL start]
[EXTERN kernel_main]				 ; 内核入口函数, EXTERN表明此符号在外部定义

start:									; 由ld指定的函数入口
	call kernel_main					; 调用c内核入口函数
	hlt         						; 终止CPU运行