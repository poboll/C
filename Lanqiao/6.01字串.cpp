//
// Created by 大妖怪 on 2024/3/19.
//
// P6 01字串
// 问题描述
// 对于长度为5位的一个01串，每一位都可能是0或1，一共有32种可能。它们的前几个是：
// 00000
// 00001
// 00010
// 00011
// 00100
// 请按从小到大的顺序输出这32种01串。
// 输入格式
// 本试题没有输入。
// 输出格式
// 输出32行，按从小到大的顺序每行一个长度为5的01串。
// 样例输出
// 00000
// 00001
// 00010
// 00011
// <以下部分省略>
#include <stdio.h>
int main() {
    int i, j, k, m, n;
    for(i = 0; i < 2; ++ i) {
        for(j = 0; j < 2; ++ j) {
            for(k = 0; k < 2; ++ k) {
                for(m = 0; m < 2; ++ m) {
                    for(n = 0; n < 2; ++ n) {
                        printf("%d%d%d%d%d\n", i, j, k, m, n);
                    }
                }
            }
        }
    }
    return 0;
}