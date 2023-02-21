/*826.单链表
实现一个单链表，链表初始为空，支持三种操作：
向链表头插入一个数；
删除第 k个插入的数后面的数；
在第 k个插入的数后插入一个数。
现在要对该链表进行 M次操作，进行完所有操作后，从头到尾输出整个链表。
注意:题目中第 k个插入的数并不是指当前链表的第 k 个数。例如操作过程中一共插入了 n 个数，则按照插入的时间顺序，这 n 个数依次为：第 1 个插入的数，第 2 个插入的数，…第 n 个插入的数。
输入格式
第一行包含整数 M，表示操作次数。
接下来 M行，每行包含一个操作命令，操作命令可能为以下几种：
    H x，表示向链表头插入一个数 x。
    D k，表示删除第 k个插入的数后面的数（当 k 为 0时，表示删除头结点）。
    I k x，表示在第 k
个插入的数后面插入一个数 x（此操作中 k 均大于 0）。
输出格式
共一行，将整个链表从头到尾输出。
数据范围
1≤M≤100000
所有操作保证合法。
输入样例：
10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 4 5
I 3 4
D 6
输出样例：
6 4 6 5
*/
/*基本思想：
①将一个数x插到现有头结点之前
②将一个数x插到下标为k的数的后面一位
③删除一个节点
思路
用 a 数组代表数据域 ，然后 ne 数存储的是指针域。
创建一个链表即创建一个头指针，head = -1；
然后存储的数据个数是 idx 初始化即为 0 ；
插入操作即将第 k 和数据后面插入一个 x : 首先创建节点 a[idx] = x ; 然后将指针指向k后面的节点 ne[idx] = ne[k] ;
k 的指针再指向新的节点 ne[k] = idx ++ (加一是因为这样就不用再写一个idx++);
删除操作，因为是静态链表，不需要释放资源，直接将的要删除的数的前一个指针指向后一个，ne[k] = ne[ne[k]];
如果是头指针即 head = ne[haed];
头插：类似于插入只是将 j 换成了head ,创建节点： a[idx] = x;
指针指向头指针指向的数据ne[idx] = head ,头指针指向head = idx++;*/
#include<iostream>
using namespace std;
const int N = 100010;
//单链表
int e[N];   //存值
int ne[N];  //存下一个结点的索引
int idx;    //当前可以用的索引号
int head = -1;   //头指针,描述第一个结点的索引,-1表示单链表结尾，初始化时链表为空，所有head指向tail=-1
/**
 * 功能：向链表头插入一个数
 * @param x
 */
void add_to_head(int x) {
    /*四步法
     1、存值
     2、将头指针指向的结点标识为下一个结点
     3、将头指针指向当前结点
     4、idx++准备下一个可用的索引号
    */
    e[idx] = x, ne[idx] = head, head = idx++;
}
/**
 * 功能：将x插到下标是k的点后面
 * @param k
 * @param x
 */
void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}
/**
 * 功能：将下标是k的点后面的点删掉
 * 比如想删除第k个结点，那么需要传入k-1,因为k-1的下一个结点才是k
 * @param k
 */
void remove(int k) {
    ne[k] = ne[ne[k]];
}
int main() {
    //优化输入
    ios::sync_with_stdio(false);
    //m次操作
    int m;
    cin >> m;
    while (m--) {
        int k, x;
        char op;
        cin >> op;
        //头插法:x
        if (op == 'H') {
            cin >> x;
            add_to_head(x);
        } else if (op == 'D') {
            //表示删除第k个插入的数后面的数（当k为0时，示删除头结点）。
            cin >> k;
            //删除头结点需要特判，否则会丢失关系
            if (k == 0) head = ne[head];
                //第k个插入的数，那么在数组中下标是k-1,所以调用时需要使用remove(k-1,x)
            else remove(k - 1);
        } else {
            //在第k个插入的数后插入一个数
            cin >> k >> x;
            //第k个插入的数，那么在数组中下标是k-1,所以调用时需要使用add(k-1,x)
            add(k - 1, x);
        }
    }
    //遍历单链表
    for (int i = head; i != -1; i = ne[i])cout << e[i] << " ";
    return 0;
}