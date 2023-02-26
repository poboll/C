/*838.堆排序
输入一个长度为 n 的整数数列，从小到大输出前 m 小的数。
输入格式
第一行包含整数 n 和 m。
第二行包含 n 个整数，表示整数数列。
输出格式
共一行，包含 m 个整数，表示整数数列中前 m 小的数。
数据范围
1≤m≤n≤10^5，
1≤数列中元素≤10^9
输入样例：
5 3
4 5 1 3 2
输出样例：
1 2 3
*/
/*思路：
堆的常用操作：
1.插入一个数 h[++size] = num; up(size);
2.求集合当中的最小值 h[1];
3.删除最小值 h[1] = h[size];size--; down(1);
4.删除任意一个元素 h[k] = h[size]; size--; down(k), up(k);//down和up都执行一遍，只会执行一种，就不用判断再执行，方便代码编写和记忆
5.修改任意一个元素 h[k] = num; down(k), up(k); //down和up都执行一遍，只会执行一种，就不用判断再执行，方便代码编写和记忆*/
#include <iostream>
using namespace std;
const int N = 100010;
int h[N], cnt; 
//数组存储堆的节点，下标从1开始, 节点x的左孩子节点下标为2x,右孩子节点下标为2x+1
//如果下标从0开始，节点x的左孩子节点下标为2x+1,右孩子节点下标为2x+2
//down操作，对堆中下标为u的元素进行一次重新排序
//down的核心思路是节点x,节点2x，节点2x+1进行交换位置，保证三个值中最小值在父节点位置
void down(int u)
{
    int t = u;
    if(u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if(u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if(t != u)
    {
        swap(h[u], h[t]);
        down(t);
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    cnt = n;//堆的节点个数，即序列元素总个数
    for(int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    //生成小根堆,时间复杂度大约是O(n), 从n/2处的节点开始往上遍历节点，并逐一执行down(i)操作,每次down或者up操作跟二叉树的层数成正比，每次操作的时间复杂度为logN
    for(int i = n/2; i; i--)
        down(i);
    while(m --) {
        printf("%d ",&h[1]);
        h[1] = h[cnt];
        cnt -- ;//堆元素个数自减
        down(1);//将交换后的堆顶元素down重新排序成小根堆
    }
    return 0;
}