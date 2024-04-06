//
// Created by 大妖怪 on 2024/4/2.
//
// P1598 垂直柱状图
// 题目描述
// 写一个程序从输入文件中去读取四行大写字母（全都是大写的，每行不超过 100 个字符），然后用柱状图输出每个字符在输入文件中出现的次数。严格地按照输出样例来安排你的输出格式。
// 输入格式
// 四行字符，由大写字母组成，每行不超过 100 个字符
// 输出格式
// 由若干行组成，前几行由空格和星号组成，最后一行则是由空格和字母组成的。在任何一行末尾不要打印不需要的多余空格。不要打印任何空行。
// 样例输入1
// THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
// THIS IS AN EXAMPLE TO TEST FOR YOUR
// HISTOGRAM PROGRAM.
// HELLO!
// 样例输出1
// *
// *
// *                   *
// *                   *     *   *
// *                   *     *   *
// *       *     *             *     *   *
// *       *     * *     * *   *     * * *
// *       *   * * *     * *   * *   * * * *
// *     * * * * * *     * * * * *   * * * *     * *
// * * * * * * * * * * * * * * * * * * * * * * * * * *
// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
// 提示
// 每行输出后面不允许出现多余的空格。
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 100

int main() {
    char input[4][MAX_CHARS+1]; // 用于存储输入的四行字符
    int count[26] = {0}; // 用于计算每个字母出现的次数

    // 读取四行字符
    for (int i = 0; i < 4; ++i) {
        fgets(input[i], sizeof(input[i]), stdin);
    }

    // 统计每个字母出现的次数
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < strlen(input[i]); ++j) {
            if (input[i][j] >= 'A' && input[i][j] <= 'Z') {
                count[input[i][j] - 'A']++;
            }
        }
    }

    // 输出柱状图
    int max_count = 0;
    for (int i = 0; i < 26; ++i) {
        if (count[i] > max_count) {
            max_count = count[i];
        }
    }

    for (int i = max_count; i > 0; --i) {
        for (int j = 0; j < 26; ++j) {
            if (count[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // 输出字母
    for (int i = 0; i < 26; ++i) {
        printf("%c ", 'A' + i);
    }
    printf("\n");

    return 0;
}