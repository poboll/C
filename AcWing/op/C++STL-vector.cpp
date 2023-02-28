/*C++STL-vector*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<int> a(10, 3);//初始化长度为10的数组
    for (auto x : a) cout << x << ' ';
    cout << endl;
    vector<int> b;
    for (int i = 0; i < 10; i ++ ) b.push_back(i);
    //1、数组下标遍历
    for (int i = 0; i < b.size(); i ++ ) cout << b[i] << ' ';
    cout << endl;
    //2、vector迭代器遍历
    for (vector<int>::iterator i = b.begin(); i != b.end(); i ++ ) cout << *i <<' ';//b.begin() = b[0], b.end = b[b.size], vector<int>::iterator = auto系统自动推断函数类型
    cout << endl;
    //3、范围遍历(C++11新特性)
    for (auto x : b) cout << x << ' ';
    cout << endl;
    //比较运算：字典序
    vector<int> c(4, 3), d(3, 4);//3333 444前者字典序较小
    if (c < d) puts("c < d");
    return 0;
}