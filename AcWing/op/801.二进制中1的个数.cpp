/*给定一个长n的数列A，求每个数的二进制表示中1的个数。
输入格式：
第一行包含整数n。第二行包含n个整数，表示整个数列。
输出格式：
共一行，包含n个整数，其中的第i个数表示数列中的第i个数的二进制表示中1的个数。
数据范围：
1 ≤ n ≤ 100000
0 ≤ A [i] ≤ 10^90
可以用lowbit来做*/
#include <iostream>
using namespace std;
int lowbit(int x) {
    return x & -x;
}
int main() {
    int n;
    cin >> n;
    while (n --) {
        int x, cnt = 0;
        cin >> x;
        while (x) {// 直至删到 0 为止 
            x -= lowbit(x); // 进行更新操作在二进制表示中将最后一位 1 至最低位的部分删掉
            cnt ++;
        }
        cout << cnt << ' '; // 输出删除的次数，即二进制表示中 1 的个数
    }
    return 0;
}