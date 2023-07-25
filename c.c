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


    int (*cmp1)(const void *, const void *);

    int a[5] = {4,5,3,2,1};

    {1, 2, 3, 4, 5};

    __attribute__((unused)) int compar(const void *p1, const void *p2);

    cmp(1,2);
    qsort(a, 5, sizeof(int), cmp);
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
    containsDuplicate();
    maximumGap();
    sortArrayByParity();
    cmp();
    min(1,2);
    findMinDifference();

}
bool containsDuplicate(int* nums, int numsSize);
int* sortArrayByParity(int* nums, int numsSize, int* returnSize);
int findMinDifference(char ** timePoints, int timePointsSize);
int cmp2(const void *p1, const void *p2) { // (1)
    int v1 = *(int *)p1;                  // (2)
    int v2 = *(int *)p2;                  // (3)
    if(v1 < v2) {                         // (4)
        return -1;
    }else if(v1 > v2) {
        return 1;
    }
    return 0;
}

int cmp1(const void *p1, const void *p2) {
    return (*(int *)p1) - (*(int *)p2);
}

int cmp3(const void *p1, const void *p2) {
    return (*(int *)p2) - (*(int *)p1);
}

int cmp4(const void *p1, const void *p2) {
    return Qua(*(int *)p1) - Qua(*(int *)p2);
}

int cmp5(const void* a, const void* b) {
    return *(int *)a - *(int *)b;                                 // (1)
}
int* sortArray(int* nums, int numsSize, int *returnSize) {
    qsort(nums, numsSize,sizeof(int),cmp);// (2)
    *returnSize = numsSize;                                       // (4)
    return nums;                                                  // (4)
}

int cmp6(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}
int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[numsSize/2];                                            //(1)
}

int cmp6(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

bool containsDuplicate(int *nums, int numsSize) {
    int i;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(i = 1; i < numsSize; ++i) {
        if(nums[i] == nums[i-1]) {      // (1)
            return true;
        }
    }
    return false;
}

int cmp7(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int maximumGap(int* nums, int numsSize) {
    int i, max = 0;
    qsort(nums, numsSize, sizeof(int),cmp);
    for(i = 1; i < numsSize; ++i) {
        if(nums[i] - nums[i-1] > max) {     // (1)
            max = nums[i] - nums[i-1];
        }
    }
    return max;
}

int Qua(int x) {
    return x & 1;
}

int cmp8(const void *a, const void *b) {
    return Qua(*(int *)a) - Qua(*(int *)b);
}

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int i;
    int *ret = (int *)malloc(sizeof(int) * numsSize);           // (1)
    for(i = 0; i < numsSize; ++i) {
        ret[i] = nums[i];                                            // (2)
    }
    qsort(ret, numsSize, sizeof(int), cmp);  // (3)
    *returnSize = numsSize;                                          // (4)
    return ret;
}

int cmp9(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int findMinDifference(char ** timePoints, int timePointsSize) {
    int *ret = (int *) malloc(sizeof(int) * timePointsSize);
    int i, ans = 1440;
    int a, b;
    for(i = 0; i < timePointsSize; ++i) {
        sscanf(timePoints[i], "%d:%d", &a, &b);                             // (1)
        ret[i] = a * 60 + b;                                                // (2)
    }
    qsort(ret, timePointsSize, sizeof(int), cmp);   // (3)
    for(i = 1; i < timePointsSize; ++i) {
        ans = min(ans, ret[i] - ret[i-1]);                           // (4)
    }
    ans = min(ans, ret[0] - ret[timePointsSize-1] + 1440);           // (5)
    return ans;
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

bool search1(int* nums, int numsSize, int target) {
    int i;
    for(i = 0; i < numsSize; ++i) {
        if(nums[i] == target) {
            return true;
        }
    }
    return false;
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

int t[40];
int tribonacci(int n){
    t[0] = 0, t[1] = 1, t[2] = 1;
    for(int i = 3; i <= n; ++i) {
        t[i] = t[i-3] + t[i-2] + t[i-1];
    }
    return t[n];
}

int countKDifference(int* nums, int numsSize, int k){
    int i, j, ans = 0;
    for(int i = 0; i < numsSize; ++i){
        for(int j = i + 1; j < numsSize; ++j){
            if( abs(nums[i] - nums[j]) == k)
                ++ans;
        }
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

int minCount(int* coins, int coinsSize) {
    int i;
    int ans = 0;
    for(i = 0; i < coinsSize; ++i) {
        ans += (coins[i]+1)/2;  // (1)//利用C语言中的除法运算，考虑到为1的时候1/2==0 ,所以将每个数+1
    }
    return ans;
}

int peakIndexInMountainArray(int* arr, int arrSize)
//int i;
int peakIndexInMountainArray(int* arr, int arrSize) {
    int n = arrSize;
    int ans = -1;
    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            ans = i;
            break;
        }
    }
    return ans;
}
int peakIndexInMountainArray1(int* arr, int arrSize) {
    int n = arrSize;
    int left = 1, right = n - 2, ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] > arr[mid + 1]) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

//char x = 'o';
//char *p = (x)的地址;

//char x = 'o';
//char *p = &x;

//int a[] = {5,2,0,1,3,1,4};
//int *p = a;

//int a;
//int *p = &a;
//a == *p;
int *p = (int *)malloc(sizeof(int) * n );

int *getList(int *nums, int numsSize, int *returnSize) {
    // ...
}


//int a[7] = {5,2,0,1,3,1,4};
//int rSize;
////int *ret =  getList(a,7,&rSize);
//int xxx;
///**
//* Note: The returned array must be malloced, assume caller calls free().    // (1)
//*/
//int *func(int *nums, int numsSize, int *returnSize) {                       // (2)
//    int *ret = (int *)malloc( sizeof(int)* xxx );                      // (3)
//    // TODO                                                                 // (4)
//    *returnSize = xxx;                                                      // (5)
//    return ret;                                                             // (6)
//}

/**
* Note: The returned array must be malloced, assume caller calls free().    // (1)
*/
int *shuffle(int *nums, int numsSize, int *returnSize) {                     // (2)
    int i;
    int *ret = (int *)malloc(sizeof(int)* numsSize );                  // (3)
    for(i = 0; i < numsSize; ++i) {
        if(i & 1) {
            ret[i] = nums[n + i/2];
        }else {
            ret[i] = nums[(i+1)/2];
        }
    }
    *returnSize = numsSize;                                                 // (5)
    return ret;                                                             // (6)
}

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int *getConcatenation(int *nums, int numsSize, int *returnSize) {
    int i;
    int *ret = (int *)malloc(2*numsSize*sizeof(int)); // (1)
    for(i = 0; i < numsSize; ++i) {
        ret[i+numsSize] = ret[i] = nums[i];                // (2)
    }
    *returnSize = 2 * numsSize;                            // (3)
    return ret;
}

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int *buildArray(int *nums, int numsSize, int *returnSize) {
    int i;
    int *ret = (int *)malloc(sizeof(int) * numsSize );
    for(i = 0; i < numsSize; ++i) {
        ret[i] = nums[ nums[i] ];                // (1)
    }
    *returnSize = numsSize;
    return ret;
}

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int *runningSum(int *nums, int numsSize, int *returnSize) {
    int i;
    int *ret = (int *)malloc(sizeof(int) * numsSize );
    for(i = 0; i < numsSize; ++i) {     // (1)
        ret[i] = nums[i];
        if(i) {
            ret[i] += ret[i-1];
        }
    }
    *returnSize = numsSize;
    return ret;
}

char * reverseLeftWords(char* s, int k) {
    int i;
    int n = strlen(s);
    char *ret = (char *)malloc( (n + 1) * sizeof(char) );   // (1)
    for(i = 0; i < n; ++i) {
        ret[i] = s[(i + k) % n];                                 // (2)
    }
    ret[n] = '\0';                                               // (3)
    return ret;
}

char * defangIPaddr(char * address) {
    char * ret = (char *)malloc(1000 * sizeof(char));   // (1)
    int returnSize = 0;
    int i;
    for(i = 0; address[i]; ++i) {                            // (2)
        if(address[i]  == '.') {
            ret[ returnSize++ ] = '[';
            ret[ returnSize++ ] = '.';
            ret[ returnSize++ ] = ']';
        }else {
            ret[ returnSize ++ ] = address[i];
        }
    }
    ret[ returnSize ] = '\0';                             // (3)
    return ret;
}

char* replaceSpace(char* s) {
    char *ret = malloc( sizeof(char) * 30001 ); // (1)
    int i, retSize = 0;
    for(i = 0; s[i]; ++i) {
        if(s[i] == ' ') {
            ret[retSize++] = '%%';
            ret[retSize++] = '2';
            ret[retSize++] = '0';
        }else {
            ret[retSize++] = s[i];
        }
    }
    ret[retSize] = '\0';
    return ret;
}

int cmp10(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}
int maxProductDifference(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);    // (1)
    return nums[numsSize-1] * nums[numsSize-2] - nums[0] * nums[1];     // (2)
}

int cmp11(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int largestPerimeter(int *nums, int numsSize) {
    int i;
    qsort(nums, numsSize, sizeof(int), cmp);
    for(i = numsSize-1; i >= 2; --i) {
        if(nums[i-2] + nums[i-1] > nums[i]) {       // (1)
            return nums[i-2] + nums[i-1] + nums[i];
        }
    }
    return 0;
}

int cmp12(const void* a, const void *b) {
    return *(int *)a - *(int *)b;
}
int arrayPairSum(int* nums, int numsSize) {
    int i, ans = 0;
    qsort(nums, numsSize, sizeof(int), cmp);    // (1)
    for(i = 0; i < numsSize; i += 2) {
        ans += nums[i];                                                 // (2)
    }
    return ans;
}

int cmp(const void *a, const int *b) {
    return *(int *)a - *(int *)b;
}

int numRescueBoats(int* people, int peopleSize, int limit) {
    int i;
    int l = 0, r = peopleSize - 1;
    int ans = 0;
    qsort(people,peopleSize,sizeof(int),cmp);   // (1)
    while(l <= r) {
        if(l == r) {
            ++ans; break;                                               // (2)
        } else if(people[l] + people[r] > limit) {                      // (3)
            ++ans, r--;
        } else                                                          // (4)
            ++ans, ++l, --r;
    }
}
arrayPairSum(1,2)
largestPerimeter(1,2)
numRescueBoats((1,2)