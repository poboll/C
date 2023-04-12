/*866.试除法判定质数
给定 n 个正整数 ai，判定每个数是否是质数。
输入格式
第一行包含整数 n。
接下来 n 行，每行包含一个正整数 ai。
输出格式
共 n 行，其中第 i 行输出第 i 个正整数 ai 是否为质数，是则输出 Yes，否则输出 No。
数据范围
1≤n≤100,
1≤ai≤2*10^9
样例
输入样例：
2
2
6
输出样例：
Yes
No*/
/*基本思想：
①暴力枚举：根据求质数的基本定义计算,时间复杂度为O(n);
②优化：根据质数的基本性质（M能被d整除,则M也能被M/d整除）发现可以只枚举到d和M/d中较小的那个即可, 处理为d <= M/d 化为 d <= sqrt(M),时间复杂度降到O(√n)。*/
/*注意for循环中的判断条件i <= x / i，之所以写成这样而不是写成i <= sqrt(x)或者i * i <= x是因为：
①i <= sqrt(x) ：在执行每次循环的时候都要计算一遍平方根会浪费时间；
②i * i <= x ：当i的值很接近整形最大值的时候i * i就超范围溢出了。*/
#include <iostream>
using namespace std;
bool IsPrime(int x) {//判断是否是质数,是返回true,不是返回false
    if (x < 2)  return false;//直接排除小于2的数
    else {
        for (int i = 2; i <= x / i; i ++ ) {
            if (x % i == 0) return false;
        }
        return true;
    }
}
int main() {
    int n;
    cin >> n;
    while(n --) {
        int x;
        cin >> x; //scanf("%d", &a);
        if(IsPrime(x))  cout << "Yes" << endl; //printf("Yes\n");
        else cout << "No" << endl; //else printf("No\n");
    }
    return 0;
}