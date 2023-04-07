/*
  项目名称：2048
  开发工具：Visual Studio 2019，EasyX 20190415(beta)
  作者：洛枫
 */

#include <easyx.h>
#include <string.h>
#include <map>
#include <sstream>
#include <time.h>
#include <conio.h>

#pragma comment( lib, "MSIMG32.LIB")


// 方块的状态
enum State
{
	EXIST,		// 存在
	DESTORY		// 销毁
};


// 二维向量，用于表示位置或者大小
struct Vector2
{
	float x;
	float y;
};


// 符号函数
int sgn(float d)
{
	if (d < 0)	return -1;
	if (d > 0)	return  1;
	return 0;
}


class Block
{
private:
	State	currentState;		// 当前的状态
	State	targetState;		// 移动后的状态
	Vector2	size;
	Vector2	currentPos;			// 当前位置
	Vector2	targetPos;			// 目标位置
	IMAGE	*img;
	IMAGE	*newImg;
	float	deltaPos;			// 每秒移动多少位置
	float	deltaSize;			// 每秒变大多少
	float	animationSpeed;		// 动画速度
	
	
public:
	Block(const Vector2 &pos, IMAGE *img)
{
	currentPos = targetPos = pos;
	currentState = targetState = EXIST;
	size = { 50,50 };
	this->img = this->newImg = img;
	
	deltaPos = 100;
	deltaSize = 40;
	animationSpeed = 20.0f;
}
	
	
	void update(float deltaTime)
{
	// 改变方块大小（图片刚生成时的由小到大的动画）
	if (size.x < img->getwidth())
	{
		size.x = size.y = size.x + deltaSize * deltaTime * animationSpeed / 2;
		if (size.x > img->getwidth())
		{
			size.x = size.y = (float)img->getwidth();
		}
	}
	
	// 更新方块位置
	if (currentPos.x != targetPos.x || currentPos.y != targetPos.y)
	{
		int directionX = sgn(targetPos.x - currentPos.x);
		int directionY = sgn(targetPos.y - currentPos.y);
		
		currentPos.x += deltaPos * directionX * deltaTime * animationSpeed;
		// 相距小于 5 视为在同一位置
		if (fabs(currentPos.x - targetPos.x) < 5)
		{
			currentPos.x = targetPos.x;
		}
		
		currentPos.y += deltaPos * directionY * deltaTime * animationSpeed;
		if (fabs(currentPos.y - targetPos.y) < 5)
		{
			currentPos.y = targetPos.y;
		}
	}
	if (currentPos.x == targetPos.x &&currentPos.y == targetPos.y)
	{
		currentState = targetState;
		img = newImg;
	}
}
	
	
	void draw()
{
	TransparentBlt(GetImageHDC(NULL), int(currentPos.x + (90 - size.x) / 2), int(currentPos.y + (90 - size.y) / 2),
		(int)size.x, (int)size.y, GetImageHDC(img), 0, 0, img->getwidth(), img->getheight(), BLACK);
}
	
	
	// 把方块从当前位置移动到目标位置，移动后改变状态
	void MoveTo(const Vector2 &pos, IMAGE *newImg, State state = EXIST)
{
	targetPos = pos;
	targetState = state;
	this->newImg = newImg;
}
	
	
	State getState()
{
	return currentState;
}
};



int		map[4][4];				// 4 * 4 地图
Block	*blockMap[4][4];		// 方块索引
int		score;					// 得分
int		maxScore;				// 最高得分
int		currentMaxBlock;		// 当前最大方块
int		maxBlock;				// 历史最大方块
int		gameLoop;				// 游戏循环
float	keyTime = 0;			// 按键间隔
std::map<int, IMAGE> image;		// 存储所有数字图像
bool	gameOver = false;		// 游戏是否结束
float	overTime;				// 游戏结束后不会立刻退出循环，而是等待 0.5s 更新动画


// 判断是否有可移动的方式，有返回 1 ，没有返回 0
// 检测思路：如果碰到为 0 的格子，或者两个相邻的格子数字相等，则返回 1
int Judge()
{
	// 横向检测
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map[i][j] == 0 || map[i][j] == map[i][j + 1] || map[i][j + 1] == 0)
				return 1;
		}
	}
	
	// 纵向检测
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map[j][i] == 0 || map[j][i] == map[j + 1][i] || map[j + 1][i] == 0)
				return 1;
		}
	}
	
	return 0;
}


// 上移
void Up()
{
	int moveFlag = 0;	// 记录是否进行过移动
	int mergeFlag = 0;	// 记录是否合并过
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int k, z;
			
			// 找到一个不为 0 的方块向上移动，并判断是否可以和下边的方块合并
			for (k = j; k < 4; k++)
				if (map[k][i] != 0)
					break;
			
			// 寻找右边不为 0 的方块
			for (z = k + 1; z < 4; z++)
				if (map[z][i] != 0)
					break;
			
			// 当前行有非 0 方块
			if (k < 4)
			{
				if (z < 4 && map[k][i] == map[z][i])
				{
					// 可以合并
					int value = map[k][i] + map[z][i];
					map[k][i] = map[z][i] = 0;
					map[j][i] = value;
					
					// 开启动画
					Block *temp = blockMap[k][i];
					blockMap[k][i] = NULL;
					blockMap[j][i] = temp;
					blockMap[j][i]->MoveTo({ 25.0f + 100 * i,225.0f + 100 * j }, &image[map[j][i]]);
					blockMap[z][i]->MoveTo({ 25.0f + 100 * i,225.0f + 100 * (j + 1) }, &image[map[z][i]], DESTORY);
					
					// 更新分数
					score += map[j][i];
					if (score > maxScore) maxScore = score;
					
					// 更新方块
					if (value > currentMaxBlock) currentMaxBlock = value;
					if (currentMaxBlock > maxBlock) maxBlock = currentMaxBlock;
					
					mergeFlag = 1;
				}
				else
				{
					// 不可以合并
					int value = map[k][i];
					map[k][i] = 0;
					map[j][i] = value;
					
					// 判断是否可以移动
					if (k != j)
					{
						moveFlag = 1;
						
						// 开启动画
						Block *temp = blockMap[k][i];
						blockMap[k][i] = NULL;
						blockMap[j][i] = temp;
						blockMap[j][i]->MoveTo({ 25.0f + 100 * i,225.0f + 100 * j }, &image[map[j][i]]);
					}
				}
			}
			else		// 判断下一行
			{
				break;
			}
		}
	}
	
	// 如果发生了移动或合并，随机生成一个 2 或 4
	if (moveFlag || mergeFlag)
	{
		int index;	// 随机位置的索引
		
		// 直到随机到一个空位置退出循环
		do
		{
			index = rand() % 4;
		} while (map[3][index] != 0);
		
		// 80% 生成 2 , 20% 生成 4
		int num = rand() % 10;
		if (num < 8)
		{
			map[3][index] = 2;
			blockMap[3][index] = new Block({ 25.0f + 100 * index, 225.0f + 100 * 3 }, &image[2]);
		}
		else
		{
			map[3][index] = 4;
			blockMap[3][index] = new Block({ 25.0f + 100 * index, 225.0f + 100 * 3 }, &image[4]);
		}
	}
}


// 下移
void Down()
{
	int moveFlag = 0;	// 记录是否进行过移动
	int mergeFlag = 0;	// 记录是否合并过
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			int k, z;
			
			// 找到一个不为 0 的方块向下移动，并判断是否可以和上边的方块合并
			for (k = j; k >= 0; k--)
				if (map[k][i] != 0)
					break;
			
			// 寻找右边不为 0 的方块
			for (z = k - 1; z >= 0; z--)
				if (map[z][i] != 0)
					break;
			
			// 当前行有非 0 方块
			if (k >= 0)
			{
				if (z >= 0 && map[k][i] == map[z][i])
				{
					// 可以合并
					int value = map[k][i] + map[z][i];
					map[k][i] = map[z][i] = 0;
					map[j][i] = value;
					
					// 开启动画
					Block *temp = blockMap[k][i];
					blockMap[k][i] = NULL;
					blockMap[j][i] = temp;
					blockMap[j][i]->MoveTo({ 25.0f + 100 * i,225.0f + 100 * j }, &image[map[j][i]]);
					blockMap[z][i]->MoveTo({ 25.0f + 100 * i,225.0f + 100 * (j - 1) }, &image[map[z][i]], DESTORY);
					
					// 更新分数
					score += map[j][i];
					if (score > maxScore) maxScore = score;
					
					// 更新方块
					if (value > currentMaxBlock) currentMaxBlock = value;
					if (currentMaxBlock > maxBlock) maxBlock = currentMaxBlock;
					
					mergeFlag = 1;
				}
				else
				{
					// 不可以合并
					int value = map[k][i];
					map[k][i] = 0;
					map[j][i] = value;
					
					// 判断是否可以移动
					if (k != j)
					{
						moveFlag = 1;
						// 开启动画
						Block *temp = blockMap[k][i];
						blockMap[k][i] = NULL;
						blockMap[j][i] = temp;
						blockMap[j][i]->MoveTo({ 25.0f + 100 * i,225.0f + 100 * j }, &image[map[j][i]]);
					}
				}
			}
			else		// 判断下一行
			{
				break;
			}
		}
	}
	
	// 如果发生了移动或合并，随机生成一个 2 或 4
	if (moveFlag || mergeFlag)
	{
		int index;	// 随机位置的索引
		
		// 直到随机到一个为 0 的位置退出循环
		do
		{
			index = rand() % 4;
		} while (map[0][index] != 0);
		
		// 80% 生成 2 , 20% 生成 4
		int num = rand() % 10;
		if (num < 8)
		{
			map[0][index] = 2;
			blockMap[0][index] = new Block({ 25.0f + 100 * index,225.0f + 100 * 0 }, &image[2]);
		}
		else
		{
			map[0][index] = 4;
			blockMap[0][index] = new Block({ 25.0f + 100 * index,225.0f + 100 * 0 }, &image[4]);
		}
	}
}


// 左移
void Left()
{
	int moveFlag = 0;	// 记录是否进行过移动
	int mergeFlag = 0;	// 记录是否合并过
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int k, z;
			
			// 找到一个不为 0 的方块向左移动，并判断是否可以和右边的方块合并
			for (k = j; k < 4; k++)
				if (map[i][k] != 0)
					break;
			
			// 寻找右边不为 0 的方块
			for (z = k + 1; z < 4; z++)
				if (map[i][z] != 0)
					break;
			
			// 当前行有非 0 方块
			if (k < 4)
			{
				if (z < 4 && map[i][k] == map[i][z])
				{
					// 可以合并
					int value = map[i][k] + map[i][z];
					map[i][k] = map[i][z] = 0;
					map[i][j] = value;
					
					// 开启动画
					Block *temp = blockMap[i][k];
					blockMap[i][k] = NULL;
					blockMap[i][j] = temp;
					blockMap[i][j]->MoveTo({ 25.0f + 100 * j,225.0f + 100 * i }, &image[value]);
					blockMap[i][z]->MoveTo({ 25.0f + 100 * (j + 1),225.0f + 100 * i }, &image[map[z][i]], DESTORY);
					
					// 更新分数
					score += map[i][j];
					if (score > maxScore) maxScore = score;
					
					// 更新方块
					if (value > currentMaxBlock) currentMaxBlock = value;
					if (currentMaxBlock > maxBlock) maxBlock = currentMaxBlock;
					
					mergeFlag = 1;
				}
				else
				{
					// 不可以合并
					int value = map[i][k];
					map[i][k] = 0;
					map[i][j] = value;
					
					// 判断是否可以移动
					if (k != j)
					{
						moveFlag = 1;
						// 开启动画
						Block *temp = blockMap[i][k];
						blockMap[i][k] = NULL;
						blockMap[i][j] = temp;
						blockMap[i][j]->MoveTo({ 25.0f + 100 * j,225.0f + 100 * i }, &image[value]);
					}
				}
			}
			else		// 判断下一行
			{
				break;
			}
		}
	}
	
	// 如果发生了移动或合并，随机生成一个 2 或 4
	if (moveFlag || mergeFlag)
	{
		
		int index;	// 随机位置的索引
		
		// 直到随机到一个为 0 的位置退出循环
		do
		{
			index = rand() % 4;
		} while (map[index][3] != 0);
		
		// 80% 生成 2 , 20% 生成 4
		int num = rand() % 10;
		if (num < 8)
		{
			map[index][3] = 2;
			blockMap[index][3] = new Block({ 25.0f + 100 * 3,225.0f + 100 * index }, &image[2]);
		}
		else
		{
			map[index][3] = 4;
			blockMap[index][3] = new Block({ 25.0f + 100 * 3,225.0f + 100 * index }, &image[4]);
		}
	}
}


// 右移
void Right()
{
	int moveFlag = 0;	// 记录是否进行过移动
	int mergeFlag = 0;	// 记录是否合并过
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			int k, z;
			
			// 找到一个不为 0 的方块向右移动，并判断是否可以和左边的方块合并
			for (k = j; k >= 0; k--)
				if (map[i][k] != 0)
					break;
			
			// 寻找右边不为 0 的方块
			for (z = k - 1; z >= 0; z--)
				if (map[i][z] != 0)
					break;
			
			// 当前行有非 0 方块
			if (k >= 0)
			{
				if (z >= 0 && map[i][k] == map[i][z])
				{
					// 可以合并
					int value = map[i][k] + map[i][z];
					map[i][k] = map[i][z] = 0;
					map[i][j] = value;
					
					// 开启动画
					Block *temp = blockMap[i][k];
					blockMap[i][k] = NULL;
					blockMap[i][j] = temp;
					blockMap[i][j]->MoveTo({ 25.0f + 100 * j,225.0f + 100 * i }, &image[value]);
					blockMap[i][z]->MoveTo({ 25.0f + 100 * (j - 1),225.0f + 100 * i }, &image[map[z][i]], DESTORY);
					
					// 更新分数
					score += map[i][j];
					if (score > maxScore) maxScore = score;
					
					// 更新方块
					if (value > currentMaxBlock) currentMaxBlock = value;
					if (currentMaxBlock > maxBlock) maxBlock = currentMaxBlock;
					
					mergeFlag = 1;
				}
				else
				{
					// 不可以合并
					int value = map[i][k];
					map[i][k] = 0;
					map[i][j] = value;
					
					// 判断是否可以移动
					if (k != j)
					{
						moveFlag = 1;
						// 开启动画
						Block *temp = blockMap[i][k];
						blockMap[i][k] = NULL;
						blockMap[i][j] = temp;
						blockMap[i][j]->MoveTo({ 25.0f + 100 * j,225.0f + 100 * i }, &image[value]);
					}
				}
			}
			else		// 判断下一行
			{
				break;
			}
		}
	}
	
	// 如果发生了移动或合并，随机生成一个 2 或 4
	if (moveFlag || mergeFlag)
	{
		int index;	// 随机位置的索引
		do
		{
			index = rand() % 4;
		} while (map[index][0] != 0);
		
		// 80% 生成 2 , 20% 生成 4
		int num = rand() % 10;
		if (num < 8)
		{
			map[index][0] = 2;
			blockMap[index][0] = new Block({ 25.0f + 100 * 0,225.0f + 100 * index }, &image[2]);
		}
		else
		{
			map[index][0] = 4;
			blockMap[index][0] = new Block({ 25.0f + 100 * 0,225.0f + 100 * index }, &image[4]);
		}
	}
}


void Update(float deltaTime)
{
	// 更新方块
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (blockMap[i][j] != NULL)
			{
				blockMap[i][j]->update(deltaTime);
				if (blockMap[i][j]->getState() == DESTORY)
				{
					delete blockMap[i][j];
					blockMap[i][j] = NULL;
				}
			}
		}
	}
	
	if (gameOver)
	{
		overTime -= deltaTime;
		if (overTime <= 0)
			gameLoop = 0;
	}
	
	keyTime += deltaTime;
	// 0.2s 可以按键一次
	if (keyTime < 0.2f || gameOver)
		return;
	
	if ((GetAsyncKeyState(VK_UP) & 0x8000) || (GetAsyncKeyState('W') & 0x8000))			// 上
	{
		Up();
		if (!Judge())
		{
			gameOver = true;
		}
		keyTime = 0;
	}
	else if ((GetAsyncKeyState(VK_DOWN) & 0x8000) || (GetAsyncKeyState('S') & 0x8000))	// 下
	{
		Down();
		if (!Judge())
		{
			gameOver = true;
		}
		keyTime = 0;
	}
	else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) || (GetAsyncKeyState('A') & 0x8000))	// 左
	{
		Left();
		if (!Judge())
		{
			gameOver = true;
		}
		keyTime = 0;
	}
	else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) || (GetAsyncKeyState('D') & 0x8000))	// 右
	{
		Right();
		if (!Judge())
		{
			gameOver = true;
		}
		keyTime = 0;
	}
}


// 设置文字样式和颜色
void settext(int height, int weight, UINT color)
{
	settextstyle(height, 0, _T("Arial"), 0, 0, weight, false, false, false, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
	settextcolor(color);
}


// 在指定矩形区域内居中输出字符串
void printtext(LPCTSTR s, int left, int top, int right, int width)
{
	RECT r = { left, top, right, width };
	drawtext(s, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}


// 绘制界面
void Draw()
{
	// 历史最大方块
	TransparentBlt(GetImageHDC(NULL), 12, 30, 90, 90, GetImageHDC(&image[maxBlock]), 0, 0, 90, 90, 0x9eaebb);
	
	setfillcolor(0x9eaebb);
	// 绘制当前分数
	solidroundrect(112, 30, 264, 119, 10, 10);
	settext(28, 800, 0xdbe6ee);
	printtext(_T("SCORE"), 112, 40, 264, 69);
	std::wstringstream ss;
	ss << score;
	settext(44, 800, WHITE);
	printtext(ss.str().c_str(), 112, 70, 264, 114);
	ss.str(_T(""));
	
	// 绘制最高分数
	solidroundrect(275, 30, 427, 119, 10, 10);
	settext(28, 800, 0xdbe6ee);
	printtext(_T("BEST"), 275, 40, 427, 69);
	ss << maxScore;
	settext(44, 800, WHITE);
	printtext(ss.str().c_str(), 275, 70, 427, 114);
	ss.str(_T(""));
	
	// 绘制提示信息
	settextcolor(BLACK);
	ss << "Join the numbers and get to the " << currentMaxBlock * 2 << " tile!";
	settext(24, 800, 0x707b83);
	printtext(ss.str().c_str(), 0, 120, 439, 211);
	
	// 绘制方块底板
	solidroundrect(12, 212, 427, 627, 10, 10);
	
	// 绘制方块
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			putimage(25 + 100 * j, 225 + 100 * i, &image[0]);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (blockMap[i][j] != NULL)
				blockMap[i][j]->draw();
		}
	}
}


// 初始化游戏
void Init()
{
	srand((unsigned int)time(NULL));		// 初始化随机数种子
	
	memset(map, 0, 4 * 4 * sizeof(int));	// 把地图初始化为 0
	memset(blockMap, 0, 4 * 4 * sizeof(Block*));
	
	score = 0;
	gameLoop = 1;
	gameOver = false;
	overTime = 0.5f;
	currentMaxBlock = 2;
	map[0][0] = 2;
	map[0][1] = 2;
	blockMap[0][0] = new Block({ 25,225 }, &image[2]);
	blockMap[0][1] = new Block({ 125,225 }, &image[2]);
	
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
}


// 游戏结束界面 返回 1 表示继续游戏 返回 0 表示结束游戏
int OverInterface()
{
	// 保存最高纪录
	std::wstringstream ss;
	ss << maxScore;
	WritePrivateProfileString(_T("2048"), _T("MaxScore"), ss.str().c_str(), _T(".\\data.ini"));
	ss.str(_T(""));
	ss << maxBlock;
	WritePrivateProfileString(_T("2048"), _T("MaxBlock"), ss.str().c_str(), _T(".\\data.ini"));
	
	setbkmode(TRANSPARENT);
	setbkcolor(0x8eecff);
	cleardevice();
	
	// Game Over
	settext(60, 1000, 0x696f78);
	printtext(_T("Game Over!"), 0, 0, 439, 199);
	
	// 绘制最大方块
	TransparentBlt(GetImageHDC(NULL), 175, 150, 90, 90, GetImageHDC(&image[currentMaxBlock]), 0, 0, 90, 90, 0x9eaebb);
	
	// ReStart
	setfillcolor(0x9dadba);
	solidroundrect(120, 310, 319, 389, 10, 10);
	settext(36, 1000, WHITE);
	printtext(_T("ReStart"), 120, 310, 319, 389);
	// Exit
	solidroundrect(120, 460, 319, 539, 10, 10);
	printtext(_T("Exit"), 120, 460, 319, 539);
	
	FlushBatchDraw();
	
	FlushMouseMsgBuffer();
	
	while (1)
	{
		while (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			if (msg.mkLButton)
			{
				int x = msg.x;
				int y = msg.y;
				if (x >= 120 && x <= 319 && y >= 310 && y <= 389)
					return 1;
				if (x >= 120 && x <= 319 && y >= 460 && y <= 539)
					return 0;
			}
		}
		Sleep(100);
	}
	return 1;
}


// 释放内存
void FreeMem()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (blockMap[i][j] != NULL)
				delete blockMap[i][j];
}


// 用于生成方块图片
//		img:		方块图片指针
//		num:		方块上的数字
//		imgColor:	方块颜色
//		fontSize:	字体大小
//		fontColor:	字体颜色	
void CreateImage(IMAGE *img, LPCTSTR num, COLORREF imgColor, int fontSize, COLORREF fontColor)
{
	SetWorkingImage(img);
	setbkmode(TRANSPARENT);
	setbkcolor(0x9eaebb);
	settext(fontSize, 1000, fontColor);
	setfillcolor(imgColor);
	settextcolor(fontColor);
	
	cleardevice();
	
	solidroundrect(0, 0, img->getwidth() - 1, img->getheight() - 1, 10, 10);
	
	RECT r = { 0,0,img->getwidth() - 1,img->getheight() - 1 };
	drawtext(num, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

// 绘制图片缓存
void Load()
{
	IMAGE temp(90, 90);
	
	CreateImage(&temp, _T(""),     0xb5becc, 72, WHITE);		image[0] = temp;
	CreateImage(&temp, _T("2"),    0xdbe6ee, 72, 0x707b83);		image[2] = temp;
	CreateImage(&temp, _T("4"),    0xc7e1ed, 72, 0x707b83);		image[4] = temp;
	CreateImage(&temp, _T("8"),    0x78b2f4, 72, WHITE);		image[8] = temp;
	CreateImage(&temp, _T("16"),   0x538ded, 72, WHITE);		image[16] = temp;
	CreateImage(&temp, _T("32"),   0x607df6, 72, WHITE);		image[32] = temp;
	CreateImage(&temp, _T("64"),   0x3958e9, 72, WHITE);		image[64] = temp;
	CreateImage(&temp, _T("128"),  0x6bd9f5, 56, WHITE);		image[128] = temp;
	CreateImage(&temp, _T("256"),  0x4bd0f2, 56, WHITE);		image[256] = temp;
	CreateImage(&temp, _T("512"),  0x2ac0e4, 56, WHITE);		image[512] = temp;
	CreateImage(&temp, _T("1024"), 0x13b8e3, 40, WHITE);		image[1024] = temp;
	CreateImage(&temp, _T("2048"), 0x00c5eb, 40, WHITE);		image[2048] = temp;
	CreateImage(&temp, _T("4096"), 0x3958e9, 40, WHITE);		image[4096] = temp;
	CreateImage(&temp, _T("8192"), 0x3958e9, 40, WHITE);		image[8192] = temp;
	
	SetWorkingImage(NULL);
}


// 主函数
int main()
{
	float deltaTime = 0;	// 每帧耗时
	
	initgraph(440, 650);
	Load();
	BeginBatchDraw();
	
	maxScore = 0;
	
	// 读取最高分
	maxScore = GetPrivateProfileInt(_T("2048"), _T("MaxScore"), 0, _T(".\\data.ini"));
	// 读取最大方块
	maxBlock = GetPrivateProfileInt(_T("2048"), _T("MaxBlock"), 2, _T(".\\data.ini"));
	
	while (1)
	{
		Init();
		
		while (gameLoop)
		{
			clock_t start = clock();
			
			cleardevice();
			Update(deltaTime);
			Draw();
			FlushBatchDraw();
			Sleep(1);
			
			clock_t end = clock();
			deltaTime = (end - start) / 1000.0f;
		}
		
		FreeMem();
		
		if (OverInterface() == 0)
			break;
		
		FlushMouseMsgBuffer();
	}
	
	closegraph();
}
