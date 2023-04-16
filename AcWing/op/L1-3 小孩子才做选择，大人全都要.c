/*L1-3 小孩子才做选择，大人全都要
阿汪面前有两只盲盒，每只盒子打开都有两种可能：或者装了 X 克狗粮，或者是一只容量为 Y 克的狗粮储蓄盒。如果是狗粮，阿汪可以快乐地吃掉；如果是空储蓄盒，那就倒霉了，阿汪必须想办法找到狗粮把这只储蓄盒装满，自己还吃不到。
正当阿汪发愁不知道该怎么选的时候，铲屎官大手一挥：“小孩子才做选择，大人全都要！”但全都要的结果，却不一定是赚了还是亏了……
我们假设聪明的阿汪总是能嗅出狗粮最多的盒子，并且绝不会选任何储蓄盒。而铲屎官没有这样的鼻子，他一定是全都要。铲屎官如果打开了有储蓄盒的盒子，就必须想办法把储蓄盒装满，他会优先用另一只盒子里的狗粮装（如果另外一只盒子里有狗粮），不够了还得自己去买新的狗粮，这样阿汪可就亏啦，什么都吃不到了。本题就请你判断阿汪到底是赚了还是亏了。
输入格式：
输入在一行中给出两个整数，绝对值都不超过 100，中间用一个空格分开，分别代表两只盒子里的东西。如果是正数就表示是狗粮的份量，如果是负数就表示绝对值是空盆的容量。两个数都肯定不是 0，因为保证没有空盒子。
输出格式：
第一行输出两个结果：如果让阿汪选能吃到的狗粮 A，和如果铲屎官全都要能吃到的狗粮 B。两个数字间用一个空格分开。如果铲屎官的决定让阿汪赚到了，就在第二行输出一个笑脸 ^_^，否则输出一个哭脸 T_T。但如果反正什么都吃不到（两个盒子里都没有狗粮），就输出一张躺平脸 -_-。
输入样例 1：
12 18
输出样例 1：
18 30
^_^
输入样例 2：
12 -18
输出样例 2：
12 0
T_T
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/
#include <stdio.h>
int main(void) {
    int m, n, temp;
    scanf("%d%d", &m, &n);
    if(m + n > 0) {
        if(m > n) {
            printf("%d %d\n^_^", m, m + n);
        }else {
            printf("%d %d\n^_^", n, m + n);
        }      
    }else {
        if(m < 0 && n < 0) {
            printf("T_T");
        }else if(m < 0) {
            printf("%d 0\nT_T", n);
        }else {
            printf("%d 0\nT_T", m);
        }
        
    }
    return 0;
}