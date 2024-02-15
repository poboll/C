//
// Created by 大妖怪 on 2024/2/13.
//
// P1575【深基5.例5】旗鼓相当的对手
// 题目描述
// 现有 N 名同学参加了期末考试，并且获得了每名同学的信息：语文、数学、英语成绩（均为不超过 150 的自然数）。如果某对学生 <i, j> 的每一科成绩的分差都不大于 5，且总分分差不大于 10，那么这对学生就是“旗鼓相当的对手”。现在想知道这些同学中，有几对“旗鼓相当的对手”？同样一个人可能会和其他好几名同学结对。
// 输入格式
// 第一行一个正整数 N。
// 接下来 N 行，每行三个整数，其中第 i 行表示第 i 名同学的语文、数学、英语成绩。最先读入的同学编号为 1。
// 输出格式
// 输出一个整数，表示“旗鼓相当的对手”的对数。
// 样例输入
// 3
// 90 90 90
// 85 95 90
// 80 100 91
// 样例输出
// 2
// 提示
// 数据保证，2 \le N\le 1000 且每科成绩为不超过 150 的自然数。
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int scores[N][3];
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &scores[i][0], &scores[i][1], &scores[i][2]);
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int diff1 = abs(scores[i][0] - scores[j][0]);
            int diff2 = abs(scores[i][1] - scores[j][1]);
            int diff3 = abs(scores[i][2] - scores[j][2]);
            int totalDiff = diff1 + diff2 + diff3;

            if (diff1 <= 5 && diff2 <= 5 && diff3 <= 5 && totalDiff <= 10) {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}