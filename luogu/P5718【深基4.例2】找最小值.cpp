// 
//  Created by 大妖怪 on 2024/3/16.
//
// P5718【深基4.例2】找最小值
// 题目描述
// 给出 n 和 n 个整数 a_i，求这 n 个整数中最小值是什么。
// 输入格式
// 第一行输入一个正整数 n，表示数字个数。
// 第二行输入 n 个非负整数，表示 a_1,a_2 \dots a_n，以空格隔开。
// 输出格式
// 输出一个非负整数，表示这 n 个非负整数中的最小值。
// 样例输入1
// 8
// 1 9 2 6 0 8 1 7
// 样例输出1
// 0
// 提示
// 数据保证，n <= 100 且 0 <= a_i <= 1000。
//#include <stdio.h>
//int main() {
//    int n, a[1010] = {0}, ans;
//    scanf("%d", &n);
//    for(int i = 1; i <= n; ++ i) {
//        scanf("%d", &a[i]);
//    }
//    ans = a[1];
//    for(int i = 1; i <= n; ++ i) {
//        if(a[i] <= ans) {
//            ans = a[i];
//        }
//    }
//    printf("%d", ans);
//    return 0;
//}
#include <stdio.h>
// 听说手写min会更快
int min(int x, int y) {
    return x < y ? x : y;
}
int main() {
    // ans要初始化一个很大的数、不然答案会变成0
    int n, in, ans = 1e9;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i) {
        scanf("%d", &in);
        ans = min(ans, in);
    }
    printf("%d", ans);
    return 0;
}

