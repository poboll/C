/*806. 两个数的和
题目描述
输入两个浮点数 x 和 y，请你编写一个函数，double add(double x, double y)，计算并输出 x 与 y 的和。
样例
1.11 2.22
样例输出
3.33
*/
#include <cstdio>
#include <iostream>

using namespace std;

double add(double x, double y)
{
    return x + y;
}

int main()
{
    double x, y;
    cin >> x >> y;
    printf("%.2lf\n", add(x, y));

    return 0;
}
