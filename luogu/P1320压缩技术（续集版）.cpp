//
// Created by 大妖怪 on 2024/2/9.
//
// P1320压缩技术（续集版）
// 题目描述
// 设某汉字由 N * N 的  0 和  1 的点阵图案组成。
// 我们依照以下规则生成压缩码。连续一组数值：从汉字点阵图案的第一行第一个符号开始计算，按书写顺序从左到右，由上至下。第一个数表示连续有几个  0，第二个数表示接下来连续有几个  1，第三个数再接下来连续有几个  0，第四个数接着连续几个  1，以此类推……
// 例如: 以下汉字点阵图案：
// 0001000
// 0001000
// 0001111
// 0001000
// 0001000
// 0001000
// 1111111
// 对应的压缩码是： 7 3 1 6 1 6 4 3 1 6 1 6 1 3 7（第一个数是 N ,其余各位表示交替表示0和1 的个数，压缩码保证 N * N = 交替的各位数之和）
// 输入格式
// 汉字点阵图（点阵符号之间不留空格）。
// 输出格式
// 输出一行，压缩码。
// 样例输入
// 0001000
// 0001000
// 0001111
// 0001000
// 0001000
// 0001000
// 1111111
// 样例输出
// 7 3 1 6 1 6 4 3 1 6 1 6 1 3 7
// 提示
// 数据保证，3 <= N <= 200。