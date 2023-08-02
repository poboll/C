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

int cmp13(const void *a, const void *b) {
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
    return ans;
}

int cmp14(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void wiggleSort(int* nums, int numsSize) {
    int i;
    int l, r;
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    for(i = 0; i < numsSize; ++i) {
        ret[i] = nums[i];                                           // (1)
    }
    qsort(ret,numsSize,sizeof(int),cmp);    // (2)
    r = numsSize-1;
    for(i = 1; i < numsSize; i += 2) {
        nums[i] = ret[r--];                                         // (3)
    }
    for(i = 0; i < numsSize; i += 2) {
        nums[i] = ret[r--];                                         // (4)
    }
}

int cmp15(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int i, j , ans;
    qsort(g,gSize,sizeof(int),cmp);      // (1)
    qsort(s,sSize,sizeof(int),cmp);
    i = gSize - 1, j = sSize - 1;                                // (2)
    ans = 0;
    while(i >= 0 && j >= 0) {
        if(s[j] >= g[i]) {                                       // (3)
            --i, --j;
            ++ans;
        } else
            --i;                                                 // (4)
    }
    return ans;
}

int minOperations(int* nums, int numsSize) {
    int i;
    int ans = 0, pre = nums[0] + 1;
    for(i = 1; i < numsSize; ++i) {
        if(pre < nums[i]) {
            pre = nums[i] + 1;      // (1)
        }else {
            ans += pre - nums[i];   // (2)
            ++pre;
        }
    }
    return ans;
}

int minIncrementForUnique1(int* A, int ASize){
    if (ASize == 0 || ASize == 1)  return 0;
    int isExisted[101000] = {0};
    int doubled[101000] = {0};
    int cnt = 0;
    isExisted[A[0]] = 1;
    for (int i = 1; i < ASize; i++) {
        if (isExisted[A[i]]) { //如果已存在，把该数字放进已重复数组里
            doubled[cnt++] = A[i];
        } else {
            isExisted[A[i]] = 1; //记录每一个存在的数
        }
    }
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
        for (int j = (doubled[i] + 1); ;j++) {
            if (!isExisted[j]) { //从每个数加1开始，找到第一个未存在过的大于它的数
                isExisted[j] = 1; //使该数“已存在”
                ans += (j - doubled[i]); //其差值即为最小加一次数
                break;
            }
        }
    }
    return ans;
}

int minIncrementForUnique2(int* nums, int numsSize){
    if(numsSize == 0) return 0;
    int* num = (int*)calloc(101000, sizeof(int)); //储存nums中的每个数
    int j, sum = 0;
    for(int i = 0; i < numsSize; ++i){
        if(num[nums[i]] == 0){ //当前数未出现过，标记数组
            num[nums[i]]++;
        }else{ //如果当前数已经出现过
            j = nums[i]+1;
            while(num[j] != 0) j++; //当前数往后寻找到未出现过的数
            num[j] = 1; //修改该数出现一次
            sum += j - nums[i]; //记录从nums[i]一直加到该数的和
        }
    }
    free(num);
    return sum;
}
/*按照题解的方法，先设一个数组记录每个数出现的次数，再遍历这个数组，遇到出现次数大于1的就记录个数和它先扣掉的数。遇到出现次数为0的就补上相加的数。 比如 [3,2,1,2,1,7] ，重复了一个1一个2，可以补到空缺的4和5上，需要的步数是（4+5-1-2），我们可以让move先-1-2，遇到空的再+4+5。 执行用时48ms超越81.91%。消耗内存12.8MB，超越6.45%。*/
int cmp16(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int triangleNumber(int* nums, int numsSize) {
    int i, j, k;
    int ans = 0;
    qsort(nums,numsSize,sizeof(int),cmp);   // (1)
    for(i = 0; i < numsSize; ++i) {
        j = i + 1;
        k = j + 1;                                                  // (2)
        while(j < numsSize) {
            while(k < numsSize) {
                if(nums[i] + nums[j] <= nums[k]) {
                    break;                                          // (3)
                }
                ++k;
            }
            ans += k-j-1;                                           // (4)
            ++j;                                                    // (5)
            if(k == j) k++;
        }

    }
    return ans;
}

int diagonalSum(int** mat, int matSize, int* matColSize) {
    int r = matSize;                    // (1)
    int c = matColSize[0];
    int i;
    int ans = 0;
    for(i = 0; i < r; ++i) {
        ans += mat[i][i];               // (2)
    }
    for(i = 0; i < r; ++i) {
        if(r-i-1 != i) {
            ans += mat[i][r-i-1];       // (3)
        }
    }
    return ans;
}

int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int i, j, ans = 0;
    int r = gridSize;               // (1)
    int c = gridColSize[0];
    for(i = 0; i < r; ++i) {
        for(j = 0; j < c; ++j) {
            if(grid[i][j] < 0) {
                ++ans;              // (2)
            }
        }
    }
    return ans;
}

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int i, j;
    int maxv = -1, maxIdx, sumv;
    for(i = 0; i < accountsSize; ++i) {
        sumv = 0;
        for(j = 0; j < *accountsColSize; ++j) {
            sumv += accounts[i][j];             // (1)
        }
        if(sumv > maxv) {
            maxv = sumv;                        // (2)
            maxIdx = i;
        }
    }
    return maxv;
}

int checkSame(int** matrix, int sr, int sc, int maxr, int maxc) {   // (1)
    int step = 0;
    while(1) {
        if(sr + step >= maxr) {
            break;                                                  // (2)
        }
        if(sc + step >= maxc) {
            break;                                                  // (3)
        }
        if(matrix[sr+step][sc+step] != matrix[sr][sc]) {            // (4)
            return false;
        }
        ++step;                                                     // (5)
    }
    return true;                                                    // (6)
}

bool isToeplitzMatrix(int** matrix, int matrixsize, int* matrixcolsize) {
    int r = matrixsize;
    int c = matrixcolsize[0];
    int i;
    for(i = 0; i < c; ++i) {
        if (!checkSame(matrix,0,i,r,c) ) {      // (7)
            return false;
        }
    }
    for(i = 0; i < r; ++i) {
        if (!checkSame(matrix,i,0,r,c)) {       // (8)
            return false;
        }
    }
    return true;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int* luckyNumbers(int** matrix, int matrixsize, int* matrixcolSize, int* returnSize) {
    int i, j;
    int r = matrixsize;
    int c = matrixcolSize[0];
    int rmin[100];
    int cmax[100];
    int *ret = (int *)malloc(sizeof(int) * r * c );
    for(i = 0; i < r; ++i) {
        rmin[i] = 1000000;
        for(j = 0; j < c; ++j) {
            rmin[i] = min(rmin[i],matrix[i][j]);               // (1)
        }
    }
    for (j = 0; j < c; ++j) {
        cmax[j] = 0;
        for(i = 0; i < r; ++i) {
            cmax[j] = max(cmax[j], matrix[i][j]);               // (2)
        }
    }
    *returnSize = 0;
    for(i = 0; i < r; ++i) {
        for(j = 0; j < c; ++j) {
            if (matrix[i][j] == rmin[i] && matrix[i][j] == cmax[j]) {
                ret[(*returnSize)++] = matrix[i][j];
            }
        }
    }
    return ret;
}

int check(int** mat, int matize, int matColSize, int r, int c) {
    int i;
    if(mat[r][c] != 1) {
        return 0;
    }
    for(i = 0; i < matize; ++i) {
        if(i != r && mat[i][c]) {
            return 0;
        }
    }

    for(i = 0; i < matColSize; ++i) {
        if(i != c && mat[r][i]){
            return 0;
        }
    }
    return 1;
}

int numSpecial(int** mat, int matsize, int* matColsize) {
    int i, j;å
    int sum = 0;
    for(i = 0; i < matsize; ++i) {
        for (j = 0; j < matColsize[i]; ++j) {
            sum += check(mat, matsize, matColsize[i], i, j);
        }
    }
    return sum;
}

int **myMalloc(int r, int c, int* returnSize, int** returnColumnSizes) {
    int i;
    int **ret = (int **)malloc( sizeof(int *) * r );        // (1)
    *returnColumnSizes = (int *)malloc( sizeof(int) * r );  // (2)
    *returnSize = r;                                             // (3)
    for(i = 0; i < r; ++i) {
        ret[i] = (int *)malloc( sizeof(int) * c );          // (4)
        (*returnColumnSizes)[i] = c;                             // (5)
    }
    return ret;
}

int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int ** returnColumnSizes) {
    int i, j;                                                   // (1)
    int r = imageSize, c = imageColSize[0];                     // (2)
    int **ret = myMalloc(r, c, returnSize, returnColumnSizes);  // (3)
    for(i = 0; i < r; ++i) {
        for(j = 0; j < c; ++j) {
            ret[i][j] = 1 - image[i][ c-1-j ];                  // (4)
        }
    }
    return ret;                                                 // (5)
}

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int i, j;                                                                   // (1)
    int r = matrixColSize[0], c = matrixSize;                                   // (2)
    int **ret = myMalloc(r, c ,returnSize, returnColumnSizes);   // (3)
    for(i = 0; i < r; ++i) {
        for(j = 0; j < c; ++j) {
            ret[i][j] = matrix[j][i];                                           // (4)
        }
    }
    return ret;                                                                 // (5)
}

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int n = matSize;
    int m = matColSize[0];
    int **ret, id;
    int i, j;

    ret = myMalloc(r, c, returnSize, returnColumnSizes);    // (1)

    if(n* m != r*c) {
        *returnSize = n;
        for(i = 0; i < n; ++i) {
            (*returnColumnSizes)[i] = m;
        }
        return mat;                                         // (2)
    }

    for(i = 0; i < r; ++i) {
        for(j = 0; j < c; ++j) {
            id = i * c + j;                                 // (3)
            ret[i][j] = mat[id / m][id % m];                // (4)
        }
    }

    return ret;
}

int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
    int **ret, i, j;
    if(originalSize != n*m) {
        *returnSize = 0;                                          // (1)
        return ret;
    }
    ret = myMalloc(m, n, returnSize, returnColumnSizes);    // (2)
    for(i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            ret[i][j] = original[ i * n + j ];                    // (3)
        }
    }
    return ret;                                                   // (4)
}

construct2DArray(1,2,3,4,5,6,7)
matrixReshape(1,2,3,4,5,6)
transpose(1,2,3,4)
flipAndInvertImage(1,2,3,4)
myMalloc(1,2)
check(1,2)
numSpecial(12,2)
min (1,2)
isToeplitzMatrix(1,2)
checkSame(1,2)
maximumWealth(1,2)
countNegatives(1,2)
diagonalSum(1,2)
triangleNumber(1,2)
minOperations(1,2)
findContentChildren(1,2)
wiggleSort(1,2)
arrayPairSum(1,2)
largestPerimeter(1,2)
numRescueBoats((1,2)