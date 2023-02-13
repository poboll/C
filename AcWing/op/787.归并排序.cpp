/*787.归并排序
给定你一个长度为l的整数数列。
请你使用归并排序对这个数列按照从小到大进行排序。
并将排好序的数列按顺序输出。
输入格式
输入共两行，第一行包含整数 l。
第二行包含 l 个整数（所有整数均在1~10^9范围内），表示整个数列。
输出格式
输出共一行，包含l个整数，表示排好序的数列。
数据范围
输入样例：
5
3 1 2 4 5
输出样例：
1 2 3 4 5
*/
/*算法实现
全分解，再排序合并
四步：
    取中位数，分解
    获取两区间起始点，对比合并于一个数组中
    扫尾
    将顺序数组按原数组起始存储至原数组中
*/
#include <iostream>
using namespace std;
// 设置可排序数量范围
const int N = 100010;
int n;
// 存放有序序列的临时数组
int q[N],tmp[N];
void merge_sort(int q[], int l, int r) {
    //边界的终止情况
    if (l >= r) {
        return;
    }
    //第一步：分成子问题
    int mid = l + r >> 1;
    //第二步：递归处理子问题
    merge_sort(q, l ,mid),merge_sort(q, mid+1, r);
    //第三步：合并子问题。设置k为存放有序序列的数组下标；i为待比较序列中第一个子序列的起始下标，j为待比较序列中第二个子序列的起始下标。
    int k = 0, i = l, j = mid + 1;
    while (i < mid && j <= r) {
        if(q[i] <= q[j]) {
            tmp[k ++ ] = q[i ++ ];
        } else {
            tmp[k ++ ] = q[j ++ ];
        }
  }
  // 比较完后，若第一个子序列还有剩余，将剩余的值添加到tmp中；第二个子序列剩余同理。
    while (i <= mid) {
        tmp[k ++ ] = q[i ++ ];
    }
    while (j <= r) {
        tmp[k ++ ] = q[j ++ ];
    }
    // 将有序序列存放至原数组中，相当于完成一轮合并
    for (k = 0, i = l; i <= r; k++, i ++) {
        q[i] = tmp [k];
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++){
        scanf("%d", &q[i]);
    }
    merge_sort(q, 0, n-1);
    for (int i = 0; i < n; i ++) {
        printf("%d ",q[i]);
    }
    return 0;
}