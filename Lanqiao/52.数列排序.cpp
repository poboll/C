//
// Created by 大妖怪 on 2024/3/17.
//
// P52 数列排序
// 问题描述
// 给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1<=n<=200
// 输入格式
// 第一行为一个整数n。
// 第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。
// 输出格式
// 输出一行，按从小到大的顺序输出排序后的数列。
// 样例输入
// 5
// 8 3 6 4 9
// 样例输出
// 3 4 6 8 9
// 选择排序
#include <stdio.h>
int main() {
    int n, i, j, min ,temp;
    int a[210];
    scanf("%d", &n);
    for(i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n - 1; ++ i) {
        min = i;
        for(j = i + 1; j < n; ++ j) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        if(min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
