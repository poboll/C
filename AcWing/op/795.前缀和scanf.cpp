/*795.前缀和
输入一个长度为 nn 的整数序列。
接下来再输入 mm 个询问，每个询问输入一对 l,rl,r。
对于每个询问，输出原序列中从第 ll 个数到第 rr 个数的和。
输入格式
第一行包含两个整数 n 和 m。
第二行包含 n 个整数，表示整数数列。
接下来 m 行，每行包含两个整数 l 和 r，表示一个询问的区间范围。
输出格式
共 m 行，每行输出一个询问的结果。
数据范围
1≤l≤r≤n,
1≤n,m≤100000
−1000≤数列中元素的值≤1000
输入样例：
5 3
2 1 3 6 4
1 2
1 3
2 4
输出样例：
3
6
10
*/
#include<iostream>
using namespace std;
const int N = 1e5+10;
int n, m;
int a[N], s[N];
int main() {
    scanf("%d%d", &n, &m);//大数据输入scanf快一倍
    for(int i = 1; i <= n; i ++) { 
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i ++) {//前缀和的初始化
        s[i]=s[i - 1] + a[i];
    }
    while(m -- ) { 
        int l,r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);//区间和的计算
    }
    return 0;
}