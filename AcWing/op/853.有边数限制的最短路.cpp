/*853.有边数限制的最短路
给定一个n个点m条边的有向图，图中可能存在重边和自环， 边权可能为负数。
请你求出从1号点到n号点的最多经过k条边的最短距离，如果无法从1号点走到n号点，输出impossible。
注意：图中可能 存在负权回路 。
输入格式
第一行包含三个整数n，m，k。
接下来m行，每行包含三个整数x，y，z，表示存在一条从点x到点y的有向边，边长为z。
输出格式
输出一个整数，表示从1号点到n号点的最多经过k条边的最短距离。
如果不存在满足条件的路径，则输出“impossible”。
数据范围
1≤n, k≤5001≤n, k≤500, 1≤m≤10000,
任意边长的绝对值不超过10000。
输入样例：
3 3 1
1 2 1
2 3 1
1 3 3
输出样例：
3*/
/*尝试能否利用 源点 → a → b 来减少 源点 → b 的距离*/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, M = 1e4 + 10;
struct Edge {
    int a, b, w;
} edge[M];
int dist[N], backup[N];
int n, m, k;
int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // 题目要求不超过k条边
    for (int i = 0; i < k; i ++) {
        // 所有迭代过程中都是依赖上一次的dist
        // 如果不做备份，当前dist值会被其他的边更新过了，导致错误
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j ++)
        {
            int a = edge[j].a, b = edge[j].b, w = edge[j].w;
            // 只用上一次迭代的结果更新当前的距离
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    // 为什么要这么判断呢？
    // 因为可能存在: i号结点 → n号结点的边，边权为-2
    // 但是i号结点本来就不可达，dist[i]是0x3f3f3f3f，dist[n]是0x3f3f3f3f
    // 但是dist[n]可以被dist[i]更新为0x3f3f3f3f - 2，因此不可以用“==”符号
    if (dist[n] > 0x3f3f3f3f / 2)   return -1;
    return dist[n];
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i ++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edge[i] = {a, b, w};
    }
    int t = bellman_ford();
    if (t == -1) puts("impossible");
    else printf("%d\n", t);
    return 0;
}
