/**/
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