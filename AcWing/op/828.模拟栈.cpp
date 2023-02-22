/*828.模拟栈
实现一个栈，栈初始为空，支持四种操作：
1. push x – 向栈顶插入一个数 x；
2. pop – 从栈顶弹出一个数；
3. empty – 判断栈是否为空；
4. query – 查询栈顶元素。
现在要对栈进行 M 个操作，其中的每个操作 3 和操作 4都要输出相应的结果。
输入格式
第一行包含整数 M，表示操作次数。
接下来 M 行，每行包含一个操作命令，操作命令为 push x，pop，empty，query 中的一种。
输出格式
对于每个 empty 和 query 操作都要输出一个查询结果，每个结果占一行。
其中，empty 操作的查询结果为 YES 或 NO，query 操作的查询结果为一个整数，表示栈顶元素的值。
数据范围
1≤M≤100000
1≤x≤109
所有操作保证合法。
输入样例：
10
push 5
query
push 6
pop
query
pop
empty
push 4
query
empty
输出样例：
5
5
YES
4
NO
*/
/*用数组模拟实现：
①第一个元素时n == 1
②n是全局变量，初始值为0
③按照题目要求，三四两步最后加回车
*/
/*注意事项：
①第一个元素时n == 1
②n是全局变量，初始值为0
③按照题目要求，三四两步最后加回车*/
#include <iostream>
using namespace std;
const int N=100010;
//tt是栈顶指针
int stk[N],tt;
void push(int x){
    stk[tt]=x;
    tt++;
}
void pop(){
    tt--;
}
bool empty(){
    if(tt==0) return true;
    else return false;
}
int query(){
    if(!empty()) return stk[tt-1];
}
int main(){
    tt=0;
    int m;
    cin>>m;
    string s;
    int x;
    while(m--){
        cin>>s;
        if(s=="push"){
            cin>>x;
            push(x);
        }else if(s=="pop"){
            pop();
        }else if(s=="empty"){
            bool tmp=empty();
            if(tmp) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else{
            cout<<query()<<endl;
        }
    }
    return 0;
}