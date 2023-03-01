/*C++STL-priority_queue
priority_queue, 优先队列，默认是大根堆
    size()
    empty()
    push()  插入一个元素
    top()  返回堆顶元素
    pop()  弹出堆顶元素
    定义成小根堆的方式：priority_queue<int, vector<int>, greater<int>> q;
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
    priority_queue<int> heap1;//默认大跟堆
    //小根堆从小到大排序：负数
    int x;
    heap1.push(-x);
    //定义时直接定义小根堆：多定义两个参数
    priority_queue<int, vector<int>, greater<int>> heap2;
    return 0;
}