//
// Created by 大妖怪 on 2024/4/4.
//
// P1321 单词覆盖还原
// 题目描述
// 一个长度为 l 的字符串中被反复贴有 boy 和 girl 两单词，后贴上的可能覆盖已贴上的单词（没有被覆盖的用句点表示），最终每个单词至少有一个字符没有被覆盖。问贴有几个 boy 几个 girl？
// 输入格式
// 一行被反复贴有 boy 和 girl 两单词的字符串。
// 输出格式
// 两行，两个整数。第一行为 boy 的个数，第二行为 girl 的个数。
// 样例输入1
// ......boyogirlyy......girl.......
// 样例输出1
// 4
// 2
// 提示
// 数据保证，3 <= l <= 255，字符串仅仅包含如下字符：.bgilory。
#include <stdio.h>
#include <string.h>

int main() {
    char str[256];
    scanf("%s", str);
    int len = strlen(str);
    int boy_count = 0, girl_count = 0;

    for (int i = 0; i < len; ++i) {
        if (str[i] == 'b' && str[i + 1] == 'o' && str[i + 2] == 'y') {
            ++boy_count;
            i += 2; // Skip the 'boy' sequence
        } else if (str[i] == 'g' && str[i + 1] == 'i' && str[i + 2] == 'r' && str[i + 3] == 'l') {
            ++girl_count;
            i += 3; // Skip the 'girl' sequence
        }
    }

    printf("%d\n%d\n", boy_count, girl_count);
    return 0;
}
