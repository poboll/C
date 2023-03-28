/*94.递归实现排列型枚举
把 1∼n 这 n 个整数排成一行后随机打乱顺序，输出所有可能的次序。
输入格式
一个整数 n。
输出格式
按照从小到大的顺序输出所有方案，每行 1 个。
首先，同一行相邻两个数用一个空格隔开。
其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面。
数据范围
1≤n≤9
输入样例：
3
输出样例：
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1*/
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