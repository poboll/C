#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
int e[M], ne[M], h[N], idx;
int n, m;
int color[N];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
// 对 u 进行染色，并对其邻边进行染色
bool bfs(int u) {
    queue<int> q;
    q.push(u);
    color[u] = 1;
    while (q.size()) {
        int t = q.front();
        q.pop();
        int c = color[t]; // 颜色
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            // 未染色
            if (!color[j]) {
                color[j] = 3 - c;
                q.push(j);
            }
            // 已染色且与 t 颜色相同
            else if (color[j] && color[j] == c)
                return false;
        }
    }
    return true;
}
int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m --) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    bool flag = true;
    for (int i = 1; i <= n; i ++) { 
        if (!color[i]) {
            if (!bfs(i)) {
                flag = false;
                break;
            }
        }
    }
    puts(flag ? "Yes" : "No");
    return 0;
}
