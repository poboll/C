/*840.模拟散列表

*/
//先采用拉链法
#include<cstring>
#include<iostream>
using namespace std;
//我们哈希表的存储应尽可能采用质数
//因此这里我们需要找一个比比100000大的最小质数
/*int main()
{
    for(int i = 100000; ;i++) {
        bool flag = true;
        for(int j = 2; j * j < i; j ++) {
            if(i % j == 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << i;
            break;
        }
    }
    return 0;
}
输出结果是：100003
*/
const int N = 100003;
int h[N], e[N], ne[N], idx;
void insert(int x) {
    int k = (x%N+N)%N;//先进行映射
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}
bool find(int x) {
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i]) {
        if(e[i] == x)
            return true;
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    //先把h[N]中所有元素都先指向空（也就是我们规定的-1)
    memset(h,-1,sizeof h);
    while(n -- ) {
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        if(*op == 'Q') {
            if(find(x)) puts("Yes");//
            else puts("No");
        }
        else insert(x);
    }
    return 0;
}
