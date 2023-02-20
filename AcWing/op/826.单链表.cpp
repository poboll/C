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
1≤M≤10000*/
/*思路
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
const int N =100010;
int n,m;
int a[N] ,ne[N],idx,head;
void init() {
    head  = -1 ;

}
void head_push(int x) {
    a[idx] = x;
    ne[idx] = head;
    head = idx ++;
}
void add(int k, int x) {
      a[idx] = x;
      ne [idx] = ne[k] ;
      ne[k] = idx ++;
}
void remove (int k) {
    ne[k] = ne [ne[k]];
}
int main() {
    cin>>n;
    init();
    int k,x;
    while(n--) {
        char c ;
        int k,x;
        cin>>c;
        if( c == 'D') {
            cin>>k;
            if ( !k ) head = ne[head];
            else remove(k-1);
        } else if(c == 'H') {
            cin>>x;
            head_push(x);
        }else{
              cin>> k >> x;
            add(k-1,x);
        }
    }
    for (int i = head; i != -1; i = ne[i]) cout << a[i] << ' ';
    return 0;
}