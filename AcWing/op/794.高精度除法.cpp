/*794.高精度除法
给定两个非负整数（不含前导 00） A，BA，B，请你计算 A/BA/B 的商和余数。
输入格式
共两行，第一行包含整数 AA，第二行包含整数 BB。
输出格式
共两行，第一行输出所求的商，第二行输出所求余数。
数据范围
1≤A的长度≤1000001≤A的长度≤100000,
1≤B≤100001≤B≤10000,
BB 一定不为 00
输入样例：
7
2
输出样例：
3
1
*/
/*思路
按照除法的法则
设置余数r
r一开始初始化为0
由于除法是从高位开始计算的 所以结果也是从高位开始存储的（结果需要反转）
r = r * 10 + Ai
商就是r / 10
反而余数r = r % 10 对于下一个A[i]进行计算*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//A/b   商是c，余数r
vector<int> div(vector<int> &A,int b, int &r)//r是引用
{
    vector<int> C; //商是C，用vector<int>型存储商
    r =0;//r控制每次计算的余数
    for(int i =A.size()-1; i>=0; i--)//除法运算过程
    {
        r= r* 10+A[i];//余数*10+下一位作为下次被除数
        C.push_back(r/b);//输出商
        r %=b;//计算r下一次运算的值
    }
    reverse(C.begin(),C.end());
    while(C.size()>1 && C.back() ==0) C.pop_back();
    //去掉前导0当商为1时不去除即C.size()>1
    return C;
}
int main()
{
    string a;//高精度数a存为字符串
    int b;//较小数b
    cin >>a >> b;//输入两数
    vector<int> A;//定义数组A
    for(int i =a.size() -1; i>=0; i--) 
        A.push_back(a[i]-'0');//在A数组中正序添加高精度数a
    int r;
    auto C = div(A,b,r);//调用函数计算商
    for(int i =C.size() -1;i>=0;i--) 
        printf("%d",C[i]);
    cout << endl << r <<endl;//输出余数r
    return 0;
}