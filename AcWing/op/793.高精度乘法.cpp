/*793.高精度乘法
给定两个非负整数（不含前导 0） A 和B ，请你计算 A × B 的值。
输入格式
共两行，第一行包含整数 A ，第二行包含整数B 。
输出格式
共一行，包含 A × B 的值。
数据范围
1 ≤ A 的长度 ≤ 100000 , 1≤A的长度≤100000,1≤A的长度≤100000,
0 ≤ B ≤ 10000 0≤B≤100000≤B≤10000
输入样例：
2
3
输出样例：
6*/
/*本题名为高精度乘法，实为高精度整数与普通整数相乘，而并非两个高精度整数相乘，故难度有所降低。
类似于高精度加法，本题从低位至高位将高精度整数每一位乘以普通整数。每次计算得到的结果由几部分相加构成：从低位来的进位、本位相乘结果
得到的结果又分为个位和高位两个部分：个位直接存进结果中，作为乘积结果中对应位的值；高位则继续保留，留至后面的位计算时处理。
如此循环往复，当高精度整数每一位均处理完后，将高精度整数最高位计算的进位一并存入结果中。
最后筛除前导0，得出乘积结果。若理解有困难，自行模拟乘法过程即可。*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> mul(vector<int> a, int b) {
    vector<int> c;
    int num = 0; //用来存放临时计算结果
    for (int i = 0; i < a.size() || num != 0; i ++ )
    {
        if (i < a.size()) num += a[i] * b;
        c.push_back(num % 10);
        num /= 10;
    }
    //筛除前导0
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int main() {
    string A;
    int b;
    cin >> A >> b;
    //用vector存储高精度整数
    vector<int> a, c;
    for (int i = A.size() - 1; i >= 0; i -- ) a.push_back(A[i] - '0');
    //进行乘法过程
    c = mul(a, b);
    //输出乘法结果
    for (int i = c.size() - 1; i >= 0; i -- ) cout << c[i];
    return 0;
}