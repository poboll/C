//
// Created by 大妖怪 on 2024/1/28.
//
// P2911[USACO08OCT] Bovine Bones G
// 贝茜喜欢玩棋盘游戏和角色扮演游戏，所以她说服了约翰开车带她去小商店.在那里她买了三个骰子。这三个不同的骰子的面数分别为 s_1,s_2,s_3。
// 对于一个有 S 个面的骰子每个面上的数字是 1,2,3,\ldots,S。每个面（上的数字）出现的概率均等。贝茜希望找出在所有“三个面上的数字的和”中，哪个和的值出现的概率最大。
// 现在给出每个骰子的面数，需要求出哪个所有“三个面上的数字的和”出现得最频繁。如果有很多个和出现的概率相同，那么只需要输出最小的那个。
// 数据范围： 2<= s_1<=q 20，2 <=q s_2<=q 20，2 <=q s_3<=q 40。
// 输入格式
// \* Line 1: Three space-separated integers: S1, S2, and S3
// 输出格式
// \* Line 1: The smallest integer sum that appears most frequently when the dice are rolled in every possible combination.
// 样例输入
// 3 2 3
// 样例输出
// 5
// 提示
// Here are all the possible outcomes.
// 1 1 1 -> 3
// 1 2 1 -> 4
// 2 1 1 -> 4
// 2 2 1 -> 5
// 3 1 1 -> 5
// 3 2 1 -> 6
// 1 1 2 -> 4
// 1 2 2 -> 5
// 2 1 2 -> 5
// 2 2 2 -> 6
// 3 1 2 -> 6
// 3 2 2 -> 7
// 1 1 3 -> 5
// 1 2 3 -> 6
// 2 1 3 -> 6
// 2 2 3 -> 7
// 3 1 3 -> 7
// 3 2 3 -> 8
// Both 5 and 6 appear most frequently (five times each), so 5 is the answer.
// 三个循环遍历所有可能的骰子点数组合，计算每个组合的和，然后统计每个和出现的次数，找出出现次数最多的和中最小的那个。
#include <stdio.h>
#include <stdlib.h>

int main() {
    int s1, s2, s3;
    scanf("%d %d %d", &s1, &s2, &s3);

    // 计算可能的最大和
    int maxSum = s1 + s2 + s3;

    // 记录每个和出现的次数
    // 使用动态内存分配
    int *freq = (int*)calloc(maxSum + 1, sizeof(int));
//    int freq[maxSum + 1] = {0};
//    int freq[maxSum + 1];
//    for(int i = 0; i <= maxSum; ++i) {
//        freq[i] = 0;
//    }

    // 遍历所有可能的组合
    for(int i = 1; i <= s1; ++i) {
        for(int j = 1; j <= s2; ++j) {
            for(int k = 1; k <= s3; ++k) {
                int sum = i + j + k;
                freq[sum]++;
            }
        }
    }

    // 找出出现次数最多的和中最小的那个
    int maxFreq = 0;
    int result = 0;
    for(int i = 1; i <= maxSum; ++i) {
        if(freq[i] > maxFreq) {
            maxFreq = freq[i];
            result = i;
        }
    }

    printf("%d\n", result);

    // 释放动态分配的内存
    free(freq);

    return 0;
}