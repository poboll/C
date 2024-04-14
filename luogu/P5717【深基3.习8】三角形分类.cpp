//
// Created by 大妖怪 on 2024/3/10.
//
// P5717【深基3.习8】三角形分类
// 题目描述
// 给出三条线段 a,b,c 的长度，均是不大于 10000 的正整数。打算把这三条线段拼成一个三角形，它可以是什么三角形呢？
// - 如果三条线段不能组成一个三角形，输出`Not triangle`；
// - 如果是直角三角形，输出`Right triangle`；
// - 如果是锐角三角形，输出`Acute triangle`；
// - 如果是钝角三角形，输出`Obtuse triangle`；
// - 如果是等腰三角形，输出`Isosceles triangle`；
// - 如果是等边三角形，输出`Equilateral triangle`。
// 如果这个三角形符合以上多个条件，请按以上顺序分别输出，并用换行符隔开。
// 输入格式
// 输入 3 个整数 a、b 和 c。
// 输出格式
// 输出若干行判定字符串。
// 样例输入1
// 3 3 3
// 样例输出1
// Acute triangle
// Isosceles triangle
// Equilateral triangle
// 样例输入2
// 3 4 5
// 样例输出2
// Right triangle
// 样例输入3
// 6 10 6
// 样例输出3
// Obtuse triangle
// Isosceles triangle
// 样例输入4
// 1 14 5
// 样例输出4
// Not triangle
// 提示
// 当两短边的平方和大于一长边的平方，说明是锐角三角形。
// 当两短边的平方和等于一长边的平方，说明是直角三角形。
// 当两短边的平方和小于一长边的平方，说明是钝角三角形。
#include <cstdio>
#include <algorithm>
using namespace std;
int a, b, c;
int main() {
    scanf("%d%d%d", &a, &b, &c);
    int d[4] = {0, a, b, c};
    sort(d + 1, d + 4);
    if(d[1] + d[2] <= d[3]) {
        printf("Not triangle\n");
        return 0;
    }
    if(d[1] * d[1] + d[2] == d[3] * d[3])   printf("Right triangle\n");
    else if(d[1] * d[1] + d[2] * d[2] > d[3] * d[3])    printf("Acute triangle\n");
    else if(d[1] * d[1] + d[2] * d[2] < d[3] * d[3])    printf("Obtuse triangle\n");
    if(a == b || b == c || a == c)  printf("Isosceles triangle\n");
    if(a == b && b == c)    printf("Equilateral triangle\n");
    return 0;
}