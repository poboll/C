#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+10;
int a[N],sum[N];
int main()
{
    ios::sync_with_stdio(false);//提高cin读取速度，不能使用scanf
    int n,m,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        sum[i]=x+sum[i-1];
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
    return 0;
}