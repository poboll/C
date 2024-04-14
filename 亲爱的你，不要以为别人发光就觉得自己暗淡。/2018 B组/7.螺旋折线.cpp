// G 螺旋折线
// 题目描述：
// 如图p1.png所示的螺旋折线经过平面上所有整点恰好一次。
// 对于整点(X, Y)，我们定义它到原点的距离dis(X, Y)是从原点到(X, Y)的螺旋折线段的长度。
// 例如dis(0, 1)=3, dis(-2, -1)=9
// 给出整点坐标(X, Y)，你能计算出dis(X, Y)吗？
// 分析分析：
// 这个题目初一看，什么鬼？看着向四周发散，我陷入了沉思
// 等等，灵光的闸现，永远就在这一瞬间
// 看看，我们是不是先
// 左 1 上 1
// 右 2 下 2
// 左 3 上 3
// 。。。
// 好家伙，我们要求的也就是第几个点也就是把这个加起来，直接对他进行模拟运就可以了
#include <stdio.h>
int main() {
    // 提前赋值 temp 为点的个数，x 和 y 用来记录它们
    int x1, y1, x2 = 0, y2 = 0, temp = 0, tempx = 1, tempy = 1;
    scanf("%d%d", &x1, &x2);
    // 开始模拟
    for(int i = 1; ; ++ i) {
        // 对于 x 的模拟
        if(tempx % 2 == 1) {
            for(int j = 0; j < i; ++ j) {
                x2 --;
                temp ++;
                if(x1 == x2 && y1 == y2) {
                    goto A;
                }
            }
            tempx ++;
        }else {
            for(int j = 0; j < i; ++ j) {
                x2 ++;
                temp ++;
                if(x1 == x2 && y1 == y2) {
                    goto A;
                }
            }
            tempx ++;
        }
        // 对于 y 的模拟
        if(tempy % 2 == 1) {
            for(int j = 0; j < i; ++ j) {
                y2 ++;
                temp ++;
                if(x1 == x2 && y1 == y2) {
                    goto A;
                }
            }
            tempy ++;
        }else {
            for(int j = 0; j < i; ++ j) {
                y2 --;
                temp ++;
                if(x1 == x2 && y1 == y2) {
                    goto A;
                }
            }
            tempy ++;
        }
    }
A:
    printf("%d", temp);
    return 0;
}
// 1 3
// 34