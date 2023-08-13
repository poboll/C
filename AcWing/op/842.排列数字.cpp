/*842.排列数字
给定一个整数 n，将数字 1∼n 排成一排，将会有很多种排列方法。
现在，请你按照字典序将所有的排列方法输出。
输入格式
共一行，包含一个整数 n。
输出格式
按字典序输出所有排列方案，每个方案占一行。
数据范围
1≤n≤7
输入样例：
3
输出样例：
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
#include <iostream>
using namespace std;
const int N = 10;
int n, path[N];//存储当前已经插入的数字
bool s[N];//标记数组，标记下标为i的数字是否用过
void dfs(int cur) {
    if(cur > n) {//如果n个位置都已经插入完成，此时cur为n+1，因为数组下标从1开始
        for(int i = 1; i <= n; i ++)  printf("%d ",path[i]);
        puts("");
        return;
    }
    //遍历所有数字，找出还没使用过的数字
    for(int i = 1; i <= n; i ++) {
        if(!s[i]) {//如果第i个数字未使用过
            path[cur] = i;//把第i个数字插入到数字当前数组中
            s[i] = true;//标记第i个数字已经使用
            dfs(cur + 1);//继续深搜能够插入下一个位置的数字
            s[i] = false;//恢复现场，将i标记成还未使用过
        }
    }
}
int main() {
    cin >> n;
    dfs(1);
    return 0;
}