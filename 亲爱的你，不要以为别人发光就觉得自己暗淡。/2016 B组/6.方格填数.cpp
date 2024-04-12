#include <stdio.h>
#include <stdlib.h>
int count = 0;
int temp[10], index = 0;
int is_legal(int s[3][4]) {
	// 判断是否满足要求：相邻位置数字不能相邻，两数字的差大于1，去头去尾s[0][0]、s[2][3]置为-2
	// 假设每个位置都有上下左右和对角
	// 在数组中进行比较，不在就没有
	for(int i = 0; i < 3; ++ i) {
		for(int j = 0; j < 4; ++ j) {
			if(j - 1 >= 0) {
				if(abs(s[i][j] - s[i][j-1] == 1)) {
					return 0;
				}
			}
			if(j + 1 <= 4) {
				if(abs(s[i][j] - s[i][j+1] == 1))  {
					return 0;
				}
			}
			if(i + 1 < 3) {
				if(abs(s[i][j] - s[i+1][j] == 1)) {
					return 0;
				}
			}
			if(j - 1 >= 0 && i + 1 <3) {
				if(abs(s[i][j] - s[i-1][j-1]) == 1) {
					return 0;
				}
			}
			if(j + 1 < 4 && i + 1 < 3) {
				if(abs(s[i][j] - s[i+1][j+1]) == 1) {
					return 0;
				}
			}
			if(i - 1 >= 0 && j + 1 < 4) {
				if(abs(s[i][j] - s[i-1][j+1]) == 1)	{
					return 0;
				}
			}
			if(i - 1 >= 0) {
				if(abs(s[i][j] - s[i-1][j]) == 1) {
					return 0;
				}
			}
			if(j - 1 >= 0 && i - 1 >= 0) {
				if(abs(s[i][j] - s[i-1][j-1]) == 1) {
					return 0;
				}
			}
		}
	}
	return 1;
}
void fun(int s[3][4], int a, int b) {
	int i;
	if(a == 2 && b == 3) { // 表示当前已经填满了表格，需要进行判断看是否满足要求
		if(is_legal(s)) {
			count ++;
		}
	}else { // 继续填写
		for(int i = 0; i <= 9; ++ i) {
			int j;
			for(j = 0; j < index; ++ j) { // 填写的数字必须是没有用过的
				if(i == temp[j]) {
					break;
				}
			}
			if(j == index) {
				s[a][b] == 1;
				temp[index ++] = i;
				if(b > 3) { // 当前行还没填完
					fun(s, a + 1);
				}else { // 填完从下一行开始
					if(a < 2) { // 判断当前行是否是最后一行
						fun(s, a + 1, 0);
					}
				}
				index --;
				// 在一次填满结束后，当前位置的数字换位其他可以填写的数字
				// 所以当前使用的数字需要出去
			}
		}
	}
}
int main()
{
	int s[3][4];
	s[0][0] = -2;
	s[2][3] = -2;
	//左上角和右下角没有，为了方便判断把数值设为-2（小于-1大于10均可） 
	fun(s, 0, 1);
	printf("%d\n", count);
	return 0;
}
