// E 快速排序
// 题目描述：
// 以下代码可以从数组a[]中找出第k小的元素。
// 它使用了类似快速排序中的分治算法，期望时间复杂度是O(N)的。
// 请仔细阅读分析源码，填写划线部分缺失的内容。
#include <stdio.h>

int quick_select(int a[], int l, int r, int k) {
	int p = rand() % (r - l + 1) + l;
	int x = a[p];
	{int t = a[p]; a[p] = a[r]; a[r] = t;}
	int i = l, j = r;
	while(i < j) {
		while(i < j && a[i] < x) i++;
		if(i < j) {
			a[j] = a[i];
			j--;
		}
		while(i < j && a[j] > x) j--;
		if(i < j) {
			a[i] = a[j];
			i++;
		}
	}
	a[i] = x;
	p = i;
	if(i - l + 1 == k) return a[i];
	if(i - l + 1 < k) return quick_select(                        ); //填空
	else return quick_select(a, l, i - 1, k);
}
	
int main()
{
	int a[] = {1, 4, 2, 8, 5, 7, 23, 58, 16, 27, 55, 13, 26, 24, 12};
	printf("%d\n", quick_select(a, 0, 14, 5));
	return 0;
}
// 分析分析：
// 这个题目怎么说，不就是我们的老朋友快速排序吗！！！
// 就是分组比大小的题目，我们就算不会，但是也可以通过后面的代码去推断出来
// 后面的代码是
// quick_select(a, l, i - 1, k);
// 虽然说没有明说，但是我们要知道这个不就是
// i - l + 1 > k的情况吗
// 然后就可以直接开始推断了
// 看到没我们的话是一个i-1，也就是他右边的减少
// 那么我们要填的这个就肯定是一个+1，让他的左边往右边移动，后面就是我们对于k的一个调整
// 第K大的值在数组的第K位，在这个位置的左边的都比它小，右边的都比它大，但整个数组不一定是有序的。
// 结果：
a, i+1, r, k-(i-l+1)