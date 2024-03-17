//
// Created by 大妖怪 on 2024/3/17.
//
// P5719【深基4.例3】分类平均
// 题目描述
// 给定 n 和 k，将从 1 到 n 之间的所有正整数可以分为两类：A 类数可以被 k 整除（也就是说是 k 的倍数），而 B 类数不能。请输出这两类数的平均数，精确到小数点后 1 位，用空格隔开。
// 数据保证两类数的个数都不会是 0。
// 输入格式
// 输入两个正整数 n 与 k。
// 输出格式
// 输出一行，两个实数，分别表示 A 类数与 B 类数的平均数。精确到小数点后一位。
// 样例输入1
// 100 16
// 样例输出1
// 56.0 50.1
// 提示
// 数据保证，1 <= n<= 10000，1 <= k <= 100。
#include <stdio.h>
int main() {
    int n, k, cnt1 = 0, cnt2 = 0;// 计数器cnt
    double ans1, ans2, sum1, sum2;// A = ans1, B = ans2， sum和
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++ i) {
        if(i % k == 0) {//除尽k
            sum1 += i;//A总和
            cnt1 ++;//A计数器
        }else {
            sum2 += i;//B总和
            cnt2 ++;//B计数器
        }
    }
    ans1 = sum1 / cnt1;
    ans2 = sum2 /cnt2;
    printf("%.1lf %.1lf", ans1, ans2);
    return 0;
}