#include <iostream>
using namespace std;
const int N = 20;
int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];
// 比较原始的 dfs 搜索，每一格都搜，s 表示皇后数量
void dfs(int x, int y, int s) {
    // 换行
    if (y == n) y = 0, x++;
    if (x == n) {
        // 摆好了 n 个皇后
        if (s == n) {
            for (int i = 0; i < n; i ++) puts(g[i]);
            puts("");
        }
        return;
    }
    // 不放皇后
    dfs(x, y + 1, s);
    // 放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        dfs(x, y + 1, s + 1); // 递归下一层
        g[x][y] = '.';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            g[i][j] = '.';
    dfs(0, 0, 0);
    return 0;
}