//
// Created by 大妖怪 on 2024/1/22.
//
#include <stdio.h>
int main (){
    int l, m;
    scanf("%d %d", &l, &m);

    int trees[l + 1]; // 数轴上每个点的树的状态，1表示有树，0表示没有树
    for(int i = 0; i <= l; i ++) {
        trees[i] = 1; // 初始时所有点都有树
    }

    for(int i = 0; i < m; i ++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // 移除区域内的树
        for(int j = u; j <= v; j ++) {
            trees[j] = 0;
        }
    }

    int remain = 0;
    // 计算剩余的树木数量
    for(int i = 0; i <= l; i ++) {
        remain += trees[i];
    }

    printf("%d\n", remain);

    return 0;
}