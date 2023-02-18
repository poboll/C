/*790.数的三次方根
给定一个浮点数 n，求它的三次方根。
输入格式
共一行，包含一个浮点数 n。
输出格式
共一行，包含一个浮点数，表示问题的解。
注意，结果保留 6 位小数。
数据范围
−10000≤n≤10000
输入样例：
1000.00
输出样例：
10.000000
*/
/*思路
浮点数的二分，在0~n间一直二分直到精度<1e-9停止*/
#include <iostream>
using namespace std;
int main() {
    double a;
    cin >> a;
    if(a < 0) {
        cout << '-';
        a = a * (-1);
    }
    double l = 0, r = a;
    while(r - l > 1e-8) {
        double mid = (l + r) / 2;
        if(mid * mid * mid >= a) r = mid;
        else l = mid;
    }
    printf("%lf", l);
    return 0;
}