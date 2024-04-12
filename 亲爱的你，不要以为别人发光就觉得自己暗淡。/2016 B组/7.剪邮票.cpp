// G 剪邮票
// 题目描述：
// 如【图1.jpg】, 有12张连在一起的12生肖的邮票。
// 现在你要从中剪下5张来，要求必须是连着的。
// （仅仅连接一个角不算相连）
// 比如，【图2.jpg】，【图3.jpg】中，粉红色所示部分就是合格的剪取。
// 图1：https://www.cdnjson.com/image/dYNiG
// 图2：https://image.dooo.ng/i/2024/04/10/6616a1c91bfda.webp
// 图3：https://image.dooo.ng/i/2024/04/10/6616a1c99a41c.webp
// 请你计算，一共有多少种不同的剪取方法。
// 分析分析：
// 这又是一个很经典的dfs算法，在这里，小唐没有想那没多，我们是不是要找一个5的邮票，这其实是已经定下来的，那我们直接使用全排列，把我们的所有可以做成5张邮票的数据找出来，然后我们去对我们5个邮票地位置进行一个比对，我们的答案就出来了，其实就是要求，你这五个邮票在不同的位置至少有一个相连就可以了
// 题目代码
#include <bits/stdc++.h>
long long ans = 0;
int ss[3][4] = {0, 0, 0,
                0, 0, 0,
                0, 0, 0,
                0, 0, 0};
void dfs(int x, int y) {
    if(x > 2 || x < 0 || y > 3 || y < 0) {
        return ;
    }
    if(ss[x][y] == 0) {
        return ;
    }
    ss[x][y] = 0;
    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x - 1, y);
    dfs(x, y - 1);
}
bool panduan(int a[12]) {
    int k = 0;
    int x, y;
    for(int i = 0; i < 3; ++ i) {
        for(int j = 0; j < 4; ++ j) {
            if(a[k] == 1) {
                x = i;
                y = j;
            }
            ss[i][j] = a[k++];
        }
    }
    dfs(x, y);
    int flag = 0;

    for(int i = 0; i < 3; ++ i) {
        for(int j = 0; j < 4; ++ j) {
            if(ss[i][j] == 1) {
                flag = 1;
            }
        }
    }
    if(flag == 1) {
        return false;
    }
    return true;
}
int main() {
    int a[12] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    do {
        if(panduan(a)) {
            ans ++;
        }
    }while(next_permutation(a, a + 12));
    printf("%d", ans);
    return 0;
}