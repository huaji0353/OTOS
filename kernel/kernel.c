/*
	kernel.c 内核主函数定义
	0x100000 内存地址
*/

#include <kernel.h>

int kernel_main(void) // 内核主函数，由汇编头指定入口
{
	console_fuc_test();
}
