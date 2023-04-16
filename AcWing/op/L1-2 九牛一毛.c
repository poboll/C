/*L1-2 九牛一毛
这是一道脑筋急转弯题：猪肉一斤 15 元，鸡肉一斤 20 元，那么一毛钱能买多少头牛？
答案是：9 —— 因为“九牛一毛”。
本题就请你按照这个逻辑，计算一下 N 块钱能买多少斤猪肉、多少斤鸡肉、多少头牛。
输入格式：
输入在一行中给出一个不超过 1000 的正整数 N，即以“元”为单位的货币量。
输出格式：
在一行中顺序输出 N 块钱能买多少斤猪肉、多少斤鸡肉、多少头牛。三个数字都只取整数部分，其间以 1 个空格分隔，行首尾不得有多余空格。
输入样例：
18
输出样例：
1 0 1620
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/
#include <stdio.h>
int main() {
    int n, a, b, c;
    scanf("%d", &n);
    a = n / 15;
    b = n / 20;
    c = n * 10 * 9;
    printf("%d %d %d", a, b, c);
    return 0;
}