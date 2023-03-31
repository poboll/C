/*1209.带分数
100 可以表示为带分数的形式：100=3+69258 / 714
还可以表示为：100=82+3546 / 197
注意特征：带分数中，数字 1∼9 分别出现且只出现一次（不包含 0）。
类似这样的带分数，100 有 11 种表示法。
输入格式
一个正整数。
输出格式
输出输入数字用数码 1∼9 不重复不遗漏地组成带分数表示的全部种数。
数据范围
1≤N<106
输入样例1：
100
输出样例1：
11
输入样例2：
105
1
输出样例2：
6*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;
const int N = 20;
int n;
int used[N];
int way[N];
double a, b, c;
int times;
double cal(int start,int end) {
    double num = 0;
    for (int i = start; i <= end; i++) {
        num = num * 10 + way[i];
    }
    return num;
}
//假如说从1-3都是a，那么a有3个数，分别是345，i=1:3   i=2:3*10+4=34 i=2:34*10+5=345  
void dfs(int u) {
    if (u > 9) {
        for (int i = 1; i <= 7; i++) {
            for (int j = i + 1; j <= 8; j++) {
                a = cal(1,i);
                b = cal(i+1,j); 
                c = cal(j + 1, 9);
//注意这里abc三个数的边界，之前填错了导致有的情况被漏掉了
                if (a*c + b == n*c) {
                    times++;
                }
            }
        }
    }
    for (int i = 1; i <= 9; i++) {
        if (used[i] == 0) {
            way[u] = i;
            used[i] = 1;
            dfs(u + 1);
            way[u] = 0;//恢复现场
            used[i] = 0;
        }
    }
}
int main() {
    cin >> n;
    dfs(1);
    cout<<times;
}