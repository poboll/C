//
// Created by 大妖怪 on 2024/2/7.
//
// P1205[USACO1.2]方块转换Transformations
// 题目描述
// 一块 n * n 正方形的黑白瓦片的图案要被转换成新的正方形图案。写一个程序来找出将原始图案按照以下列转换方法转换成新图案的最小方式：
// - 转 90度：图案按顺时针转 90度。
// - 转 180度：图案按顺时针转 180度。
// - 转 270度：图案按顺时针转 270度。
// - 反射：图案在水平方向翻转（以中央铅垂线为中心形成原图案的镜像）。
// - 组合：图案在水平方向翻转，然后再按照 1 \sim 3 之间的一种再次转换。
// - 不改变：原图案不改变。
// - 无效转换：无法用以上方法得到新图案。
// 如果有多种可用的转换方法，请选择序号最小的那个。
// 只使用上述 7 个中的一个步骤来完成这次转换。
// 输入格式
// 第一行一个正整数 n。
// 然后 n 行，每行 n 个字符，全部为 `@` 或 `-`，表示初始的正方形。
// 接下来 n 行，每行 n 个字符，全部为 `@` 或 `-`，表示最终的正方形。
// 输出格式
// 单独的一行包括 1 \sim 7 之间的一个数字（在上文已描述）表明需要将转换前的正方形变为转换后的正方形的转换方法。
// 样例输入
// 3
// @-@
// ---
// @@-
// @-@
// @--
// --@
// 样例输出
// 1
// 提示
// 【数据范围】
// 对于 100 的数据，1 <= n <= 10。
// 题目翻译来自 NOCOW。
// USACO Training Section 1.2
#include <stdio.h>
int n;
char a[15][15], b[15][15], c[15][15], d[15][15];
bool work1() {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            b[j][n-i+1] = a[i][j];
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(b[i][j] != c[i][j])
                    return 0;
                return 1;
            }
        }
    }
}
bool work2() {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            b[n-i+1][n-j+1] = a[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(b[i][j] != c[i][j])
                return 0;
            return 1;
        }
    }
}
bool work3() {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            b[n-j+1][i] = a[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <=n; ++j) {
            if(b[i][j] != c[i][j])
                return 0;
            return 1;
        }
    }
}
bool work4() {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            b[i][n-j+1] = a[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            b[i][n-j+1] = a[i][j];
        }
    }
}
bool work5() {
    work4();
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            a[i][j] = b[i][j];
            if(work1())
                return 1;
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < n; ++j) {
            a[i][j] = b[i][j];
            if(work2())
                return 1;
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < n; ++j) {
            a[i][j] = b[i][j];
            if(work3())
                return 1;
        }
    }
    return 0;
}
bool work6() {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(a[i][j] != c[i][j])
                return 0;
        }
    }
    return 1;
}
void work() {
    if(work1()){
        printf("1");
        return;
    }
    if(work2()){
        printf("2");
        return;
    }if(work3()){
        printf("3");
        return;
    }if(work4()){
        printf("4");
        return;
    }if(work5()){
        printf("5");
        return;
    }
    if(work6()){
        printf("6");
        return;
    }
    printf("7");
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
            d[i][j] = a[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%d" , &c[i][j]);
        }
    }
    work();
    return 0;
}