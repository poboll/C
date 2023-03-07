/*846.树的重心
给定一颗树，树中包含n个结点（编号1~n）和n-1条无向边。
请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。
重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。
输入格式
第一行包含整数n，表示树的结点数。
接下来n-1行，每行包含两个整数a和b，表示点a和点b之前存在一条边。
输出格式
输出一个整数m，表示重心的所有的子树中最大的子树的结点数目。
数据范围
1≤n≤10^5
输入样例
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
输出样例：
4*/
/*树作为一种递归的数据结构，树的问题十有八九也是用递归方式来解决的。从某种意义上说，dfs与递归的界限并没有那么明显，所以在对树进行深度优先遍历时，往往能够顺便求解很多问题。
首先，分析下本题的存储，普通的树，是特殊的图，而且是稀疏图，所以使用邻接表来存储。邻接表的实现可以采用vector加上结构体的形式，较为简洁，但是用数组实现效率更高。我们用h[i]表示编号为i节点的第一条边的序号，边的编号用idx表示，用e[idx]数组存储第idx条边指向节点的编号，用ne[i]表示下一条边的序号。下面实现给从节点a到b添加一条边的操作。
void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
用文字描述下加边的过程就是，e[idx]=b;//第idx条边指向b节点，ne[idx]=h[a];//第idx条边下一条边的序号是a节点原来第一条边的序号，h[a]=idx++;//a节点的第一条边的序号为idx（也就是a->b这条边）,如果需要加上权重的话，在之前加上w[idx]=c;即可。上面的代码也就是单链表的头插法的操作，为啥要用头插法，如果采取尾插法的话还要存储a节点指向最后一条边的序号，比较麻烦。对于树，直接当成无向图处理，每条边双向添加即可。
要想找到树的重心，需要知道去掉某节点后剩下连通块中节点的数量，对于某个节点u，以u为根节点的子树的节点总数为x，则其父节点（若存在）所在连通块节点的数目为n-x。要求以某节点为根节点子树的节点的个数，只需要递归的求以其孩子节点为根节点子树的总和即可。设int dfs(int u)这个函数能够实现该功能，则想要统计u所有子树节点之和，只需要int sum = 0；u的孩子节点比如有a，b，sum + dfs(a)+dfs(b) + 1即是u所在子树节点的总和了，同时，还可以求各个连通块节点的最大值，找到树的重心。*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005, maxm = 2 * maxn;
int n, h[maxn], e[maxm], ne[maxm], idx;
int ans = maxn;
bool st[maxn];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs(int u) {
    st[u] = true;//已经访问过，防止重复遍历父节点
    int size = 0, sum = 0;
    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if(st[j])   continue;//不用遍历父节点
        int s = dfs(j);
        size = max(size, s);//更新连通块的最值
        sum += s;//加上孩子节点的个数
    }
    size = max(size, n - sum - 1);//再次与父节点所在的连通块比较最值
    ans = min(ans, size);//找到最小连通块个数
    return sum + 1;
}
int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}