//G 子串简写
//题目描述
//程序猿圈子里正在流行一种很新的简写方法：对于一个字符串，只保留首尾字符，将首尾字符之间的所有字符用这部分的长度代替。例如 internation-alization 简写成 i18n，Kubernetes （注意连字符不是字符串的一部分）简写成 K8s, Lanqiao 简写成 L5o 等。
//在本题中，我们规定长度大于等于 K 的字符串都可以采用这种简写方法（长度小于 K 的字符串不配使用这种简写）。
//给定一个字符串 S 和两个字符 c1 和 c2，请你计算 S 有多少个以 c1 开头c2 结尾的子串可以采用这种简写？
//输入格式
//第一行包含一个整数 K。
//第二行包含一个字符串 S 和两个字符 c1 和 c2。
//输出格式
//一个整数代表答案。
//样例输入
//4
//abababdb a b
//样例输出
//6
//提示
//符合条件的子串如下所示，中括号内是该子串：
//
//[abab]abdb
//[ababab]db
//[abababdb]
//ab[abab]db
//ab[ababdb]
//abab[abdb]
//对于 20% 的数据，2 ≤ K ≤ |S | ≤ 10000。
//对于 100% 的数据，2 ≤ K ≤ |S | ≤ 5 × 105。S 只包含小写字母。c1 和 c2 都是小写字母。
//|S | 代表字符串 S 的长度。
// 超时！！！！！
//#include <stdio.h>
//#include <string.h>
//int main() {
//	int k, l, r, ans = 0;
//	char c1, c2;
//	char s[10010];
//	scanf("%d", &k);
//	scanf("%s", &s);
//	scanf(" %c %c", &c1, &c2);
//	for (l = 0; l <= strlen(s) - 4; l++)
//	{
//		if (s[l] != c1)
//			continue;
//		for (r = l + k - 1; r <= strlen(s) - 1; r++)
//		{
//			if (s[l] != c1)
//				break;
//			if (s[r] != c2)
//				continue;
//			if (s[l] == c1 && s[r] == c2 && r - l >= k - 1)
//			{
//				ans++;
//			}
//		}
//	}
//	printf("%d", ans);
//	return 0;
//}

// 找末尾c2前面有几个符合条件的c1
#include <iostream>
using namespace std;
int main() {
	int k, ans = 0, n = 0;
	char c1, c2;
	string s;
	scanf("%d", &k);
	cin >> s;
	scanf("%c %c", &c1, &c2);
	for(int i = 0; i < s.length(); ++ i ) {
		if(i - k + 1 >= 0 && s[i-k+1] == c1) {
			n ++;
		}
		if(s[i] == c2) {
			ans += n;
		}
	}
	printf("%d", ans);
	return 0;
}
