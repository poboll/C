#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, M = 10010;
int dist[N]; // 到源点的距离
int backup[N]; // 备份数组防止串联
int n, m, k;
// a 指向 b 权重为 w 的边
struct Edge {
    int a, b, w;
} edges[M];
void bellman_ford() {
    // 初始化距离为无穷大
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; // 源点到源点距离为 0

    for (int i = 0; i < k; i ++) {
		// 备份上一次迭代的结果，防止出现串联（用本次更新的点去更新其他点）
	    memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j ++) {// 遍历所有边
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
			// 比较 1->b 和 1->a->b 的路径长度
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else cout << dist[n] << endl;
}
int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i ++) {
        int a, b, w; 
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    bellman_ford();
    return 0;
}