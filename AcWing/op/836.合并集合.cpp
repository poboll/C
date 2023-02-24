/*836.合并集合
一共有 n 个数，编号是 1∼n，最开始每个数各自在一个集合中。
现在要进行 m 个操作，操作共有两种：
M a b，将编号为 aa 和 bb 的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
Q a b，询问编号为 aa 和 bb 的两个数是否在同一个集合中；
输入格式
第一行输入整数 n 和 m。
接下来 m 行，每行包含一个操作指令，指令为 M a b 或 Q a b 中的一种。
输出格式
对于每个询问指令 Q a b，都要输出一个结果，如果 aa 和 bb 在同一集合内，则输出 Yes，否则输出 No。
每个结果占一行。
数据范围
1≤n, m≤105
输入样例：
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
输出样例：
Yes
No
Yes
*/
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N]; // 当前节点的父节点；
// 该函数的含义：查找a所在集合的祖先节点下标，从1开始, 并内部更新p[a]为a节点的祖先节点。
int find(int a) {
    // 根据通项公式，假设p[a]的祖先节点已知。
    if (p[a] != a) p[a] = find(p[a]);
    return p[a];
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // 初始化每个集合
    for (int i = 1; i <= n; i++) p[i] = i;
    int a, b;
    char op[2];
    while (m -- ) {
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'M') p[find(a)] = find(b);
        else {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}