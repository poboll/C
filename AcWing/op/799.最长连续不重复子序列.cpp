/*799.最长连续不重复子序列
给定一个长度为 n 的整数序列，请找出最长的不包含重复的数的连续区间，输出它的长度。
输入格式
第一行包含整数 n。
第二行包含 n 个整数（均在 0 ∼ 10^5 范围内），表示整数序列。
输出格式
共一行，包含一个整数，表示最长的不包含重复的数的连续区间的长度。
数据范围
1 ≤ n ≤ 10^5
输入样例：
5
1 2 2 3 5
输出样例：
3
*/
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N], s[N]; //a[i]用来存放原序列,s[i]用来存放区间中各数字出现次数

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    
    int res = 0;
    for (int i = 0, j = 0; i < n; i ++ )
    {
        s[a[i]] ++; //a[i]出现次数加1
        while (s[a[i]] > 1) s[a[j ++]] --; //起点右移，直至没有区间内没有重复
        res = max(res, i - j + 1);
    }
    
    cout << res << endl;
    return 0;
}
