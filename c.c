#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
    printf("吴粤大麻瓜\n");
    mySqrt(1);
    maximum()
    return 0;
}

返回类型 函数名 (参数列表)
{
    函数体
    return 返回值;
}

int multiply(int A, int B) {  //(1)
    return A * B;
}

int divide(int a, int b){
    if(a == -2147483648 && b == -1) {
        return 2147483647;              //(1)
    }
    return a / b;                       //(2)
}

double myPow(double x, int n){          //(1)
    return pow(x, n);                   //(2)
}

int mySqrt(int x) {                     //(1)
    return (int)sqrt(x);
}

int maximum(int a, int b){
    return a > b ? a : b;   //(1)
}