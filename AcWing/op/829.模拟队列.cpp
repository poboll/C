/*829.模拟队列
实现一个队列，队列初始为空，支持四种操作：
push x – 向队尾插入一个数 x；
pop – 从队头弹出一个数；
empty – 判断队列是否为空；
query – 查询队头元素。
1
2
3
4
现在要对队列进行 M个操作，其中的每个操作 3 和操作 4都要输出相应的结果。
输入格式
第一行包含整数 M，表示操作次数。
接下来 M行，每行包含一个操作命令，操作命令为 push x，pop，empty，query 中的一种。
输出格式
对于每个 empty 和 query 操作都要输出一个查询结果，每个结果占一行。
其中，empty 操作的查询结果为 YES 或NO，query 操作的查询结果为一个整数，表示队头元素的值。
数据范围
1≤M≤100000,
1≤x≤109,
所有操作保证合法。
输入样例：
10
push 6
empty
query
pop
empty
push 3
push 4
pop
query
push 6
1
2
3
4
5
6
7
8
9
10
11
输出样例：
NO
6
YES
4
1
2
3
4
*/
/*思路：
队列：是一个特殊的数组，最前面的叫做队头，最后面的叫做队尾，只允许在队头删除元素，在队尾插入元素。先进先出。
用一个数组q保存数据。
用hh表示队头，q[hh]即队头元素，q[hh+1]即第二个元素。
用tt表示队尾，q[tt]就是队尾元素，q[tt+1]就是下一次入队，元素应该放的位置。
[hh,tt]左闭右闭，代表队列中元素所在的区间。
出队pop：因为hh为队头，[hh,tt]代表元素所在区间。所以出队可以用hh++实现，hh++后，区间变为[hh+1,tt];
入队push：因为tt代表队尾，[hh,tt]代表元素所在区间，所以出队可以用tt++实现，hh++后，区间变为[hh,tt+1]，然后再q[tt+1]位置放入入队元素。
是否为空empty：[hh,tt]代表元素所在区间，当区间非空的时候，队列非空，也就是tt>=hh的时候，队列非空。
询问对头query：用hh代表队头，q[hh]就是队头i元素，返回q[hh]即可。*/
#include<iostream>
using namespace std;
const int N=100010;
//q[]表示队列 hh表示队头 tt表示队尾
int q[N];
int hh=0,tt=-1;//最开始下标为0开始的队列
int main() {
    int m,x;
    string op;
    cin>>m;
    for(int i=0;i<m;i++) {
        cin>>op;
        if(op=="push") {
            cin>>x;
            q[++tt]=x;          //向队列插入元素
        }else if(op=="pop") {
            hh++;              //弹出队头元素
        }else if(op=="query") {
            cout<<q[hh]<<endl;//查询队头元素
        }else {
            if(hh<=tt) {//不为空
                cout<<"NO"<<endl;
            }else {     //为空
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}
