//采用开放寻址法
#include<cstring>
#include<iostream>
using namespace std;
//我们哈希表的存储应尽可能采用质数
//因此这里我们需要找一个比比200000大的最小质数
/*int main() {
    for(int i = 200000;;i++) {
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
输出结果为：200003
*/
const int N = 200003,null = 0x3f3f3f3f;
//相对于拉链法的优势就是只需要一个数组
int h[N];
//核心操作就是这个find函数
/*find函数的作用是，如果映射的k对应的h[k]上没有的别的元素占领（包括自己）
就return k，此时表示我应该插入的k值
*/
/*
如果映射的k对应的h[k]上就是x自己，则此时return k的意义就是获取x在h[]数组中的位置
*/
/*
如果映射的k对应的h[k]上占领的不是自己，并且h[k]不是空的
表明此时是其他人已经占领了k，所以我们需要找下一个坑
所以k++一直往下找，知道找到合适的
*/
int find(int x) {
    int k = (x % N + N) % N;
    while(h[k] != null && h[k] != x) {
        k ++;
        if(k == N) k = 0;
    }
    
    return k;
}
int main() {
    int n;
    cin >> n;
    //先把h[N]中所有元素都先指向0x3f（h中是int，四个字节，组合起来的ox3f3f3f3f就是我们定义的无穷值null)
    memset(h, 0x3f, sizeof h);
    while(n -- ) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(*op == 'I') {
            h[find(x)] = x;
        }
        else {
            if(h[find(x)]==null) puts("No");//puts自带换行输出
            else puts("Yes");
        }
    }
    return 0;
}
