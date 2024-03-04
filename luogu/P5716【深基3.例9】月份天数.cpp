//
// Created by 大妖怪 on 2024/3/3.
//
// P5716【深基3.例9】月份天数
// 题目描述
// 输入年份和月份，输出这一年的这一月有多少天。需要考虑闰年。
// 输入格式
// 输入两个正整数，分别表示年份 y 和月数 m，以空格隔开。
// 输出格式
// 输出一行一个正整数，表示这个月有多少天。
// 样例输入1
// 1926 8
// 样例输出1
// 31
// 样例输入2
// 2000 2
// 样例输出2
// 29
// 提示
// 数据保证 1583 <= y <= 2020，1 <= m <= 12。
#include <iostream>

int main() {
    // 输入年份和月份
    int year, month;
    std::cin >> year >> month;

    // 判断闰年
    bool isLeapYear = false;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        isLeapYear = true;
    }

    // 计算月份天数
    int daysInMonth;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            daysInMonth = isLeapYear ? 29 : 28;
            break;
        default:
            std::cerr << "Invalid month\n";
            return 1;
    }

    // 输出结果
    std::cout << daysInMonth << std::endl;

    return 0;
}