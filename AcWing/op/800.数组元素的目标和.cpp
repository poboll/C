/*800.数组元素的目标和
给定两个升序排序的有序数组A和B，以及一个目标值x。数组下标从0开始。
请你求出满足A[i] + B[j] = x的数对(i, j)。
数据保证有唯一解。
输入格式
第一行包含三个整数n，m，x，分别表示A的长度，B的长度以及目标值x。
第二行包含n个整数，表示数组A。
第三行包含m个整数，表示数组B。
输出格式
共一行，包含两个整数 i 和 j。
数据范围
数组长度不超过100000。
同一数组内元素各不相同。
1≤数组元素≤10^9
输入样例：
4 5 6
1 2 4 7
3 4 6 8 9
输出样例：
1 1
*/
/*基本思想：
a b两数组都是升序，用双指针 i 和 j , i 先指向a数组的第一个元素，j 指向b数组的最后一个元素。因为当 i 向右移动时a[i]变大，所以 j 应当向左移动使得b[j]变小。对于a中的每一个 i ，当a[i] 加b[j] 的和大于目标和x时，j 就向左移动直到不满足a[i] + b[j] > x。可以将时间复杂度从O（n * m）降到 O（n + m）
①i 指针向右遍历a数组
②满足a[i] + b[j] > x时 j –
③a[i] + a[j] = x输出下标值*/
#include <iostream>
using namespace std;
const int N = 100010;
int n, m, x;
int a[N], b[N];
int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    for (int i = 0; i < m; i ++ ) cin >> b[i];
    for (int i = 0, j = m - 1; i < n; i ++ ) {
        while (j >= 0 && a[i] + b[j] > x) j --;//核心步骤
        if (a[i] + b[j] == x) {
            printf("%d %d", i, j);
            break;
        }
    }
    return 0;
}