//
// Created by 大妖怪 on 2023/9/17.
//
#include <iostream>
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        return a;
    }

    int d = exgcd(b, a % b, y, x);//不能改变递归调用的参数顺序
    y -= a / b * x;
    return d;
}

int main() {
    int n;
    scanf("%d", &n);

    while(n --) {
        int a, b, x, y;
        scanf("%d%d", &a, &b);

        exgcd(a, b, x, y);

        printf("%d %d\n", x, y);
    }

    return 0;
}