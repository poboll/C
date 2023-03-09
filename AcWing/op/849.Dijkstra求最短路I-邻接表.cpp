#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
int h[N], w[N], e[N], ne[N], idx; // 邻接表
int dist[N]; // 到源点的距离
bool st[N]; // 是否已经确认最短路
int n, m;
void add (int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i ++) {
        int t = -1;
        // 找到未确定最短路的点中，距离源点最近的点 t
        for (int j = 1; j <= n; j ++)
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        st[t] = true;
        // 使用 t 更新邻点的最短路径
        for (int j = h[t]; j != -1; j = ne[j]) {
            int k = e[j]; // 遍历 t 的邻点
            dist[k] = min(dist[k], dist[t] + w[j]);     
        }
    }
    if (dist[n] == 0x3f3f3f3f)  return -1;
    return dist[n];
}
int main() {
    scanf("%d%d", &n, &m);
    // 默认边长初始化成无穷大
    memset(h, -1, sizeof h);
    while (m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        // 处理重边，只需要记录最短的边
        add(a, b, c);
    }
    printf("%d\n", dijkstra());
    return 0;
}