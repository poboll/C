/*C++STL
vector, 变长数组, 倍增的思想
    size() 返回数组元素个数
    empty() 是否为空
    clear() 清空
string, 字符串, substr(), c_str()
queue, 队列, push(), front(), top(), pop()
priority_queue, 优先队列, push(), top(), pop()
stack, 栈, push(), top(), pop()
deque, 双端队列
set, map, multiset, multimap, 基于平衡二叉树（红黑树），动态维护有序序列
unordered_set, unordered_map, unordered_multise, unordered_multimap, 哈希表
bitset, 压位*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<int> a(10, 3);//初始化长度为10的数组
    for (auto x : a) cout << x << endl;
    return 0;
}