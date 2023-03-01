/*C++STL-string
deque, 双端队列
    size()
    empty()
    clear()
    front()/back() 返回第一个元素/返回最后一个函数
    push_back()/pop_back() 最后插入/弹出最后
    push_front()/pop_front() 队首插入元素/队首弹出元素
    begin()/end()
    [] 随机寻址*/
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
    //常用函数
    cout << a.substr(1, 10) << endl;//输出到最后一个字母为止
    //返回从一开始的子串
    cout << a.substr(1) << endl;
    //a存储地址的字符地址
    printf("%s\n", a.c_str());
    return 0;
}