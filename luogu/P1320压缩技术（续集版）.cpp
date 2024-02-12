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
#include <stdio.h>

void compressMatrix(int matrix[200][200], int n) {
    int compressedCode[400];  // 假设N最大为200，那么压缩码的长度最大为400
    int codeIndex = 0;

    compressedCode[codeIndex++] = n;  // 第一个数是 N

    for (int i = 0; i < n; i++) {
        int count = 0;
        int currentDigit = matrix[i][0];

        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == currentDigit) {
                count++;
            } else {
                compressedCode[codeIndex++] = count;
                count = 1;
                currentDigit = matrix[i][j];
            }
        }

        compressedCode[codeIndex++] = count;
    }

    // 输出结果
    for (int i = 0; i < codeIndex; i++) {
        printf("%d", compressedCode[i]);
        if (i < codeIndex - 1) {
            printf(" ");
        }
    }
}

int main() {
    int matrix[200][200];
    int n;

    // 读取输入数据
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &matrix[i][j]);
        }
    }

    // 获取压缩码
    compressMatrix(matrix, n);

    return 0;
}
