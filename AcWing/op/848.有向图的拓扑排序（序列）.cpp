/*848.有向图的拓扑排序（序列）
给定一个 n 个点 m 条边的有向图，点的编号是 1 到 n，图中可能存在重边和自环。
请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 −1。
若一个由图中所有点构成的序列 A 满足：对于图中的每条边 (x,y)，x 在 A 中都出现在 y 之前，则称 A 是该图的一个拓扑序列。
输入格式
第一行包含两个整数 n和 m。
接下来 m 行，每行包含两个整数 x 和 y，表示存在一条从点 x 到点 y的有向边 (x,y)。
输出格式
共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。
否则输出 −1。
数据范围
1≤n, m≤10^5
输入样例：
3 3
1 2
2 3
1 3
输出样例：
1 2 3
*/
/*这里考虑入度(几条边指向自己)，出度(几条边指出)。
首先思考，如果无环图即满足拓扑排序，是否可以将该节点的所有 出边 删去，结果使得每个节点的入度是0，满足入度是0，则将其存储起来。
如果存在环，一定存环上的点入度不是0.
所以可以将结点的出边删除，下个节点的入度减减。*/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;
int e[N], ne[N], h[N], idx;//用于创建邻接表
int n, m;
int d[N];//记录每个节点的入度
int q[N];//记录拓扑序列
void add(int a,int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
bool topsort() {
    int hh = 0, tt = -1;//因为此时没有放入任何节点所以tt=-1
    for(int i = 1; i <= n; i ++)//将所有入度为0的点放入队列
        if(d[i] == 0)   q[++ tt] = i;
    while(hh <= tt) {
        int t = q[hh ++];//取出队头元素
        for(int i = h[t]; i != -1; i = ne[i]) {//找队头元素的出边j
            int j = e[i];
            d[j] --;//j的入度--
            if(d[j] == 0)   q[++ tt] = j;//j的入度--为0时加入队列
        }
    }
    return tt == n - 1; //当tt=n-1时，所有点都入队了表示没有环，返回true
}
int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int a,b;
        cin >> a >> b;
        add(a, b);
        d[b]++;//节点b的入度+1
        //不要对d数组进行初始化，因为d是全局变量，会自动初始化为0
    }
    if(topsort()) {//有拓扑序列则输出顺序
        for(int i = 0; i < n; i ++)
            cout << q[i] << " ";
    } else {
        puts("-1");
    }
    return 0;
}
