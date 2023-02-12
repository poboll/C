/*797.差分
给定一个长n的整数序列A，再进行m次操作，每次操作包含三个整数l,r,c表示将序列中的[l,r]每个数都增c 。输出操作完后的数列。区间的下标是从1开始计数的。
输入格式：
第一行包含两个整数n和m。第二行包含n个整数，表示整数序列。接下来m行，每行包含三个整数l，r，c表示一个操作。
输出格式：
共一行，包含n个整数，表示最终序列。
数据范围：
1≤n,m≤100000
1 ≤ l ≤ r ≤ n
− 1000 ≤ c ≤ 1000 -1000
− 1000 ≤ A [ i ] ≤ 1000
样例输入：
输入：
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1
输出：
3 4 5 3 4 2
*/
/*
思路是利用差分数组。求出差分数组d使得
A [ i ] = ∑ d [ 0 : i ] A[i]=\sum d[0:i]
A[i]=∑d[0:i]
真实代码中可以想象A一开始都是0，每次将A[i:i]增加一个数，而对于差分数组来说，原数组A[l:r]全体增加一个数c，效果是d[l]增加c，而d[r+1]减少c（如果r+1越界了那就忽略），这样方便编程。*/
#include <iostream>
using namespace std;
const int N = 100010;
int n, m;
int a[N],b[N];
void insert(int l, int r, int c){//插入函数
    b[l] += c;
    b[r + 1] -= c;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i ++){
        insert(i, i, a[i]);
    }
    while (m --){
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    for (int i = 1; i <= n; i ++){
        b[i] += b[i - 1];
    }
    for (int i = 1; i <= n; i ++){
        printf("%d ", b[i]);
    }
    return 0;
}