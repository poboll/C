// B 星系炸弹
// 题目描述：
// 在X星系的广袤空间中漂浮着许多X星人造“炸弹”，用来作为宇宙中的路标。
// 每个炸弹都可以设定多少天之后爆炸。
// 比如：阿尔法炸弹2015年1月1日放置，定时为15天，则它在2015年1月16日爆炸。
// 有一个贝塔炸弹，2014年11月9日放置，定时为1000天，请你计算它爆炸的准确日期。
// 请填写该日期，格式为 yyyy-mm-dd 即4位年份2位月份2位日期。比如：2015-02-19
// 请严格按照格式书写。不能出现其它文字或符号。
// 分析分析：
// 他来了他来了，好欸，是对于日期的模拟！！！他就是一个我们对于日期的累加
// 注意：大小月！！！注意润平年！！！over！！！
#include <stdio.h>
void fact(int year, int yue, int tian, int ri) {
    for(int i = 1; i <= ri; ++ i) {
        tian ++;
        // 1 3 5 7 8 10 12
        if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12) {
            if(tian > 31) {
                tian = 1;
                yue ++;
            }
        }
        if(yue==4||yue==6||yue==9||yue==11) {
            if(tian > 30) {
                tian = 1;
                yue ++;
            }
        }
        if(year%4==0||year%400==0&&year%100!=0) {
            if(yue == 2 && tian > 29) {
                tian = 1;
                yue ++;
            }
        }else {
            if(yue == 2 && tian > 28) {
                tian = 1;
                yue ++;
            }
        }
        if(yue == 13) {
            year ++;
            yue = 1;
        }
    }
    printf("%d-", year);
    if(yue < 10) {
        printf("0%d-", yue);
    }else {
        printf("%d-", yue);
    }
    if(tian < 10) {
        printf("0%d", tian);
    }else {
        printf("%d", tian);
    }
}
int main() {
    fact(2014, 11, 9, 1000); // 2017-08-05
}