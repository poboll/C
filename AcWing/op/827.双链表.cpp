/*双链表
实现一个双链表，双链表初始为空，支持5种操作：
在最左侧插入一个数；
在最右侧插入一个数；
将第 k个插入的数删除；
在 第 k个插入的数左侧插入一个数；
在第 k个插入的数右侧插入一个数
现在要对该链表进行 M次操作，进行完所有操作后，从左到右输出整个链表。
注意:题目中第 k个插入的数并不是指当前链表的第 k 个数。例如操作过程中一共插入了 n 个数，则按照插入的时间顺序，这 n 个数依次为：第 1 个插入的数，第 2 个插入的数，…第 n个插入的数。
输入格式
第一行包含整数 M，表示操作次数。接下来 M行，每行包含一个操作命令，操作命令可能为以下几种：
L x，表示在链表的最左端插入数 x。
R x，表示在链表的最右端插入数 x。
D k，表示将第 k个插入的数删除。
IL k x，表示在第 k个插入的数左侧插入一个数。
IR k x，表示在第 k个插入的数右侧插入一个数。
输出格式
共一行，将整个链表从左到右输出。
数据范围
1≤M≤100000
所有操作保证合法。
输入样例：
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2
输出样例：
8 7 7 3 2 9
*/
/*思路：
开三个数组
e[]用来存储数值
l[]用来存储前驱（左边数的下标）
r[]用来存储后继（右边数的下标）
idx用来记录当前下标
定义几个函数然后调用函数接着就ac了~*/
#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
int e[N],r[N],l[N],idx;
//e用来存储数值，l[]用来存储前驱（左边数的下标），r[]用来存储后继（右边数的下标），idx用来记录当前下标
void init() {//初始化
    //0是左端点，1是右端点 
    r[0]=1;
    l[0]=0;
    idx=2;
} 
void add_to_right(int k,int x) {//在k右边插入x
    e[idx]=x;//将x存入当前下标的数值数组中 
    r[idx]=r[k];//当前下标的后继为k的后继 
    l[idx]=k;//当前下标的前驱为k 
    l[r[k]]=idx;//k的后继节点的前驱为idx 
    r[k]=idx++; //k的后继节点为idx； idx++； 
} 
void add_to_left(int k,int x) {//在k的左边插入x 
  	add_to_right(l[k],x);//等价于在k的前驱的右边插入x 
}
void remove(int k)  {//删除第k个结点
  	r[l[k]]=r[k];//k的前驱的后继为k的后继
	  l[r[k]]=l[k];//k的后继的前驱为k的前驱 
}   
void add_to_head(int x ) {//在链表的最左端插入数x
   	add_to_right(0,x);//在0的后面插入x 
} 
void add_to_tail(int x)	{//在链表的最右端插入数x
		add_to_right(l[1],x);
} 
int main() {
		int m;
		init();
		scanf("%d",&m);
		while(m--) {
        string c;
        cin>>c;
        if(c=="L") {
            int x;
            scanf("%d",&x);
            add_to_head(x);
        }else if(c=="R") {
            int x;
            scanf("%d",&x);
            add_to_tail(x);
        }else if(c=="D") {
            int k;
            scanf("%d",&k);
            remove(k+1);
        }else if(c=="IL") {
            int k,x;
            scanf("%d%d",&k,&x);
            add_to_left(k+1,x);
        }else {
            int k,x;
            scanf("%d%d",&k,&x);
            add_to_right(k+1,x);
        }
    } 
    for(int i=r[0];i!=1;i=r[i]) {
        printf("%d ",e[i]);
    }
    printf("\n");
    return 0;
} 