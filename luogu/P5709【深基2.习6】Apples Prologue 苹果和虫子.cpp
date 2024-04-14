//
// Created by 大妖怪 on 2024/2/17.
//
//【深基2.习6】Apples Prologue / 苹果和虫子
// 题目描述
// 八尾勇喜欢吃苹果。她现在有 m（1 <= m <= 100）个苹果，吃完一个苹果需要花费 t（0 <= t <= 100）分钟，吃完一个后立刻开始吃下一个。现在时间过去了 s（1 <= s <= 10000）分钟，请问她还有几个完整的苹果？
// 输入格式
// 输入三个非负整数表示 m, t, s。
// 输出格式
// 输出一个整数表示答案。
// 样例输入
// 50 10 200
// 样例输出
// 30
// 提示
// 如果你出现了 RE，不如检查一下被零除？
#include <stdio.h>

int main() {
    int m, t, s;
    scanf("%d %d %d", &m, &t, &s);

    int apples_eaten = s / t; // 计算在s分钟内能吃多少个完整的苹果
    int total_time = apples_eaten * t; // 计算吃完这些苹果所需的总时间

    int remaining_time = s - total_time; // 计算吃完这些苹果后剩余的时间

    if (remaining_time < 0) {
        remaining_time = 0; // 如果剩余时间为负数，说明在规定时间内已经吃完了所有的苹果
    }

    int remaining_apples = m - apples_eaten; // 计算剩余的完整苹果数量

    printf("%d\n", remaining_apples);

    return 0;
}