//超时
#include<iostream>
using namespace std;
const int N = 20;
int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];//row-行
//在算法中，通常纵轴表示x，横轴表示y
void dfs(int x, int y, int s) {//s代表当前皇后的数量，x,y代表坐标
    if(y == n) y = 0, x ++;//即在每一行遍历格子越界时，要转到下一行的第一个格子
    if(x == n) {
        if(s == n) {//说明找到了解，可以输出结果了
            for(int i = 0; i < n; i++)  cout << g[i] << endl;
            cout << endl;
            return;
        }
    }
    //对每一个格子，有放皇后和不放皇后两种选择
    //1.放皇后
    if(!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        g[x][y] = '.';
    }
    //2.不放皇后
    dfs(x, y + 1, s);
}
 
int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i][j] = '.';
    dfs(0, 0, 0);
    return 0;
}