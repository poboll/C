#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 16;
int n;
int st[N];//状态，记录每个位置当前的状态，0，未考虑，1选，2不选  
vector<vector<int>> ways;   //二维数组
void dfs(int u) {//u表示当前我们正在做第几位
    if(u > n) {//边界
        vector<int> way;
        for(int i = 1; i <= n;i ++) //记录方案
            if(st[i] == 1)          //当前位置为1，表示我们选了，输出
                way.push_back(i);       
        ways.push_back(way);    // 把way方案存到ways里面去
        return;
    }
    st[u] = 2; 
    dfs(u + 1); //第一个分支，不选
    st[u] = 0;  //恢复现场
    st[u] = 1;
    dfs(u + 1); //第二个分支，选
    st[u] = 0;
}
int main() {
    cin >> n;
    dfs(1);//st数组是全局的，不用传进去
    for(int i = 0; i < ways.size(); i ++) {
        for(int j = 0; j < ways[i].size(); j ++ )   printf("%d ",ways[i][j]);
        puts("");//输出一个空字符串+换行
    }
    return 0;
}