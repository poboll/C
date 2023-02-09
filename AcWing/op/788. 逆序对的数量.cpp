/*题目描述
给定一个长度为 n 的整数数列，请你计算数列中的逆序对的数量。
逆序对的定义如下：对于数列的第 i 个和第 j 个元素，如果满足 i<j 且 a[i]>a[j]，则其为一个逆序对；否则不是。
输入格式
第一行包含整数 n，表示数列的长度。
第二行包含 n 个整数，表示整个数列。
输出格式
输出一个整数，表示逆序对的个数
数据范围
1≤n≤100000
数列中的元素的取值范围 [1,]。
输入样例
6
2 3 4 5 6 1
输入样例
5*/
/*解题思路：
假设一个函数merge_sort已经能求出逆序对的数量，若将这组数平分为左右两个部分，则逆序对的数量=左侧数内部逆序对的数量+右侧数内部逆序对的数量+右侧每个数与左侧数组成的逆序对数量的和。
1.把数组分成某个位置分成两个数组
2.对两边递归排序并计算出在同一边逆序对的数量
3.归并数组，并计算不在同一边的逆序对的数量
4.然后遍历看看有没有没归并的数
5.然后赋值给原数组*/
#include<iostream>
using namespace std;
 
const int N = 100010;
 
int n;
int q[N],tem[N];
 
long long merge_sort(int q[],int l,int r){// int 在1e5 时会爆
    if(l >= r) return 0;
    
    int mid = (l + r) >> 1;
    //递归左右两边逆序数对
    long long res = merge_sort(q,l,mid) + merge_sort(q,mid + 1,r);
    
    //归并并计算不在一边的逆序数对
    int k = 0,i = l,j = mid + 1;
    while(i <= mid && j <= r)
        if(q[i] <= q[j]) tem[k++] = q[i++];
        else {
            tem[k++] = q[j++];
            res += mid - i + 1;//计算逆序对数    
            //j的初始值为mid+1，此时当前的q[j]只与(q[k]，i<=k<j)这几个元素存在逆序关系；
            //归并排序从mid 的中间往两侧归并，因此中间元素是相对于当前mid有序的；    
        }
    //扫尾
    while (i <= mid) tem[k++] = q[i++];
    while (j <= r) tem[k++] = q[j++];
    
    //赋给原数组
    for (int i = l,j = 0; i <= r; i ++ ,j++)
        q[i] = tem[j];
        
        return res;
}
 
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);
    printf("%ld",merge_sort(q,0,n - 1));
    
    return 0;
}