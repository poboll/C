/*852.spfa判断负环
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。
请你判断图中是否存在负权回路。
输入格式
第一行包含整数 n 和 m。
接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。
输出格式
如果图中存在负权回路，则输出 Yes，否则输出 No。
数据范围
1≤n≤2000,
1≤m≤10000,
图中涉及边长绝对值均不超过 10000。
输入样例：
3 3
1 2 -1
2 3 4
3 1 -4
输出样例：
Yes*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 2010, M = 10010;
int n, m;
int dist[N], cnt[N];
int h[N], e[M], w[M], ne[M], idx; 
bool st[N];
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
bool spfa() {
    queue<int> q;
    // 把所有的点都放入到队列当中，因为是判断整个图中是否有负权环，所以把所有的点都加入到队列中
    for(int i = 1; i <= n; i++){
        q.push(i);//入队
        st[i] = true;//标记该点已经入队
    } 
    // 宽搜
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];//t的相邻点
            int we = w[i];//边权 
            // 此时的dist数组只用于存储判断是否存在更新为较小的情况，可以不存储实际的距离大小，只用于判断更新之后的大小关系即可
            if(dist[j] > dist[t] + we){
                dist[j] = dist[t] + we;
                // 判断更新之后统计1号点到各个点最短距离经过的边数是否>=n
                // 根据鸽巢原理/抽屉原理，可知n条边的路径上至少有n+1个点，但实际上至多有n个点，则说明一条路径上有相同的两个点，则成环
                // 又因为只有在两点距离被更新成较小的值时才统计1号点到j的最短路径的边数，所以一定是存在负权环才会更新，则以cnt[j] >= n 来判断是否存在负权环
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if(!st[j]) {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    if(spfa())  puts("Yes");
    else puts("No");
    return 0;
}