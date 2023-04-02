/*95.费解的开关
你玩过“拉灯”游戏吗？
25 盏灯排成一个 5×5 的方形。
每一个灯都有一个开关，游戏者可以改变它的状态。
每一步，游戏者可以改变某一个灯的状态。
游戏者改变一个灯的状态会产生连锁反应：和这个灯上下左右相邻的灯也要相应地改变其状态。
我们用数字 1 表示一盏开着的灯，用数字 0 表示关着的灯。
下面这种状态
10111
01101
10111
10000
11011
在改变了最左上角的灯的状态后将变成：
01111
11101
10111
10000
11011
再改变它正中间的灯后状态将变成：
01111
11001
11001
10100
11011
给定一些游戏的初始状态，编写程序判断游戏者是否可能在 6 步以内使所有的灯都变亮。
输入格式
第一行输入正整数 n，代表数据中共有 n 个待解决的游戏初始状态。
以下若干行数据分为 n 组，每组数据有 5 行，每行 5 个字符。
每组数据描述了一个游戏的初始状态。
各组数据间用一个空行分隔。
输出格式
一共输出 n 行数据，每行有一个小于等于 6 的整数，它表示对于输入数据中对应的游戏状态最少需要几步才能使所有灯变亮。
对于某一个游戏初始状态，若 6 步以内无法使所有灯变亮，则输出 −1。
数据范围
0<n≤500
输入样例
3
00111
01011
10001
11010
11100

11101
11101
11110
11111
11111

01111
11111
11111
11111
11111
输出样例
3
2
-1
*/
/*思路
每个位置至多只会被点击一次
若固定了第一行，则满足题意的点击方案至多只有一种。原因：当第i行某一位为1时，若前i行已被固定，只能点击第i+1行该位置上的数字才能使第i行的这一位变成0，从上到下使用归纳法可得上述结论。
点击的先后顺序不影响最终结果。
于是，我们不妨先考虑第一行如何点击。在枚举第一行的点击方案后，就可以认为第一行固定不动，在考虑2 ~ 5行如何点击。而按照上述性质2，此时第2 ~ 5行的点击方案是确定的。
若到达第n行是不全为1，说明这种点击方式不合法。在所有合法的点击方式中取点击次数最少的就是答案。*/
#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;
int n;
char g[N][N] , backup[N][N]; //backup是备份数组

void turn(int x , int y)
{
    int dx[5] = {0 , 1 , 0 , -1 , 0} , dy[5] = {1 , 0 , -1 , 0 , 0};
    for(int i = 0; i < 5; i++)
    {
        int a = x + dx[i] , b = y + dy[i];
        if(a < 0 || a >= 5 || b < 0 || b >= 5) continue;
        // 0的ASCII码为48  1的ASCII码为49 所以只需要对'0' ^ 1 即可得到 '1' 相反同理
        g[a][b] ^= 1;
    }
}

int main()
{
    cin >> n;
    
    while(n--)
    {
        
        for(int i = 0; i < 5; i++) cin >> g[i];
        
        int res = 10; // 记录结果
        
        // 枚举第一行所有的按开关或不按开关的状态，1:按开关  0:不按开关
        for(int i = 0; i < 32; i++)       
        {
            int step = 0; //记录步数
            
            // 先将当前数组备份到backup数组中,因为每次遍历第一行，要使用原始数组来遍历
            memcpy(backup , g , sizeof g);  
            
            // 看第一行的第j列是否需要按开关
            for(int j = 0; j < 5; j++)
            {
                if(i >> j & 1) // 如果第j位是1的话,就需要按开关,否则不按开关
                {
                    step++; // 记录步数
                    turn(0 , j); // 按开关
                }
            }
            
            // 遍历其他行，由于其他行是否按开关都只与上一行有关，所以只遍历0~4行即可
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    if(g[i][j] == '0') // 如果第i行j类是关灯状态，那么就必须按第i+1行j列的开关
                    {
                        step++;
                        turn(i + 1 , j);
                    }
                }
            }
            
            // 最后只需要看最后一行是否有灯关着即可
            bool dark = false;
            for(int i = 0; i < 5; i++)
            {
                if(g[4][i] == '0')
                {
                    dark = true;
                    break;
                }
            }
            
            // 如果灯全部打开
            if(!dark) res = min(res , step);
            
            memcpy(g , backup , sizeof g); // 将原始数组重新赋值回去，供第一行遍历
        }
        
        if(res > 6) res = -1;
        cout << res << endl;
    }
    
    return 0;
}
