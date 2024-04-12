// D 快速排序
// 排序在各种场合经常被用到。
// 快速排序是十分常用的高效率的算法。
// 其思想是：先选一个“标尺”，
// 用它把整个队列过一遍筛子，
// 以保证：其左边的元素都不大于它，其右边的元素都不小于它。
// 这样，排序问题就被分割为两个子区间。
// 再分别对子区间排序就可以了。
// 下面的代码是一种实现，请分析并填写划线部分缺少的代码。
// 题目描述
#include <stdio.h>
void swap(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}
int partition(int a[], int p, int r)
{
	int i = p;
	int j = r + 1;
	int x = a[p];
	while(1)
	{
		while(i<r && a[++i]<x);
		while(a[--j]>x);
		if(i>=j) break;
		swap(a,i,j);
	}
	______________________;//填空
	return j;
}
void quicksort(int a[], int p, int r)
{
	if(p<r)
	{
		int q = partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

int main()
{
	int i;
	int a[] = {5,13,6,24,2,8,19,27,6,12,1,17};
	int N = 12;
	quicksort(a, 0, N-1);
	for(i=0; i<N; i++) 
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
// 分析分析：
// 这就是一个快速排序的基本操作了，那一个模块就是对函数是用于切割，表示比当前的数小的放左边，比当前数大的放右边，然后依次对左边和右边进行排序。填空部分就是在分完之后，将当前的数进行交换位置。我们可以直接带数字进去模拟会快很多
// 题目代码
swap(a, p, j);