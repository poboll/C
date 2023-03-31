#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#define MAX_GRID 4
#define GRID_WIDTH 100 
#define INTERVAL 15
using namespace std;
 
enum Color {
 
 zero = RGB(205, 193, 180),
 two1 = RGB(238, 228, 218),
 two2 = RGB(237, 224, 200),
 two3 = RGB(242, 177, 121),
 two4 = RGB(245, 149, 99),
 two5 = RGB(246, 124, 95),
 two6 = RGB(246, 94, 59),
 two7 = RGB(242, 177, 121),
 two8 = RGB(237, 204, 97),
 two9 = RGB(255, 0, 128),
 two10 = RGB(145, 0, 72),
 two11 = RGB(242, 17, 158),
 back = RGB(187, 173, 160),
};
 
Color arr[13] = { zero,two1,two2, two3, two4, two5, two6, two7, two8, two9, two10,two11,back };
int num[12] = { 0,2,4,8,16,32,64,128,256,512,1024,2048 };
int map[MAX_GRID][MAX_GRID];
POINT pos[MAX_GRID][MAX_GRID];
bool flag = false;
//游戏初始界面，随机产生2或者4
int twoorfour() {
 if (rand() % 10 == 1) {
  return 4;
 }
 else {
  return 2;
 }
 
}
//随机位置，把数放在数组里面
 
void CreateNumber() {
 
 while (1) {
  int x=rand()%MAX_GRID;
  int y=rand()%MAX_GRID;
  if (map[x][y] == 0) {
 
 
   map[x][y] = twoorfour();
   break;
  }
 }
}
 
void GameInit() {
 //设置随机数种子
 srand(GetTickCount());
 for (int i = 0;i < MAX_GRID;i++)
 {
  for (int k = 0;k < MAX_GRID;k++)
  {
   pos[i][k].x = k * GRID_WIDTH + (k + 1) * INTERVAL;
   pos[i][k].y = i * GRID_WIDTH + (i + 1) * INTERVAL;
  }
 }
 CreateNumber();
 CreateNumber();
 
}
 
 
void GameDraw() {
 
 //计算格子坐标
 for (int i = 0;i < MAX_GRID;i++)
 {
  for (int k = 0;k < MAX_GRID;k++)
  {
   for (int q = 0;q < 12;q++) {
    if (map[i][k] == num[q]) {
     setfillcolor(arr[q]);
     solidrectangle(pos[i][k].x, pos[i][k].y, pos[i][k].x + GRID_WIDTH, pos[i][k].y + GRID_WIDTH);
    
     if (map[i][k] != 0)
     {
      char number[5] = " ";
      settextcolor(RGB(119, 110, 101));
      settextstyle(50, 0, "楷体");
      setbkmode(TRANSPARENT);//背景颜色透明
      sprintf(number, "%d", map[i][k]);
      int tempx = textwidth(number);
      tempx = GRID_WIDTH / 2 - tempx / 2;
      int tempy = textheight(number);
      tempy = GRID_WIDTH / 2 - tempy / 2;//文字居中
      outtextxy(pos[i][k].x+tempx, pos[i][k].y+tempy, number);
     }
    }
   }
     
  }
 }
 
}
 
//键盘操作数字移动
 
void moveup() {
 for (int i = 0;i < MAX_GRID;i++)
 {
  int temp = 0;
  for (int k = 1;k < MAX_GRID;k++) {
   if (map[k][i] != 0) {
 
    if (map[temp][i] == 0) {
     map[temp][i] = map[k][i];
     map[k][i] = 0;
 
    }
    else if (map[temp][i] == map[k][i]) {
     map[temp][i] += map[k][i];
     map[k][i] = 0;
    }
 
    else {
     map[temp + 1][i] = map[k][i];
     if (temp + 1 != k) {
      map[k][i] = 0;
     }
 
    }
    temp++;
    flag = true;
   }
 
  }
 }
 
}
void movedown() {
 
 for (int i = 0;i < MAX_GRID;i++)
 {
  int temp = 3;
  for (int k = MAX_GRID - 2;k >=0;k--) {
   if (map[k][i] != 0) {
 
    if (map[temp][i] == 0) {
     map[temp][i] = map[k][i];
     map[k][i] = 0;
 
    }
    else if (map[temp][i] == map[k][i]) {
     map[temp][i] += map[k][i];
     map[k][i] = 0;
    }
 
    else {
     map[temp - 1][i] = map[k][i];
     if (temp - 1 != k) {
      map[k][i] = 0;
     }
 
    }
    temp--;
    flag = true;
   }
 
  }
 }
 
}
void moveright() {
 for (int i = 0;i < MAX_GRID;i++)
 {
  int temp = 3;
  for (int k = 2;k >=0;k--) {
   if (map[i][k] != 0) {
 
    if (map[i][temp] == 0) {
     map[i][temp] = map[i][k];
     map[i][k] = 0;
 
    }
    else if (map[i][temp] == map[i][k]) {
     map[i][temp] += map[i][k];
     map[i][k] = 0;
    }
 
    else {
     map[i][temp - 1] = map[i][k];
     if (temp - 1 != k) {
      map[i][k] = 0;
     }
 
    }
    temp--;
    flag = true;
   }
 
  }
 }
 
}
 
 
 
void moveleft() {
 for (int i = 0;i < MAX_GRID;i++)
 {
  int temp = 0;
  for (int k = 1;k < MAX_GRID;k++) {
   if (map[i][k] != 0) {
 
    if (map[i][temp] == 0) {
     map[i][temp] = map[i][k];
     map[i][k] = 0;
 
    }
    else if (map[i][temp] == map[i][k]) {
     map[i][temp] += map[i][k];
     map[i][k] = 0;
    }
 
    else {
     map[i][temp+1] = map[i][k];
     if (temp + 1 != k) {
      map[i][k] = 0;
     }
 
    }
    temp++;
    flag = true;
   }
 
  }
 }
 
}
 
 
void gamejudge() {
 if (flag) {
  CreateNumber();
  flag = false;
 }
}
 
void GameControl() {
 
 char key = _getch();
 switch (key) {
 case 'w':
  moveup();
  break;
 case 'a':
  moveleft();
  break;
 case 's':
  movedown();
  break;
 case 'd':
  moveright();
  break;
 
 }
}
 
int main() {
 initgraph(MAX_GRID*GRID_WIDTH+5*INTERVAL,MAX_GRID*GRID_WIDTH + 5 * INTERVAL);
 setbkcolor(RGB(187, 173, 160));
 cleardevice();
 GameInit();
 while (1) {
  GameDraw();
  GameControl();
  gamejudge();
  
 }
 
 getchar();
 return 0;
}