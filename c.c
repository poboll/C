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



    int a[7] = {9,8,7,6,5};
    int b = a[0];   // 5
    int c = a[6];   // 4
    int d = a[7];   // error

    int nums[10];
    int fff[7] = {5,2,0,1,3,1,4};
    add(a[]);
    search();
    findMin();
    climbStairs();
    countKDifference();
    game();
    minCount();

}

int add1(int a, int b) {
    return a + b;
}

int add3(int nums[10]) {
    int i;
    int s = 0;
    for(i = 0; i < nums; ++i) {
        s += nums[i];
    }
    return s;
}

int add4(int nums[10], int numsSize) {
    int i;
    int s = 0;
    for(i = 0; i < numsSize; ++i) {
        s += nums[i];
    }
    return s;
}

int add(int *nums, int numsSize) {
    // ...
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

int search(int* nums, int numsSize, int target) {   // (1)
    int i;
    for(i = 0; i < numsSize; ++i) {                 // (2)
        if(nums[i] == target) {
            return i;                               // (3)
        }
    }
    return -1;                                       // (4)
}

int findMin(int* nums, int numsSize) {
    int i, min = 100000;
    for(i = 0; i < numsSize; ++i) {
        if(nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}

int f[1000];                        // (1)
int climbStairs(int n) {
    f[0] = f[1] = 1;                // (2)
    for(int i = 2; i <= n; ++i) {
        f[i] = f[i-1] + f[i-2];     // (3)
    }
    return f[n];                    // (4)
}

int countKDifference(int* nums, int numsSize, int k) {
    int i, j, ans = 0;
    for(int j = i + 1; j < numsSize; ++j){
        if( abs(nums[i] - nums[j]) == k)
            ++ans;
    }
    return ans;
}

int game(int* guess, int guessSize, int* answer, int answerSize) {
    int i;
    int ans = 0;
    for(i = 0; i < 3; ++i) {
        ans +=(guess[i] == answer[i]) ? 1 : 0;  // (1)
    }
    return ans;
}

int minCount1(int* coins, intcoinsSize) {
    int i;
    int ans = 0;
    for(i = 0; i < coinsSize; ++i) {
        ans += (coins[i]+1)/2;  // ()
    }
    return ans;
}

int minCount(int* coins, int coinsSize) {
    int i;
    int ans = 0;
    for(i = 0; i < coinsSize; ++i) {
        ans += (coins[i]+1)/2;  // (1)
    }
    return ans;
}
int