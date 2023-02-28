/*C++STL-string
string，字符串
    size()/length()  返回字符串长度
    empty() 返回字符串是否为空
    clear() 清空字符串
    substr(起始下标，(子串长度))  返回子串
    c_str()  返回字符串所在字符数组的起始地址*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string a = "yxc";
    a += "def";
    a += 'C';
    cout << a << endl;
    return 0;
}