#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
string s;
int p[N], n, m, x, y;
int find(int x) {//查找集合与路径压缩
    if(p[x] != x) return p[x] = find(p[x]);
    return x;
}
int main() {
    scanf("%d%d", &n,  &m);
    for(int i = 1; i <= n; ++i)  p[i] = i;
    while(m -- ) {
        cin >> s;
        scanf("%d%d", &x, &y);
        if(s == "M") p[find(x)] = find(y); //一定要用父节点合并这样才能保证根节点唯一
        else printf("%s\n", find(x) == find(y) ? "Yes":"No");
    }
    return 0;
}