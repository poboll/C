//
// Created by 大妖怪 on 2024/3/25.
//
// P1765 手机
// 题目描述
// 一般的手机的键盘是这样的：
// ![](https:// cdn.luogu.com.cn/upload/image_hosting/yq2orii6.png)
// 要按出英文字母就必须要按数字键多下。例如要按出 $\tt x$ 就得按 $9$ 两下，第一下会出 $\tt w$，而第二下会把 $\tt w$ 变成 $\tt x$。$0$ 键按一下会出一个空格。
// 你的任务是读取若干句只包含英文小写字母和空格的句子，求出要在手机上打出这个句子至少需要按多少下键盘。
// 输入格式
// 一行句子，只包含英文小写字母和空格，且不超过 200 个字符。
// 输出格式
// 一行一个整数，表示按键盘的总次数。
// 样例输入1
// i have a dream
// 样例输出1
// 23
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[201];
    int keyCount = 0;
    fgets(sentence, 201, stdin); // 读取输入的句子

    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            keyCount++; // 空格键按一下
        } else {
            int keyPress = (sentence[i] - 'a') % 3 + 1; // 计算按键次数
            if (sentence[i] == 's' || sentence[i] == 'z') {
                keyPress = 4; // 's'和'z'需要按4次
            }
            keyCount += keyPress;
        }
    }

    printf("%d\n", keyCount);

    return 0;
}