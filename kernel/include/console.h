// 一屏25行
#define LINE_COUNT 25
// 一行80个字符
#define LINE_LENGTH 80

/* 
	VGA文本模式颜色定义表
	https://wiki.osdev.org/Printing_to_Screen
	color = White << 4 | Blue 字蓝色:背景白色
*/
#define Black           0x0
#define Blue            0x1
#define Green           0x2
#define Cyan            0x3
#define Red             0x4
#define Purple          0x5
#define Brown           0x6
#define Gray            0x7
#define Dark_Gray       0x8
#define Light_Blue      0x9
#define Light_Green     0xA
#define Light_Cyan      0xB
#define Light_Red       0xC
#define Light_Purple	0xD
#define Yellow          0xE
#define White           0xF

/* 自定义颜色序列 */
#define color_error				Black << 4 | Red
#define color_warning			Black << 4 | Yellow
#define color_ok				Black << 4 | Green
#define color_standout			Black << 4 | Gray

typedef struct point // 定义一个点的结构体
{
	int x;
	int y;
}point;

typedef struct console_info //定义一种控制台结构类型
{
	point xy; // 当前虚拟光标的坐标
	int color; // 控制台颜色属性
	char *text; // 控制台中的文本
}console_info;

void console_write(char *str, int color);
void console_write_char(char c, int color);
void console_fill(char c);
void console_fuc_test();
void console_scroll();

// 汇编中操作光标的函数
void console_io_movexy(int x, int y);