#include <console.h>

/* unsigned char *con_video_memstart = (unsigned char*)0xb8000;
	con显存开始地址 查看使用gdb:x/16xb 0xb8000
	旧代码写屏
*/
unsigned short *con_video_memstart = (unsigned short *) 0xb8000;
console_info con_video_struct;

void console_fill(char c)
{
	int i;
	for (i = 0; i < 80*25; i++) {
		con_video_memstart[i] = c | con_video_struct.color << 8;
	}
}

void console_scroll()
{
	int i;
	for (i = 0; i < (LINE_COUNT - 1) * LINE_LENGTH; i++) {
		con_video_memstart[i] = con_video_memstart[i + LINE_LENGTH];
	}
}

void console_write(char *str, int color)
{
	//int j;
	//for (j = 0; str[j]; j++, i++) {
	//	con_video_memstart[i * 2 + 0] = str[j];
	//	con_video_memstart[i * 2 + 1] = color;
	//}
	while(*str)
	{
		console_write_char((char)*str, color);
		++str;
	}
}

void console_write_char(char c, int color)	// 在控制台光标处输出字
{
	if (c == '\n')
	{
		con_video_struct.xy.x = 0;
		++con_video_struct.xy.y;
		return;
	}
	else if (con_video_struct.xy.x >= LINE_LENGTH)
	{
		con_video_struct.xy.x = 0;
		++con_video_struct.xy.y;
	}
	else if (con_video_struct.xy.y >= LINE_COUNT)
	{
		console_scroll();
		--con_video_struct.xy.y;
	}
	else
	{
		++con_video_struct.xy.x;
	}
	con_video_memstart[con_video_struct.xy.y * LINE_LENGTH + con_video_struct.xy.x] = c | color << 8;
	//con_video_memstart[1*80+1] = 'A' | (Red<<4| Green ) << 8;
}

void console_fuc_test()
{
	con_video_struct.color = color_standout;
	char *str = "OSdev Kernel Build 0.0114514\n"; // ん?
	//console_fill('.'); // 用. 清屏
	//console_write_char('A', color_warning);
	//console_write(str,  color_error);
	//console_write(str,  color_warning);
	int i;
	for (i=0;i<25;++i)
	{
		console_write("this is a test\n",  color_ok);
	}
	console_write(" end test",  color_warning);
	//console_write(str,  color_ok);
	//console_write(str,  color_standout);
}