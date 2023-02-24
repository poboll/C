/*835.Tire字符串统计
维护一个字符串集合，支持两种操作：
I x 向集合中插入一个字符串 x；
Q x 询问一个字符串在集合中出现了多少次。
共有 N 个操作，输入的字符串总长度不超过 105，字符串仅包含小写英文字母。
输入格式
第一行包含整数 N，表示操作数。
接下来 N 行，每行包含一个操作指令，指令为 I x 或 Q x 中的一种。
输出格式
对于每个询问指令 Q x，都要输出一个整数作为结果，表示 x 在集合中出现的次数。
每个结果占一行。
数据范围
1≤N≤2∗10^4
输入样例：
5
I abc
Q abc
Q ab
I ab
Q ab
输出样例：
1
0
1*/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;
int cnt[N];//存储以下标为结尾的字符串的出现的次数
int son[N][26];//至多有N个字符，即N个结点，每个结点至多有26个子节点
int idx = 0;//用于标识节点的索引，初始值为0，根结点的idx为空
/**
    Trie树,字典树，用于存储和快速查找字符串，一般字符串内容是纯大写字母或者纯小写字母或者数字
**/
//将某个字符串插入到字典树中
void insertStr(char str[]) {
    int p = 0;//根节点的索引
    for(int i = 0; str[i]; i++) {
        int next_idx = str[i] - 'a';//求下一个字符所在的结点的索引
        if(!son[p][next_idx]) son[p][next_idx] = ++idx;//如果下一个字符str[i]不存在,则创建该字符对应的结点，标识idx自增。根节点或者尾节点的idx为0
        p = son[p][next_idx];//更新下一个字符所在节点的索引
    }
    cnt[p]++;//以下标为p结尾的某个字符串
}
int query(char str[]) {
    int p = 0;
    for(int i= 0; str[i]; i++) {
        int next_idx = str[i] - 'a';//求下一个字符所在的结点的索引
        if(!son[p][next_idx]) return 0;//如果当前字符不存在，则直接返回
        p = son[p][next_idx];//更新下一个字符所在节点的索引
    }
    return cnt[p];//返回以p标识的结点为结尾的字符串 出现的次数
}
int main() {
    int n;
    cin >> n;
    while( n -- ) {
        char op[2], str[N];
        scanf("%s%s", op, str);
        if(op[0] == 'I')  insertStr(str);
        else cout << query(str) << endl;
    }
    return 0;
}