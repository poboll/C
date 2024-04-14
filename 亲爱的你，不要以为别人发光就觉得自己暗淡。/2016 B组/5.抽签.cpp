// E 抽签
// 题目描述：
// X星球要派出一个5人组成的观察团前往W星。
// 其中：
// A国最多可以派出4人。
// B国最多可以派出2人。
// C国最多可以派出2人。
// …
// 那么最终派往W星的观察团会有多少种国别的不同组合呢？
// 下面的程序解决了这个问题。
// 数组a[] 中既是每个国家可以派出的最多的名额。
// 程序执行结果为：
// DEFFF
// CEFFF
// CDFFF
// CDEFF
// CCFFF
// CCEFF
// CCDFF
// CCDEF
// BEFFF
// BDFFF
// BDEFF
// BCFFF
// BCEFF
// BCDFF
// BCDEF
// …
#include <stdio.h>
#define N 6
#define M 5
#define BUF 1024

void f(int a[], int k, int m, char b[])
{
	int i,j;
	if(k==N)
	{ 
		b[M] = 0;
		if(m==0) printf("%s\n",b);
		return;
	}
	for(i=0; i<=a[k]; i++)
	{
		for(j=0; j<i; j++) 
			b[M-m+j] = k+'A';
		______________________; //填空位置
	}
}
int main()
{
	int a[N] = {4,2,2,1,1,3};
	char b[BUF];
	f(a,0,M,b);
	return 0;
}
// 分析分析：
// 这个题目就由我们dfs的味道了，我们可以通过第一个if那里就可以看到那是一个递归的结构题了，到5的时候我们跳出，然后我们去看其他的逻辑，在哪里已经确定要是一个f（a，k+1，，b），关键就是我们的第三个属性了，这个我们更具上面的那一个for循环可以看到，m表示还需要多少人，这个就直接出来了f(a,k+1,m-j,b);
// 题目代码
f(a, k+1, m-j, b);