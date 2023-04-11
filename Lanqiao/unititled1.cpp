/*
Luna 准备玩一个无聊的游戏，初始时她有三个整数a,b,c。她将玩k轮游戏,每一轮游戏中，她将按顺序做如下 3 步:
如果 a> b 则 a=a- b1
2如果 b>c则 b=b-c
P如果 c>a 则 c=c-a.Luna 想让你帮她计算k轮后a,b,c的值。
输入格式:
本题包含多组测试数据，第一行为一个整数 T(1≤ T≤ 10)，表示测试数据组数对于每组测试数据，为4 个整数a,b,c,k (1 <a,b,c< 10,1k  10，表示游戏开始时给定的 3 个整数以及游戏的轮数。
输出格式:
对于每组测试数据，输出3 个整数表示游戏结束后a、b、c 的值
Time Limit: 1000MS
Memory Limit: 20MB*/
/*如果1s的时限给数据范围是10的7或8次方的话一般只能用O（n）的算法
对于上面的题，10的9次方10组数据，也就是10的10次方的时间，这样子1s是不可行的*/
#include <iostream>
using namespace std;
const int max1 = 1000000;
const int max2 = 1000000000;
const int max3 = 10;
void Yoriko(int &a, int &b, int &c, int &k) {
    int i;
    for (i = 0; i < k; i++) {
        if(a==b&&b==c) break;
        if (a > b) a = a - b;
        if (b > c) b = b - c;
        if (c > a)c = c - a;
    }
}
int main() {
    int t;
    int a, b, c, k;
    int i;
    int str[max3][3];
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> a >> b >> c >> k;
            Yoriko(a,b,c,k);
            str[i][0] = a;
            str[i][1] = b;
            str[i][2] = c;
        }
        for (i = 0; i < t; i++) {
            cout << str[i][0] << " " << str[i][1] << " " << str[i][2] << endl;
        }
}