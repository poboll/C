/*837.连通块中点的数量
给定一个包含 n 个点（编号为 1∼n）的无向图，初始时图中没有边。
现在要进行 m 个操作，操作共有三种：
C a b，在点 a 和点 b 之间连一条边，a 和 b 可能相等；
Q1 a b，询问点 a 和点 b 是否在同一个连通块中，a 和 b 可能相等；
Q2 a，询问点 a 所在连通块中点的数量；
输入格式
第一行输入整数 n 和 m。
接下来 m 行，每行包含一个操作指令，指令为 C a b，Q1 a b 或 Q2 a 中的一种。
输出格式
对于每个询问指令 Q1 a b，如果 a 和 b 在同一个连通块中，则输出 Yes，否则输出 No。
对于每个询问指令 Q2 a，输出一个整数表示点 a 所在连通块中点的数量
每个结果占一行。
数据范围
1≤n,m≤105
输入样例：
5 5
C 1 2
Q1 1 2
Q2 1
C 2 5
Q2 5
输出样例：
Yes
2
3*/
#include <iostream>
using namespace std;
const int N = 100010;
int p[N], cnt[N];//父节点数组p[] 集合/连通块的元素个数数组cnt[]
//查找某个元素的所在集合，即返回所在集合的根节点的值，路径压缩优化
int find(int x) {
    if(p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main() {
    //优化输入
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    //初始化并查集的p数组
    for(int i = 1; i <= n; i++)
        p[i] = i, cnt[i] = 1;//每个集合或者说连通块的初始元素个数为1
    while(m --) {
        char op[5];
        scanf("%s", op);
        int a, b;
        if(op[0] == 'C') {
            scanf("%d%d", &a, &b);
            int pa = find(a);//a所在连通块的根节点的值
            int pb = find(b);//b所在连通块的根节点的值
            if(pa != pb)//如果a和b不在同一个连通块/集合
            {
                p[pa] = pb;//将a所在集合合并到b所在的集合
                cnt[pb] += cnt[pa];//b所在连通块/集合的元素个数 += b所在连通块/集合的元素个数
            }
        }
        else if(op[1] =='1') {
            scanf("%d%d", &a, &b);
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else if(op[1] == '2') {
            scanf("%d", &a);
            cout<<cnt[find(a)]<<endl;//输出a所在连通块/集合的元素个数
        }
    }
    return 0;
}