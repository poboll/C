/*867.分解质因数
给定 n 个正整数 ai，将每个数分解质因数，并按照质因数从小到大的顺序输出每个质因数的底数和指数。
输入格式
第一行包含整数 n。
接下来 n 行，每行包含一个正整数 ai。
输出格式
对于每个正整数 ai，按照从小到大的顺序输出其分解质因数后，每个质因数的底数和指数，每个底数和指数占一行。
每个正整数的质因数全部输出完毕后，输出一个空行。
数据范围
1≤n≤100
2≤ai≤2*10^9
输入样例：
2
6
8
输出1样例：
2 1
3 

2 3*/
/*分析
一开始我是想用先求出 2 ~ 2e9之间的素数表，然后根据素数表来求每个ai的质因子和指数的
但是开素数表的时候要开到 2*10^9 太大了，爆内存，所以这个方法行不通
for(int i = 2; i <= x / i; i++) 列举了所有可能是x质因子的数，虽然里面可能有合数，但是由于每遇到一个质因子，就把该质因子的最大指数倍给除掉了，所以有合数并不影响*/
#include <iostream>
using namespace std;
void divide(int n) {
    for(int i = 2; i <= n; i ++) {
        if(n % i == 0) {//i 一定是质数
            int s = 0;
            while(n % i == 0) {
                n /= i;
                s ++;
            }
            printf("%d %d\n", i ,s);
        }
    }
    if(n > 1)   printf("%d %d\n", n ,1);
    puts("";)
}
int main() {
    int n;
    scanf("%d", &n);
    while(n --) {
        int x;
        scanf("%d", &x);
        divide(x);
    }
    return 0;
}