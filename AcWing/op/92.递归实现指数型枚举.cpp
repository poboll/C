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
}
int main() {
    cin >> n;
    dfs(0);//全局数组 省略
    return 0;
}