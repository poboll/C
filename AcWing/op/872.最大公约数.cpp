//
// Created by 大妖怪 on 2023/9/14.
//
#include <iostream>
using namespace std;
int gcd(int a, int b) {
    return b ? gcd(b, a % d) : a;//(a, 0)-->a。0可整除任何数
}
int main(){
    int n;
    while(n --) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}