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
  return quick_sort(j + 1, r, k - s1);
}
int main(){
  int n,k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i ++) {
    scanf("%d",&q[i]);
  }
  cout << quick_sort(0, n - 1, k) << endl;
  return 0;
}
