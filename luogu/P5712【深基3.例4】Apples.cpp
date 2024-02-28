//
// Created by 大妖怪 on 2024/2/25.
//
// P5712【深基3.例4】Apples
// 题目描述
// 八尾勇喜欢吃苹果。她今天吃掉了 x 个苹果。英语课上学到了 apple 这个词语，想用它来造句。如果她吃了 1 个苹果，就输出 Today, I ate 1 apple.；如果她没有吃，那么就把 1 换成 0；如果她吃了不止一个苹果，别忘了 apple 这个单词后面要加上代表复数的 s。你能帮她完成这个句子吗？
// 输入格式
// 输入一行一个自然数 x，表示吃掉的苹果数。
// 输出格式
// 根据题目要求输出。
// 样例输入1
// 1
// 样例输出1
// Today, I ate 1 apple.
// 样例输入2
// 3
// 样例输出2
// Today, I ate 3 apples.
// 提示
// 对于所有数据，0<= x <= 100。
#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    if (x == 1) {
        cout << "Today, I ate 1 apple." << endl;
    } else {
        cout << "Today, I ate " << x << " apples." << endl;
    }
    return 0;
}