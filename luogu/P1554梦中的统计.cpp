//
// Created by 大妖怪 on 2024/1/18.
//
//P1554 梦中的统计
//题目描述
//Bessie 的大脑反应灵敏，仿佛真实地看到了她数过的一个又一个数。她开始注意每一个数码（0 ... 9）：每一个数码在计数的过程中出现过多少次？
//给出两个整数 M 和 N，求在序列 [M, M + 1, M + 2, ..., N - 1, N] 中每一个数码出现了多少次。
//输入格式
//第 1 行: 两个用空格分开的整数 M 和 N。
//输出格式
//第 1 行: 十个用空格分开的整数，分别表示数码 0 \ldots 9 在序列中出现的次数。
//样例输入
//129 137
//样例输出
//1 10 2 9 1 1 1 1 0 1
//数据保证，1 <= M <= N <= 2 * 10^9，N-M <= 5 * 10^5。
#include <stdio.h>

int main() {
    // 读取输入的两个整数 M 和 N
    int M, N;
    scanf("%d %d", &M, &N);

    // 初始化一个数组用于统计每个数字出现的次数，下标表示数字
    int digitCount[10] = {0};

    // 遍历序列 [M, M+1, M+2, ..., N-1, N] 中的每个数字
    for (int i = M; i <= N; i++) {
        int number = i;

        // 统计数字出现的次数
        while (number > 0) {
            int digit = number % 10;
            digitCount[digit]++;
            number /= 10;
        }
    }

    // 输出每个数字出现的次数
    for (int i = 0; i < 10; i++) {
        printf("%d ", digitCount[i]);
    }

    return 0;
}
