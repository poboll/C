//
// Created by 大妖怪 on 2024/4/1.
//
// P159 语句解析
// 题目背景
// 木有背景……
// 题目描述
// 一串长度不超过 255 的 PASCAL 语言代码，只有 a,b,c 三个变量，而且只有赋值语句，赋值只能是一个一位的数字或一个变量，每条赋值语句的格式是 `[变量]:=[变量或一位整数];`。未赋值的变量值为 0 输出 a,b,c 的值。
// 输入格式
// 一串符合语法的 PASCAL 语言，只有 a,b,c 三个变量，而且只有赋值语句，赋值只能是一个一位的数字或一个变量，未赋值的变量值为 0。
// 输出格式
// 输出 a,b,c 最终的值。
// 样例输入1
// a:=3;b:=4;c:=5;
// 样例输出1
// 3 4 5
// 提示
// 输入的 PASCAL 语言长度不超过 255。
#include <stdio.h>

int main() {
    // 初始化变量a、b、c为0
    int a = 0, b = 0, c = 0;
    char statement[255]; // 存储输入的赋值语句

    // 读取输入的赋值语句
    fgets(statement, sizeof(statement), stdin);

    // 解析赋值语句
    for (int i = 0; statement[i] != '\0'; i++) {
        if (statement[i] == 'a' || statement[i] == 'b' || statement[i] == 'c') {
            // 找到变量名
            char variable = statement[i];
            i += 2; // 跳过:=

            // 获取赋值
            int value = 0;
            if (statement[i] >= '0' && statement[i] <= '9') {
                // 如果是数字
                value = statement[i] - '0';
            } else if (statement[i] == 'a' || statement[i] == 'b' || statement[i] == 'c') {
                // 如果是变量
                switch (statement[i]) {
                    case 'a':
                        value = a;
                        break;
                    case 'b':
                        value = b;
                        break;
                    case 'c':
                        value = c;
                        break;
                }
            }

            // 赋值
            switch (variable) {
                case 'a':
                    a = value;
                    break;
                case 'b':
                    b = value;
                    break;
                case 'c':
                    c = value;
                    break;
            }
        }
    }

    // 输出结果
    printf("%d %d %d\n", a, b, c);

    return 0;
}