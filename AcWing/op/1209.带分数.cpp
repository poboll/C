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
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=20;
int n;
bool st[N];//判重数组
bool backup[N];//备份 
int ans;//方案数 
bool check(int a,int c)
{

    int b=n*c-a*c;
    if(c==0||a==0||b==0) return false;
    memcpy(backup,st,sizeof st);
    while(b)
    {
        int x=b%10;//个位 
        b/=10;
        if(x==0||backup[x]) return false;//这个数为0或已经出现过 
        backup[x]=true;
    }
    for(int i=1;i<=9;i++)
    {
        if(!backup[i])//1~9没用完全出现 
        return false;
    }
    return true;
}
void dfs_c(int u,int a,int c)
{
    if(u==n) return;//已经用完n个数字
    if(check(a,c)) ans++;
    for(int i=1;i<=9;i++)
    {
        if(!st[i])
        {
            st[i]=true;
            dfs_c(u+1,a,c*10+i);
            st[i]=false;
        }
    }
}
void dfs_a(int u,int a)//u是当前已经用了的数字 
{
    if(a>=n) return;//无解，直接返回 
    dfs_c(u,a,0);//先枚举a再枚举c 
    for(int i=1;i<=9;i++)
    {
        if(!st[i])
        {
            st[i]=true;
            dfs_a(u+1,a*10+i);
            st[i]=false;
        }
    }
}
int main()
{
    scanf("%d",&n);
    dfs_a(0,0);//u是当前已经用了多少数字，一个数也没用，a是0 
    cout<<ans<<endl;
    return 0;
}