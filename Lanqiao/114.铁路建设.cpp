#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005, MAXM = 200005;
int n , m, cnt, head[MAXN], dis[MAXN], vis[MAXN];
struct Edge {
    int to, next;
}e[MAXM];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void dfs(int u) {
    vis[u] = 1;
    for(int  i = head[u]; i; i = e[i].next) {
        int v =e[i].to;
        if(!vis[v]) dfs(v);
        dis[u] = max(dis[u], dis[v] + 1);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    for(int i = 1; i <= n; i ++) {
        memset(vis, 0, sizeof(vis));
        dfs(i);
    }
    for(int i = 1; i <= n; i ++) {
        printf("%.2lf", dis[i] * 1.0);
    }
    return 0;
}