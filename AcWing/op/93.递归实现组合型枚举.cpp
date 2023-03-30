/*93.递归实现组合型枚举
从 1∼n 这 n 个整数中随机选出 m 个，输出所有可能的选择方案。
输入格式
两个整数 n,m ,在同一行用空格隔开。
输出格式
按照从小到大的顺序输出所有方案，每行 1 个。
首先，同一行内的数升序排列，相邻两个数用一个空格隔开。
其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面（例如 1 3 5 7 排在 1 3 6 8 前面）。
数据范围
n>0, 0≤m≤n, n+(n−m)≤25
输入样例：
5 3
输出样例：
1 2 3 
1 2 4 
1 2 5 
1 3 4 
1 3 5 
1 4 5 
2 3 4 
2 3 5 
2 4 5 
3 4 5
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 30;
int n,m;
int way[N];
void dfs(int u,int start) {//当前枚举到了哪一个位置、当前最小能够从哪一个数枚举 
	//剪枝 
	if(u + n - start < m) return;//已经选了u-1个数    假设把start到n所有选上(n-start+1)也不够m个数(<m)
	if(u == m + 1) {//表示枚举结束
		for(int i = 1; i <= m; i ++)   out << way[i] << ' ';
		cout << endl;
		return;
	}
	for(int i = start; i <= n; i ++) {
		way[u]=i;
		dfs(u+1,i+1);
		way[u]=0;
	}
}
int main() {
    cin >> n >> m;
    dfs(1, 1);//初始从第1个位置开始枚举、最小能够枚举的数为1 
    return 0;
}