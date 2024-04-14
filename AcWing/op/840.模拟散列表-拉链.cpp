/*840.模拟散列表
维护一个集合，支持如下几种操作：
    I x，插入一个数 x；
    Q x，询问数 x 是否在集合中出现过；
现在要进行 N 次操作，对于每个询问操作输出对应的结果。
输入格式
第一行包含整数 N，表示操作数量。
接下来 N 行，每行包含一个操作指令，操作指令为 I x，Q x 中的一种。
输出格式
对于每个询问指令 Q x，输出一个询问结果，如果 xx 在集合中出现过，则输出 Yes，否则输出 No。
每个结果占一行。
数据范围
1≤N≤10^5
−10^9≤x≤10^9
输入样例：
5
I 1
I 2
I 3
Q 2
Q 5
输出样例：
Yes
No
在插入和查询时,数据范围过大,会超时,这里可以避免这个问题 
*/
//先采用拉链法
#include<cstring>
#include<iostream>
using namespace std;
//我们哈希表的存储应尽可能采用质数
//因此这里我们需要找一个比100000大的最小质数
/*int main() {
    for(int i = 100000; ;i++) {
        bool flag = true;
        for(int j = 2; j * j < i; j ++) {
            if(i % j == 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << i;
            break;
        }
    }
    return 0;
}
输出结果是：100003
*/
const int N = 100003;
int h[N], e[N], ne[N], idx;
void insert(int x) {
    int k = (x % N + N) % N;//先进行映射
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx ++;
}
bool find(int x) {
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i]) {
        if(e[i] == x)
            return true;
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    //先把h[N]中所有元素都先指向空（也就是我们规定的-1)
    memset(h, -1, sizeof h);
    while(n -- ) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(*op == 'Q') {
            if(find(x)) puts("Yes");//
            else puts("No");
        }
        else insert(x);
    }
    return 0;
}