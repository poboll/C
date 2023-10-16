//
// Created by 大妖怪 on 2023/10/16.
//
//题目描述
//人比人，气死人；鱼比鱼，难死鱼。小鱼最近参加了一个“比可爱”比赛，比的是每只鱼的可爱程度。参赛的鱼被从左到右排成一排，头都朝向左边，然后每只鱼会得到一个整数数值，表示这只鱼的可爱程度，很显然整数越大，表示这只鱼越可爱，而且任意两只鱼的可爱程度可能一样。由于所有的鱼头都朝向左边，所以每只鱼只能看见在它左边的鱼的可爱程度，它们心里都在计算，在自己的眼力范围内有多少只鱼不如自己可爱呢。请你帮这些可爱但是鱼脑不够用的小鱼们计算一下。
//输入格式
//第一行输入一个正整数n，表示鱼的数目。
//第二行内输入n 个正整数，用空格间隔，依次表示从左到右每只小鱼的可爱程度
//输出格式
//一行，输出n 个整数，用空格间隔，依次表示每只小鱼眼中有多少只鱼不如自己可爱。
//输入输出样例
//输入
//6
//4 3 0 5 1 2
//输出
//0 0 0 3 1 2
#include <stdio.h>
int main() {
    int n, s, i ,j;
    scanf("%d", n);
    int a[n];
    for(i = 0; i < n; i ++) {
        s = 0; //每条鱼看不到比自己好的，每次遍历重置
        scanf("%d", a[i]);
        for(j = i; j > 0; j --) { // 自减向前看
            if(a[i] > a[j]) s ++; // 颜值高
        }
        printf("%d ", s); // 比较则输出
    }
    return 0;
}