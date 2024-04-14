/*860.染色法判定二分图
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环。
请你判断这个图是否是二分图。
输入格式
第一行包含两个整数 n 和 m。
接下来 m 行，每行包含两个整数 u 和 v，表示点 u 和点 v 之间存在一条边。
输出格式
如果给定图是二分图，则输出 Yes，否则输出 No。
数据范围
1≤n, m≤10^5
输入样例：
4 4
1 3
1 4
2 3
2 4
输出样例：
Yes*/
#include <iostream>
#include <cstring>
using namespace std;
// 由于是无向图，顶点数最大是 N，那么边数最大是顶点数的 2 倍
const int N = 1e5 + 10, M = N + N;
int h[N], e[M], ne[M], idx;
// 记录节点被染成哪种颜色, 0 表示未染色, 1, 2 是两种不同的颜色
int color[N];
int n, m;
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
// 深度优先遍历对 u 及其邻点进行染色，并返回是否能够完成染色操作
bool dfs(int u, int c) {
    color[u] = c; // 对 u 染色
    // 遍历 u 所有邻点并染色
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        // 邻点没有颜色，则递归处理这个邻点(1 染成 2，2 染成 1)
        if (!color[j] && !dfs(j, 3 - c))
            return false;
        // 已经染色，且颜色不是 3 - c，则冲突
        else if (color[j] && color[j] != 3 - c)
            return false;   
    }
    return true;
}
int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    // 读入边
    for (int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a); // 无向图
    } 
    for (int i = 1; i <= n; i ++) // 遍历所有点
        if (!color[i]) {// 没有染色
            if (!dfs(i, 1)) {// 染色该点，并递归处理和它相邻的点
                puts("No");
                return 0;
            }
        }
    puts("Yes");
    return 0;
}