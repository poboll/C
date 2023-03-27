#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 10;
int n;
int state[N];//0表示还没放数，1~n表示放了哪个数
bool used[N];//true表示用过，false表示还未用过
void dfs(int u) {
    if(u > n) {//边界：i>n时递归结束
        for(int i = 1;i <= n; i ++) printf("%d ", state[i]); //输出空格对应的数字
        puts("");
        return;
    }
    for(int i = 1; i <= n; i ++) {
        if(!used[i])  //判断该数字没被使用过，否则继续查找
        {
            state[u] = i;  //当前位置变为该数字
            used[i] = true; //表示当前数字已使用
            dfs(u + 1);   //选择下一位置的数字
            //重置使用
            state[u] = 0;
            used[i] = false;
        }
    }
}
int main() {
    scanf("%d",&n);
    dfs(1);
    return 0;
}