/*791.高精度加法
给定两个正整数（不含前导0），计算它们的和。
输入格式
共两行，每行包含一个整数。
输出格式
共一行，包含所求的和。
数据范围
1≤整数长度≤100000
输入样例：
12
23
输出样例：
35
*/
/*vector是一种顺序容器，事实上和数组差不多，但它比数组更优越。一般来说数组不能动态拓展，因此在程序运行的时候不是浪费内存，就是造成越界。而vector正好弥补了这个缺陷，它的特征是相当于可分配拓展的数组，它的随机访问快，在中间插入和删除慢，但在末端插入和删除快，而且如果你用.at()访问的话，也可以做越界检查。
v.push_back(t)  //在数组的最后添加一个值为t的数据
v.size()   //当前使用数据的大小
v.pop_back();  // 弹出容器中最后一个元素（容器必须非空）
v.back();   // 返回容器中最后一个元素的引用
*/
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
// C = A + B
vector<int> add(vector<int> &A, vector<int> &B) {//C++11新特性  添加引用-->提高效率
    vector<int> C;//定义数组C存两数之和
    int t = 0;//上一位的进位
    for (int i = 0; i < A.size() || B.size(); i ++) {
        if (i < A.size()) t += A[i];//按位做加法
        if (i < B.size()) t += B[i];//B的高位全加进去
        C.push_back(t % 10);//t存储该位a，b和模10即为结果
        t /= 10;//t存储进位为0或1
    }
    if (t) C.push_back(1);//最高位进位1
    return C;
}
int main() {
    string a, b;//定义字符串a，b
    vector<int> A, B;//定义数组A,B
    cin >> a >> b; //输入两个数a，b    a = "123456"
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');// A = [6, 5, 4, 3, 2, 1]  把字符串中字符变为整型数字并逆序存入数组
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');
    auto C = add(A , B);//调用函数，返回和存入数组C。auto编译器自己推断类型等价于 vector<int> C
    for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);//遍历输出C中元素即为两数和
    return 0;
}