// A 第几天
// 题目描述：
// 2000年的1月1日，是那一年的第1天。
// 那么，2000年的5月4日，是那一年的第几天？
// 注意：需要提交的是一个整数，不要填写任何多余内容。
// 分析分析：
// 这因该是我目前这几期里面最简单的题了吧，我们可以直接手算，如果我们要打代码的话就是…
#include <stdio.h>
int print(int year, int yue, int ri) {
    int y = 1, r = 1, count = 1; // 用于计数
    while(1) {
        r ++;
        count ++;
        if(y == 1 || y == 3 || y == 5 || y == 8 || y == 10 || y == 12) {
            if(r > 31) {
                y ++;
                r = 1;
            }
        }
        if(y == 2) {
            if(year % 4 == 0 || year % 400 == 0 && year % 100 != 0) {
                if(r > 29) {
                    y ++;
                    r = 1;
                }
            } else {
                if(r > 28) {
                    y ++;
                    r = 1;
                }
            }
        }
        if(y == 4 || y == 3 || y == 6 || y == 9 || y == 11) {
            if(r > 30) {
                y ++;
                r = 1;
            }
        }
        if(yue == y && ri = r) {
            break;
        }
    }
    return count;
}
int main() {
    int year, yue, ri;
    scanf("%d%d%d", &year, &yue, &ri);
    printf("%d", print(year, yue, ri));
    return 0;
}