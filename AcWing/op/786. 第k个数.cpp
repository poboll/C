/*786. 第k个数
给定一个长度为n的整数数列，以及一个整数k，请用快速选择算法求出数列的第k小的数是多少。
输入格式
第一行包含两个整数 n 和 k。
第二行包含 n 个整数（所有整数均在1~109109范围内），表示整数数列。
输出格式
输出一个整数，表示数列的第k小数。
数据范围
1≤n≤1000001≤n≤100000,
1≤k≤n1≤k≤n
输入样例：
5 3
2 4 1 5 3
输出样例：
3
*/
/*使用快排模板
#include<iostream>
using namespace std;
 
const int N = 100010;
int n, k;
int q[N];
 
void quick_sort(int q[], int l, int r){
  if(l>=r) return;
  int x = q[(l+r)/2], i = l-1, j = r+1;
  while(i<j){
      do i++; while(q[i]<x);
      do j--; while(q[j]>x);
      if (i<j) swap(q[i],q[j]);
  }
  quick_sort(q,l,j);
  quick_sort(q,j+1,r); 
}
int main() {
  scanf("%d %d",&n,&k);
  for(int i=0;i<n;i++) {
    scanf("%d",&q[i]);
  }
  quick_sort(q,0,n-1);
  for(int i=0;i<n;i++)
	{   
		if (i==k-1) {
      printf("%d",q[i]);
    }
	}
	return 0;
}*/
/*1、找到分界点x，q[L],q[(L+R)/2],q[R]
2、左边所有数Left<=x，右边所有数Right>=x
3、递归排序Left，递归排序Right
  1、k<=Sl，递归Left
  2、k>Sl，递归Right，k-Sl
时间复杂度：n+n/2+n/4+...=N(1+1/2+1/4+...)<=2n*/
#include<iostream>
using namespace std;
const int N = 100010;
int n,k;
int q[N];
int quick_sort(int l, int r,int k){//C++全局变量和局部变量重名优先使用局部变量
  if(l >= r) {//区间内
    return q[(l + r)/2];
  }
  int x = q[(l + r)/2], i = l-1, j = r+1;
  while (i < j) {
    while(q[ ++ i] < x);
    while(q[ -- j] > x);
    if(i < j) {
      swap(q[i], q[j]);
    }
  }
  int s1 = j - l + 1;
  if (k <= s1) {
    return quick_sort(l, j, k);
  }
  return quick_sort(j + 1, r, k - s1);//return quick_sort(q,j+1,r,k-(j-l+1));
}
int main(){
  int n,k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i ++) {
    scanf("%d",&q[i]);
  }
  printf("%d",quick_sort(0, n - 1, k));
  return 0;
}
