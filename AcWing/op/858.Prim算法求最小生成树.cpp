/*858.Prim算法求最小生成树
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。
求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。
给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。
由 V 中的全部 n 个顶点和 E 中n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。
输入格式
第一行包含两个整数 n 和 m。
接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为w 的边。
输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。
数据范围
1≤n≤500
1≤m≤105
图中涉及边的边权的绝对值均不超过 10000
输入样例：
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
输出样例：
6
Prim算法求最小生成树，算法的流程和dijkstra求最短路差不多，时间复杂度O（n^2）
 if(d[t]==0x3f3f3f3f) 点t到集合的距离为无穷大时，直接输出impossible，证明这个图是不连通的。
n次迭代找到不在集合中的距离集合最近的点t，所以prim是加点算法，而kruskal是加边算法、再用把t加到集合中，t来更新其他点到集合的距离。
book[N]  记录集合当中存在哪些点*/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int g[N][N]; // 稠密图
int dist[N]; // 节点到生成树的距离
bool st[N]; // 节点是否在生成树中
int n, m;
// 返回最小生成树中边权之和
int prim() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; // 从 1 号点开始生成
    int res = 0;
    // 每次循环选出一个点加入到生成树中
    for (int i = 0; i < n; i ++) {
        // 找到集合外，距离集合最小的点
        int t = -1;
        for (int j = 1; j <= n; j++) // 遍历所有节点
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        // 当前图是不连通的，不存在生成树
        if (dist[t] == INF) return INF;
        res += dist[t]; // 先更新最小生成树的边权和，防止有自环
        // 更新生成树外的点到生成树的距离
        for (int j = 1; j <= n; j++) 
            // t->j 距离小于原来的距离，则更新
            dist[j] = min(dist[j], g[t][j]);
        st[t] = true; // 标记该点已经在生成树中
    }
    return res;
}
int main() {
    // 各个点之间的距离初始化成无穷
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    while (m -- ){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c); // 无向图，有重边
    }
    int t = prim(); // 求最小生成树
    if (t == INF) puts("impossible");
    else cout << t << endl;
    return 0;
}