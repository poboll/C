#include <iostream>
#include <cstring>
using namespace std;
const int N=100010;
int n,tt=0,hh=0,m,idx=0;//头指针尾指针和插入的第几个数 
int e[N],ne[N],q[N];
int d[N],h[N];//存储每个节点距离起点的距离 d[1] = 0
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;//插入操作 
}
void bfs()
{
    q[0]=1;
    memset(d,-1,sizeof(d));
    d[1]=0;
    while(hh<=tt)
    {
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i])//对每一层的节点进行遍历 
        {
            int j=e[i];
            if(d[j]==-1)//如果没有被搜索到 
            {
                d[j]=d[t]+1;//当前节点的根节点的距离加1 
                q[++tt]=j;//插入队列中 
            }
        }
    }
    cout<<d[n]<<endl;
}
int main()
{
    memset(h,-1,sizeof h);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    bfs();
    return 0;
}