/*839.模拟堆
维护一个集合，初始时集合为空，支持如下几种操作：
I x，插入一个数 x；
PM，输出当前集合中的最小值；
DM，删除当前集合中的最小值（数据保证此时的最小值唯一）；
D k，删除第 k 个插入的数；
C k x，修改第 k 个插入的数，将其变为 x；
现在要进行 N 次操作，对于所有第 2 个操作，输出当前集合的最小值。
输入格式
第一行包含整数 N。
接下来 N 行，每行包含一个操作指令，操作指令为 I x，PM，DM，D k 或 C k x 中的一种。
输出格式
对于每个输出指令 PM，输出一个结果，表示当前集合中的最小值。
每个结果占一行。
数据范围
1≤N≤105
−109≤x≤109
数据保证合法。
输入样例：
8
I -10
PM
I -10
D 1
C 2 8
I 6
PM
DM
输出样例：
-10
6*/
//这里ph数组存储结点下标，hp数组存储idx
//这俩数组的意义是维护结点下标与idx的一一对应关系
//size_：1堆结点数量2堆结点下标
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int h[N],hp[N],ph[N],heap_size = 0;//hp,ph数组元素个数相同，同时等于堆中结点数
//h[]是堆本身，这边假设一个集合p和堆中每个节点存在一一对应关系，即存在映射
//hp则是h to p，利用h中的节点，找到对应p集合中对应的数，ph同理，也可以将ph和hp理解为互相保存对方地址的集合
void heap_swap(int a, int b) {//a，b是堆数组下标，也就是位置，真正交换的是位置中的值
    swap(ph[hp[a]],ph[hp[b]]);//首先要交换p指向h的位置，因为hp要用于索引hp数组，是根基，所以不能先改，参考双向链表删除结点
    swap(hp[a], hp[b]);//其次交换h指向p的位置
    swap(h[a], h[b]);//最后交换两个节点的位置
}
void down(int u) {//同838的笔记
    int t = u;
    if(u * 2 <= heap_size && h[u * 2] < h[t])
    t = u * 2;
    if(u * 2 + 1 <= heap_size && h[u * 2 + 1] < h[t])
    t = u * 2 + 1;
    if(u != t) {
        heap_swap(u, t);
        down(t);
    }
}
void up(int u) {//up函数中u位置结点只与其父节点比较，也可以用一个if语句
    while(u / 2 && h[u / 2] > h[u]) {//同838的笔记
        heap_swap(u / 2, u);
        u /= 2;;//一直递归上浮这个值，直到找到合适位置
        //这里u内的值(下沉过来的值)变大为什么不用递归down(u)?????
    }
}
int main() {
    int n, m = 0;
    cin >> n;
    while(n -- ) {
        string op;
        int k, x;
        cin >> op;
        if(op == "I") {
            scanf("%d", &x);
            heap_size ++;
            m ++;//节点对应的地址形成
            ph[m] = heap_size,hp[heap_size] = m;//绑定互相指的指针
            h[heap_size] = x;//给值
            up(heap_size);//入堆，因为向下没有路，所以只能上浮调整位置
        }
        else if(op == "PM")
        printf("%d\n",h[1]);
        else if(op == "DM") {//理同838
            heap_swap(1,heap_size);
            heap_size--;
            down(1);
        }
        else if(op == "D") {
            scanf("%d", &k);
            //需要先找到与k对应的堆结点
            int u = ph[k];//找个临时值保存对应位置的指针,相当于idx
            //h[ph[k]]=h[size_--];这种法子不能用了，因为有了附属信息（ph，hp）交换时需要改变它们
            heap_swap(u, heap_size);//把对应的值移到最后面去，值交换后值的下标（位置）改变，值也就是第几个插入的数
            heap_size -- ;//相当于删掉最后一个叶子节点
            up(u);
            down(u);//up和down都要进行一次是因为有可能被替换到中间层
        }
        else if(op == "C") {
            scanf("%d%d", &k, &x);
            h[ph[k]]=x; 
            down(ph[k]);//涉及不到heap_swap的内容，所以可以直接传ph的值进行操作
            up(ph[k]);
        }
    }
    return 0;
}