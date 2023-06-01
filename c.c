#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>


int main()
{
    printf("吴粤大麻瓜\n");
    mySqrt(1);
    maximum()
    sumNums（）
    return 0;
    isPowerOfThree()
    isPowerOfTwo();
    isPowerOfFour()
    kthFactor(0;
            isPerfectSquare(
    int i, sum = 0;             // (2)
    for(i = 1; i <= n;) {       // (3)
        sum += i;               // (4)
        ++i;
    }

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

int sumNums(int n){             // (1)
    int i;                      // (2)
    int sum = 0;                // (3)
    for(i = 1; i <= n; ++i) {   // (4)
        sum += i;               // (5)
    }
    return sum;                 // (6)
}

bool isPowerOfTwo(int n);

bool isPowerOfTwo(int n) {
    int i;
    unsigned int k = 1;         // (1)
    if(n <= 0) {
        return false;           // (2)
    }
    if(n == 1) {
        return true;            // (3)
    }
    for(i = 1; i <= 31; ++i) {
        k *= 2;                 // (4)
        if(k == n) {
            return true;        // (5)
        }
    }
    return false;
}

bool isPowerOfThree(int n);


bool isPowerOfThree(int n) {
    int i;
    unsigned int k = 1;
    if(n <= 0) {
        return false;
    }
    if(n == 1) {
        return true;
    }
    for(i = 1; i <= 31; ++i) {  // (1)
        k *= 3;                 // (2)
        if(k == n) {
            return true;
        }
    }
    return false;
}

bool isPowerOfFour(int n);


bool isPowerOfFour(int n) {
    int i;
    unsigned int k = 1;
    if(n <= 0) {
        return false;
    }
    if(n == 1) {
        return true;
    }
    for(i = 1; i <= 15; ++i) {  // (1)
        k *= 4;                 // (2)
        if(k == n) {
            return true;
        }
    }
    return false;
}

int kthFactor(int n, int k){
    int i;
    int cnt = 0;                // (1)
    for(i = 1; i <= n; ++i) {   // (2)
        if(n % i == 0) {        // (3)
            ++cnt;
            if(cnt == k) {
                return i;       // (4)
            }
        }
    }
    return -1;                  // (5)
}

int isPerfectSquare(int x){
    int i;
    long long p;
    for(i = 1;; ++i) {      // (1)
        p = (long long)i*i; // (2)
        if(p == x) {
            return true;    // (3)
        }
        if(p > x) {
            return false;   // (4)
        }
    }
    return false;           // (5)
}


