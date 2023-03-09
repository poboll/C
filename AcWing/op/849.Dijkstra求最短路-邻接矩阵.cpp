/*849.Dijkstra求最短路
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为正值。
请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。
输入格式
第一行包含整数 n 和 m。
接下来 m 行每行包含三个整数 x, y, z，表示存在一条从点 x 到点 y 的有向边，边长为 z。
输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。
如果路径不存在，则输出 −1。
数据范围
1≤n≤500, 1≤m≤10^5
图中涉及边长均不超过 10000。
输入样例：
3 3
1 2 2
2 3 1
1 3 4
输出样例：
3*/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 510;
int g[N][N]; // 邻接矩阵（稠密图）
int dist[N]; // 到源点的距离
bool st[N]; // 记录是否已经找到最短路
int n, m; // n 个点, m 条边
int dijkstra() {
    // 距离初始化成无穷大
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; // 1 号点距离为 0
    for (int i = 0; i < n; i ++) {
	    // 在没有确定最短路的点中，距离源点最近的点
        int t = -1;
        for (int j = 1; j <= n; j ++)
            // 当前点未确定最短路 && 当前路不是最短的
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true; // 标记已经确定最短路
        // 使用 t 更新其他点距离
        // 遍历所有 t 可以达到的点 jd
        for (int j = 1; j <= n; j ++)
            // 比较 1--> j 和 1--> t --> j 的距离
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    if (dist[n] == 0x3f3f3f3f)  return -1;
    return dist[n];
}
int main() {
    scanf("%d%d", &n, &m);
    // 默认边长初始化成无穷大
    memset(g, 0x3f, sizeof g);
    while (m --){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        // 处理重边，只需要记录最短的边
        g[a][b] = min(g[a][b], c);
    }
    printf("%d\n", dijkstra());
    return 0;
}