/*868.筛质数
给定一个正整数 n，请你求出 1∼n中质数的个数。
输入格式
共一行，包含整数 n。
输出格式
共一行，包含一个整数，表示 1∼n中质数的个数。
数据范围
1≤n≤10^6
输入样例：
8
输出样例：
4*/
/*分析
分为两种
朴素的筛法（埃式筛法）：找到一个质数，然后把1-n内该质数的所有倍数都筛掉
线性筛法（欧拉筛）：原理暂时不懂，和某个合数的最小质因子有关*/
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int ctn;
bool st[N];
void get_primes(int n) {
	for(int i = 2; i <= n; i ++) {
		if(!st[i]) ctn++; // i是质数
		for(int j = i; j <= n; j += i) st[j] = true; // 删数
	}
}
int main() {
	int n;
	scanf("%d", &n);
	get_primes(n);
	printf("%d", ctn);
}