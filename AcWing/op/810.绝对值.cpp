/*810.绝对值
题目描述
输入一个整数 x，请你编写一个函数，int abs(int x)，输出 x 的绝对值。
输入样例
-3
输出样例
3
*/
#include <iostream>

using namespace std;

int abs(int x)
{
    if (x > 0) return x;
    return -x;
}

int main()
{
    int x;
    cin >> x;
    cout << abs(x) << endl;

    return 0;
}