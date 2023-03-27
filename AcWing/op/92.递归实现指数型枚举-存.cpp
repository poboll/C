#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 15;
int n;
int st[N];//状态，记录每个位置当前的状态：0表示还没有考虑，1表示选它，2表示不选它
int ways[1 << 15][15], cnt;
void dfs(int u) {
    if(u == n) {
        //记录方案
        for(int i = 1; i <= n; i ++)
            if(st[i] == 1)
                ways[cnt][i] = i;
        cnt ++;
        return;
    }
    st[u] = 2;
    dfs(u + 1);//第一个分支：不选
    st[u] = 0;//恢复现场
    st[u] = 1;
    dfs(u + 1);//第二个分支：选
    st[u] = 0;//恢复现场
}
int main() {
    cin >> n;
    dfs(1);//全局数组 省略
    for(int i = 0; i < cnt; i ++) {
        for(int j = 1; j < n; j ++) printf("%d ", ways[i][j]);
        puts("");//换行
    }
    return 0;
}