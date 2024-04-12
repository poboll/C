// C 凑算式
// 题目描述：
//      B      DEF
// A + --- + ------- = 10
//      C      GHI
// 1
// 2
// 3
// 4
// 这个算式中A到I代表1到9的数字，不同的字母代表不同的数字。
// 比如：
// 6+8/3+952/714 就是一种解法，
// 5+3/1+972/486 是另一种解法。
// 这个算式一共有多少种解法？
// 分析分析：
// 做全排列next_permutation直接出结果
#include <iostream>
#include <algorithm>
int main() {
    int sum = 0;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    while(next_permutation(a, a + 9)) {
        float temp1 = a[0];
        float temp2 = a[1] * 1.0 / a[2];
        float temp3 = (a[3] * 100 + a[4] * 10.0 + a[5]) / (a[6] ** 100.0 + a[7] * 10.0 + a[8]);
        if(fabs(temp1 + temp2 + temp3 - 10) <= 1e-5)
        sum ++;
    }
    printf("%d", sum);
    return 0;
}