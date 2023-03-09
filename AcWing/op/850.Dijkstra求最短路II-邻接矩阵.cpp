#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int N = 5500;
typedef pair<int, int> PII; // {距离, 节点编号}
int g[N][N]; // 邻接矩阵
int dist[N], st[N];
int n, m;
int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap; // 小根堆
    heap.push({0, 1}); 
    while (heap.size()) {
        PII t = heap.top();
        heap.pop();
        int ver = t.second; // 距离源点最近的点
        if (st[ver])    continue;
        // 利用 t 更新它的邻点
        st[ver] = true; 
        for (int i = 1; i <= n; i ++) {
            // 比较 1->i 和 1->ver->i
            if (dist[i] > dist[ver] + g[ver][i]) {
                dist[i] = dist[ver] + g[ver][i];
                heap.push({dist[i], i});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f)  return -1;
    else return dist[n];
}
int main() {
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    while (m -- ) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c); // 处理重边
    }
    cout << dijkstra() << endl;
    return 0;
}