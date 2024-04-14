// F 递增三元组
// 题目描述：
// 给定三个整数数组
// A = [A1, A2, … AN],
// B = [B1, B2, … BN],
// C = [C1, C2, … CN]，
// 请你统计有多少个三元组(i, j, k) 满足：
// 1 <= i, j, k <= N
// Ai < Bj < Ck
// 【输入格式】
// 第一行包含一个整数N。
// 第二行包含N个整数A1, A2, … AN。
// 第三行包含N个整数B1, B2, … BN。
// 第四行包含N个整数C1, C2, … CN。
// 对于30%的数据，1 <= N <= 100
// 对于60%的数据，1 <= N <= 1000
// 对于100%的数据，1 <= N <= 100000 0 <= Ai, Bi, Ci <= 100000
// 【样例输入】
// 3
// 1 1 1
// 2 2 2
// 3 3 3
// 【样例输出】
// 27
// 分析分析：
// 这个题目一眼看下来，感觉怎么样，是不是有那味了，我想着的话，就是我们先排序，直接用#include里面的sort，然后我去遍历我们的第一个数组，看看，在第二个里面有多少个比大的，然后再去和第三个做一次比较，我们也就只要去获取，在比第二个大的时候，第三行的中比第二个大的个数
// 题目代码
#include <iostream>
#include <algorithm> 
using namespace std;
int a[1000],b[1000],c[1000];
//赋值函数 
void fuzhi(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
//输出函数 
void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
}
//寻找函数,找到比他大的那个值的下角标 ，x是我们的标准值 
int findd(int a[],int x,int n) 
{
	int temp=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>x)
		{
			return i;
		}
	} 
	return -1;//表示没有找到 
} 
int main()
{
	int countt=0;//记录总含量 
	int n;
	cin>>n;
	//初始化赋值 
	fuzhi(a,n);
	fuzhi(b,n);
	fuzhi(c,n);
	//调用函数开始排序 
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	//开始寻找我们的里面满足条件的最大值
	for(int i=0;i<n;i++)
	{
		int temp=findd(b,a[i],n);//找到我们当前这个数在第二层的位置，temp就是下角标
		if(temp==-1)
		{
			continue;
		}
		else
		{
			for(int j=temp;j<n;j++)
			{
				int cemp=findd(c,b[j],n);

				if(cemp==-1)
				{
					continue;
				}
				else
				{
					countt=(n-cemp)+countt;//后面有多少种就是一个他的n-下角标 
				}
			} 
		}
	} 
	 cout<<countt; 

}