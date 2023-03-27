#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 15;
int n;
int st[N];//状态，记录每个位置当前的状态：0表示还没有考虑，1表示选它，2表示不选它
void dfs(int u) {
    if(u == n) {
        for(int i = 0; i < n; i ++)
            if(st[i] == 1)
                printf("%d ", i);
        printf("\n");
        return;
    }
    st[u] = 2;
    dfs(u + 1);//第一个分支：不选
    st[u] = 0;//恢复现场
    st[u] = 1;
    dfs(u + 1);//第二个分支：选
    st[u] = 0;
}
int main() {
    cin >> n;
    dfs(1);//全局数组 省略
    return 0;
}