/*844.走迷宫
给定一个 n×m 的二维整数数组，用来表示一个迷宫，数组中只包含 0 或 1，其中 0 表示可以走的路，1 表示不可通过的墙壁。
最初，有一个人位于左上角 (1,1) 处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。
请问，该人从左上角移动至右下角 (n,m) 处，至少需要移动多少次。
数据保证 (1,1) 处和 (n,m) 处的数字为 0，且一定至少存在一条通路。
输入格式
第一行包含两个整数 n 和 m。
接下来 n 行，每行包含 m 个整数（0 或 1），表示完整的二维数组迷宫。
输出格式
输出一个整数，表示从左上角移动至右下角的最少移动次数。
数据范围
1≤n,m≤100
输入样例：
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
输出样例：
8*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int ,int > PII;
const int N = 110;
int g[N][N];//地图 
int f[N][N];//距离 
int n, m;
//0是没走过，1走过 
void bfs(int a, int b) {
	//队列判断 
	queue<PII> q;
	q.push({a, b});
	while(!q.empty()) {
		PII start = q.front();
		q.pop();
		//走过之后直接由0变为1 
		g[start.first][start.second] = 1;
	    //四个方向（上下右左） 
		int dx[4] = {0, 1, 0, -1};
		int dy[4] = {-1, 0, 1, 0};
		for(int i = 0; i < 4; i ++) {
			//开始移动 
			int x = start.first + dx[i];
			int y = start.second + dy[i];
			if(g[x][y] == 0){
				g[x][y] = 1;
				f[x][y] = f[start.first][start.second] + 1;
				q.push({x, y});
			}
		}
	}
	cout << f[n][m];
}
int main() { 
    //g数组全部初始化为1，不用判断越界，走不出去了
	memset(g, 1, sizeof(g));
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			cin >> g[i][j];
		}
	}
	bfs(1, 1);
	return 0;
}