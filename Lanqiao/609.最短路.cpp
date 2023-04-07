/*609.最短路
本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。
如下图所示，G 是一个无向图，其中蓝色边的长度是 1、橘色边的长度是 2、绿色边的长度是 3。
图片描述
则从 A 到 S 的最短距离是多少？
运行限制
最大运行时间：1s
最大运行内存: 128M*/
#include <stdio.h>
#include <stdlib.h>
#define  inf 99999999
int e[20][20];
void add(char A1, char A2, int c) {
	int a = A1 - 'A' + 1;
	int b = A2 - 'A' + 1;
	e[a][b] = c;
	e[b][a] = c;
}
int main(void) {
	int i, j, u, v;
	int n = 19;
	int dis[20] = {0};
	int book[20] = { 0 };
	// 初始化图 
	for (i = 1;i <= n;i ++) {
		for (j = 1;j <= n;j ++) {
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = inf;
		}
	}
	// 添加边 
	add('A', 'B', 2);
	add('A', 'C', 1);
	add('A', 'D', 1);
	add('A', 'D', 1);
	add('B', 'J', 2);
	add('B', 'G', 1);
	add('C', 'D', 3);
	add('C', 'F', 3);
	add('C', 'G', 3);
	add('D', 'E', 1);
	add('D', 'G', 2);
	add('D', 'H', 1);
	add('D', 'I', 2);
	add('E', 'H', 1);
	add('E', 'I', 3);
	add('F', 'G', 1);
	add('F', 'J', 1);
	add('G', 'F', 1);
	add('G', 'I', 3);
	add('G', 'K', 2);
	add('H', 'I', 1);
	add('H', 'L', 2);
	add('I', 'M', 3);
	add('J', 'S', 2);
	add('K', 'N', 1);
	add('K', 'L', 3);
	add('K', 'P', 2);
	add('L', 'M', 1);
	add('L', 'R', 1);
	add('M', 'N', 2);
	add('M', 'Q', 1);
	add('M', 'S', 1);
	add('N', 'P', 1);
	add('O', 'P', 1);
	add('O', 'Q', 1);
	add('O', 'R', 3);
	add('R', 'S', 1);
	for (i = 1;i <= n;i ++) {
		dis[i] = e[1][i];
	}
	book[1] = 1;
	// 核心部分
	for (i = 1;i <= n;i ++) {
		int min = inf;
		for (j = 1;j <= n;j ++) {
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		// 松弛
		book[u] = 1;
		for (v = 1;v <= n;v ++) {
			if (dis[v] > dis[u] + e[u][v] && e[u][v] < inf) {
				dis[v] = dis[u] + e[u][v];
			}
		}
	}
	printf("%d", dis[19]);
	return 0;
}
