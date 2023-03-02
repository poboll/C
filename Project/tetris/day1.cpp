/*******头 文 件*******/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>                                      
#include <conio.h>
#include <time.h>

/*******宏 定 义*******/
#define FrameX 13                   
#define FrameY 3
#define Frame_hight 20                       
#define Frame_width 18

/*******定 义 全 局 变 量*******/ 
int a[80][80]={0}/*存储每个坐标的状态*/,gr=1/*游戏结束标注*/,co[80][80]={0}/*储存对应的颜色*/;                                                 //0 空白, 1 块 2 墙
int speed=200 /*速度*/, score = 0 /*得分*/, highest=0  /*最高得分*/, m=0 /*是否第一个生成的方块*/;
struct Tetris{//声明俄罗斯方块的结构体 
	int x;//中心方块的x轴坐标 
	int y;//中心方块的y轴坐标 
	int flag;//标记方块类型的序号 
	int color;//方块类型的颜色
	int next;//下一个俄罗斯方块类型的序号
};

/*******函 数 声 明*******/ 
void gotoxy(int x, int y);
void DrawGameframe();
void creat_tetris();
///移动光标
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord);
}
///改变打印颜色
int color(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);//更改文字颜色
    return 0;
}
///隐藏光标(调用一次就行了)
void hidden_cursor() {//隐藏光标
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(hOut, &cci);
  cci.bVisible = 0;//赋1为显示，赋0为隐藏
  SetConsoleCursorInfo(hOut, &cci);
}  
///标题
void title() {
	color(11);
	gotoxy(25, 2);
	printf("俄 罗 斯 方 块 by @mdo"); 
	color(3);                             
	gotoxy(18, 4);
	printf("■"); 
	gotoxy(18, 5);
	printf("■■");
	gotoxy(18, 6);
	printf("■");
	
	color(14);//黄色
	gotoxy(26, 5);
	printf("■■"); 
	gotoxy(28, 6);
	printf("■■");
	
	color(10);//绿色
	gotoxy(36, 5);
	printf("■■"); 
	gotoxy(36, 6);
	printf("■■");
	
	color(13);//粉色
	gotoxy(44, 4);
	printf("■"); 
	gotoxy(44, 5);
	printf("■");
	gotoxy(44, 6);
	printf("■");
	gotoxy(44, 7);
	printf("■");
	
	color(12);//亮红色
	gotoxy(54, 5);
	printf("■"); 
	gotoxy(50, 6);
	printf("■■■");
}
void welcome(){//欢迎界面 
	int i, j = 1;
	color(10);
	for(i = 15; i < 60; i ++ ) {
		for(j = 8; j < 18; j ++ ) {
			gotoxy(i, j);
			if(j == 8 || j == 17) printf("=");
			else if(i == 15 || i == 59) printf("||");}}
	gotoxy(23, 11);
	color(11);
	printf("1. 开始游戏");
	gotoxy(23, 15);
	printf("3. 最高记录");
	gotoxy(40, 11);
	printf("2. 游戏说明");
	gotoxy(40, 15);
	printf("4. 退出游戏");
	gotoxy(27, 19);
	color(13);
	printf("请选择: [ ]\b\b");
}
int main() {
	hidden_cursor(); 
	title();
	welcome();
	return 0; 
}