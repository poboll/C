//
// Created by 大妖怪 on 2024/1/26.
//
//P5730【深基5.例10】显示屏
// 题目描述
// 液晶屏上，每个阿拉伯数字都是可以显示成 3*5 的点阵的（其中 `X` 表示亮点，`.` 表示暗点）。现在给出数字位数（不超过 100）和一串数字，要求输出这些数字在显示屏上的效果。数字的显示方式如同样例输出，注意每个数字之间都有一列间隔。
// 输入格式
// 第一行输入一个正整数 n，表示数字的位数。
// 第二行输入一个长度为 n 的自然数。
// 输出格式
// 输出五行，表示显示屏上的数字。
// 样例输入
// 10
// 0123456789
// 样例输出
// XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
// X.X...X...X...X.X.X.X...X.....X.X.X.X.X
// X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
// X.X...X.X.....X...X...X.X.X...X.X.X...X
// XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX
// 提示
// 数据保证，1 \leq n \leq 100。
#include <stdio.h>

// 显示数字的点阵表示
const char digits[10][5][4] = {
        {"XXX", "X.X", "X.X", "X.X", "XXX"},   // 0
        {"..X", "..X", "..X", "..X", "..X"},   // 1
        {"XXX", "..X", "XXX", "X..", "XXX"},   // 2
        {"XXX", "..X", "XXX", "..X", "XXX"},   // 3
        {"X.X", "X.X", "XXX", "..X", "..X"},   // 4
        {"XXX", "X..", "XXX", "..X", "XXX"},   // 5
        {"XXX", "X..", "XXX", "X.X", "XXX"},   // 6
        {"XXX", "..X", "..X", "..X", "..X"},   // 7
        {"XXX", "X.X", "XXX", "X.X", "XXX"},   // 8
        {"XXX", "X.X", "XXX", "..X", "XXX"}    // 9
};

int main() {
    int n;
    scanf("%d", &n);

    char nums[101];
    scanf("%s", nums);

    // 输出每一行
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < n; ++j) {
            // 输出当前数字的第i行
            printf("%s", digits[nums[j] - '0'][i]);

            // 输出数字间的列间隔
            if (j < n - 1) {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}
