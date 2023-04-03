/*1208.带分数
小明正在玩一个“翻硬币”的游戏。
桌上放着排成一排的若干硬币。我们用 * 表示正面，用 o 表示反面（是小写字母，不是零）。
比如，可能情形是：**oo***oooo
如果同时翻转左边的两个硬币，则变为：oooo***oooo
现在小明的问题是：如果已知了初始状态和要达到的目标状态，每次只能同时翻转相邻的两个硬币,那么对特定的局面，最少要翻动多少次呢？
我们约定：把翻动相邻的两个硬币叫做一步操作。
输入格式
两行等长的字符串，分别表示初始状态和要达到的目标状态。
输出格式
一个整数，表示最小操作步数
数据范围
输入字符串的长度均不超过100。
数据保证答案一定有解。
输入样例1：
**********
o****o****
输出样例1：
5
输入样例2：
*o**o***o***
*o***o**o***
输出样例2：
1
*/
/*思路
每次改变一个硬币的状态、它后面硬币也随之改变。从前往后、依次确定每一个硬币的状态、如果与目标状态不同、则翻转该硬币以及该硬币后面硬币一次、相同则无需反转。
以此类推、每一个硬币最后都能够到达目标状态。*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110;
char start[N], aim[N];
int n, res;
void turn(int i) {
    if(start[i] == '*') start[i] = 'o';
    else start[i] = '*';
}
int main() {
    cin >> start >> aim;
    n = strlen(start);
    for(int i = 0 ; i < n - 1 ;i ++)
        if(start[i] != aim[i]) {
            turn(i), turn(i + 1);
            res ++;
        }
    cout << res << endl;
    return 0;
}