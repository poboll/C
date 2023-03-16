/*859.Kruskal算法求最小生成树
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。
求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。
给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。
由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。
输入格式
第一行包含两个整数 n 和 m。
接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为 w 的边。
输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。
数据范围
1≤n≤10^5,
1≤m≤2*10^5,
图中涉及边的边权的绝对值均不超过 1000。
输入样例：
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
输出样例：
6*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int p[N]; // 并查集
int n, m;
struct Edge {
    int a, b, w;
    // 重载 < 符号，方便调用排序函数
    bool operator < (const Edge &W) const {
        return w < W.w;
    }
} edges[N]; 
// 并查集，找祖宗节点
int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}
int kruskal() {
    int cnt = 0; // 全部加入到树的集合中边的数量(可能有多个集合)
    int res = 0; // 最小生成树的边权重之和
    // 按边权从小到大顺序遍历所有边
    for (int i = 0; i < m; i ++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        int pa = find(a), pb = find(b);
        if (pa != pb) {// a b 不在一个集合中
            p[pa] = p[pb]; // 合并 a b 
            res += w; // 计算边权和     
            cnt ++; // 全部集合中的边数量 + 1a
        }
    }
    // 树中有 n 个节点便有 n-1 条边，如果 cnt 不等于 n-1，说明无法生成有 n 个节点的树
    if (cnt < n - 1) return INF; // 无法生成最小生成树
    return res;
}
int main() {
    cin >> n >> m; 
    // 初始化并查集
    for (int i = 0; i < n; i ++) p[i] = i;
    // 建图
    for (int i = 0; i < m; i ++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    // 按照边权升序排序
    sort(edges, edges + m);
    int t = kruskal();
    if (t == INF) puts("impossible");
    else cout << t;
    return 0;
}