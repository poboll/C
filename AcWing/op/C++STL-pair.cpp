/*C++STL-pair
pair<int, int>
    first, 第一个元素
    second, 第二个元素
    支持比较运算，以first为第一关键字，以second为第二关键字（字典序）
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    //初始化
    pair<int, string>p;
    p = make_pair(10, "yxc");
    p = {20, "abc"};
    //三种属性
    pair<int, pair<int, int>>q;
    return 0;
}