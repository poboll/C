//
// Created by 大妖怪 on 2024/2/29.
//
// P5173【深基3.例5】洛谷团队系统
// 题目描述
// 在洛谷上使用团队系统非常方便的添加自己的题目。如果在自己的电脑上配置题目和测试数据，每题需要花费时间 5 分钟；而在洛谷团队中上传私有题目，每题只需要花费 3 分钟，但是上传题目之前还需要一次性花费 11 分钟创建与配置团队。现在要配置 n 道题目，如果本地配置花费的总时间短，请输出 Local，否则输出 Luogu。
// 输入格式
// 输入一个正整数 n，表示需要配置的题目量。
// 输出格式
// 输出一行，一个字符串。如果本地配置花费的总时间短，请输出 Local，否则输出 Luogu。
// 样例输入1
// 2
// 样例输出1
// Local
// 样例输入2
// 50
// 样例输出2
// Luogu
// 提示
// 数据保证 1 \leq n\leq 100。
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    // 本地配置每题 5 分钟，Luogu配置每题 3 分钟 + 团队创建与配置 11 分钟
    int local_time = n * 5;
    int luogu_time = n * 3 + 11;

    // 输出结果
    if (local_time < luogu_time) {
        std::cout << "Local" << std::endl;
    } else {
        std::cout << "Luogu" << std::endl;
    }

    return 0;
}