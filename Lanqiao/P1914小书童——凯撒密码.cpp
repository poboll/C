//
// Created by 大妖怪 on 2024/3/22.
//
// P1914 小书童——凯撒密码
// 题目背景
// 某蒟蒻迷上了 “小书童”，有一天登陆时忘记密码了（他没绑定邮箱 or 手机），于是便把问题抛给了神犇你。
// 题目描述
// 蒟蒻虽然忘记密码，但他还记得密码是由一个字符串组成。密码是由原文字符串（由不超过 50 个小写字母组成）中每个字母向后移动 n 位形成的。`z` 的下一个字母是 `a`，如此循环。他现在找到了移动前的原文字符串及 n，请你求出密码。
// 输入格式
// 第一行：n。第二行：未移动前的一串字母。
// 输出格式
// 一行，是此蒟蒻的密码。
// 样例输入1
// 1
// qwe
// 样例输出1
// rxf
// 提示
// 字符串长度 <= 50，1 <= q, n <= q 26。
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char str[51];
    // 读取输入
    scanf("%d", &n);
    scanf("%s", str);
    // 加密字符串
    for(int i = 0; i < strlen(str); ++ i) {
        if(str[i] + n > 'z') {
            str[i] = 'a' + (n - ('z' - str[i] + 1));
        }else {
            str[i] += n;
        }
    }
    // 输出加密后的字符串
    printf("%s\n", str);
    return 0;
}
// 打表打爆字符串总长，因为这是入门数据
#include <bits/stdc++.h>
using namespace std;
string a,zi("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
int main()
{
    int n;
    cin >> n >> a;
    for(int i = 0; i <= a.length() - 1; ++ i) {
        cout << zi[zi.find(a[i]) + n];
    }
    return 0;
}