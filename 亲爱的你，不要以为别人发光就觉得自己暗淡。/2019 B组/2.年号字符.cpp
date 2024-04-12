// B 年号字符
// 题目描述
// 小明用字母 A对应数字 1，B对应 2，以此类推，用 Z对应 26。对于 27以上的数字，小明用两位或更长位的字符串来对应，例如 AA对应27，AB对
// 应28，AZ对应52，LQ对应329。
// 请问2019对应的字符串是什么？
// 分析分析：
// 这个题目我一整个看下来，感受就很直接了，宝，你说的不就是咱们的的进制转化，而且是26进制的，我们以AA为例子，26的0次乘以1，加上26的1次乘以1。啊哈哈哈哈哈哈，just so so 怎么可以难到我们小唐和他的小粉丝呢！（会用stack咱就用stack，主要是证明我会【手动狗头】）
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char b[20]={""};
	int a,temp;
	cin>>a;
	for(int i=0;a>0;i++)
	{
		b[i]='A'+a%26-1;
		a=a/26;
	} 
	for(int i=strlen(b)-1;i>=0;i--)
	{
		cout<<b[i]; // BYQ
	}
}