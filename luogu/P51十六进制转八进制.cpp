//
// Created by 大妖怪 on 2024/3/18.
//
// P51 十六进制转八进制问题描述
// 　　给定n个十六进制正整数，输出它们对应的八进制数。
// 输入格式
// 　　输入的第一行为一个正整数n （1<=n<=10）。
// 　　接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000。
// 输出格式
// 　　输出n行，每行为输入对应的八进制正整数。
// 【注意】
// 　　输入的十六进制数不会有前导0，比如012A。
// 　　输出的八进制数也不能有前导0。
// 样例输入
// 　　2
// 　　39
// 　　123ABC
// 样例输出
// 　　71
// 　　4435274
// 【提示】
// 先将十六进制数转换成某进制数，再由某进制数转换成八进制。
// 首先看到进制转换问题，考虑使用C语言自带的占位符转换。
// %d十进制占位符，long int、long long分别为%ld，%lld
// %o八进制占位符，long int、long long分别为%lo，%llo
// %x十六进制占位符，long int、long long分别为%lx，%llx
/** WA
 * 长度是十万的十六进制数有多大吧，已经超过了long long int是能表示的最长长度了。
    #include <stdio.h>
    int main() {
        long long int x;
        scanf("%llx", &x); // 十六进制输入
        printf("%llo", x); // 八进制输出
        return 0;
    }
 */
// 把十六进制转成二进制并用字符串保存下来，然后由二进制再向八进制转化。
// 十六进制数转二进制占四个二进制位，八进制数转二进制占三个二进制位，所以转化出的二进制数位数是4的倍数，向八进制转化时需要位数是3的倍数，所以可能需要在二进制字串前面补0。同时我们需注意题目要求不允许有前导0，所以需要判断从第一个不为0的八进制数开始输出。
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar(); //吸收换行符，防止对后面的gets()产生影响
    while(n--)
    {
        int sum;
        char str[100001], str_o[400010];
        gets(str);
        int i=0, j=0, num = strlen(str);
        if((4*num)%3 == 1) //判断转化后的长度是否能被3整除，不能则补0
            str_o[0]='0', str_o[1]='0', j=2;
        else if((4*num)%3 == 2)
            str_o[0]='0', j=1;
        for(i=0;i<num;i++)
        {
            switch(str[i]) //switch批量转化十六进制位，快速延长字符串长度
            {
                case '0':str_o[j]='0', str_o[j+1]='0', str_o[j+2]='0', str_o[j+3]='0';break;
                case '1':str_o[j]='0', str_o[j+1]='0', str_o[j+2]='0', str_o[j+3]='1';break;
                case '2':str_o[j]='0', str_o[j+1]='0', str_o[j+2]='1', str_o[j+3]='0';break;
                case '3':str_o[j]='0', str_o[j+1]='0', str_o[j+2]='1', str_o[j+3]='1';break;
                case '4':str_o[j]='0', str_o[j+1]='1', str_o[j+2]='0', str_o[j+3]='0';break;
                case '5':str_o[j]='0', str_o[j+1]='1', str_o[j+2]='0', str_o[j+3]='1';break;
                case '6':str_o[j]='0', str_o[j+1]='1', str_o[j+2]='1', str_o[j+3]='0';break;
                case '7':str_o[j]='0', str_o[j+1]='1', str_o[j+2]='1', str_o[j+3]='1';break;
                case '8':str_o[j]='1', str_o[j+1]='0', str_o[j+2]='0', str_o[j+3]='0';break;
                case '9':str_o[j]='1', str_o[j+1]='0', str_o[j+2]='0', str_o[j+3]='1';break;
                case 'A':str_o[j]='1', str_o[j+1]='0', str_o[j+2]='1', str_o[j+3]='0';break;
                case 'B':str_o[j]='1', str_o[j+1]='0', str_o[j+2]='1', str_o[j+3]='1';break;
                case 'C':str_o[j]='1', str_o[j+1]='1', str_o[j+2]='0', str_o[j+3]='0';break;
                case 'D':str_o[j]='1', str_o[j+1]='1', str_o[j+2]='0', str_o[j+3]='1';break;
                case 'E':str_o[j]='1', str_o[j+1]='1', str_o[j+2]='1', str_o[j+3]='0';break;
                case 'F':str_o[j]='1', str_o[j+1]='1', str_o[j+2]='1', str_o[j+3]='1';break;
                default:break;
            }
            j += 4; //用变量j实时记录当前字串长度，便于switch工作
        }
        int flag = 0; //这里插旗，判断第一个不是0的数出现
        for(i=0;i<strlen(str_o)-2;i+=3)
        {
            int res = 4*(str_o[i]-'0') + 2*(str_o[i+1]-'0') + (str_o[i+2]-'0'); //二进制向八进制转化
            if(res != 0) flag=1; //第一位不是0的数出现，旗子判定可以开始输出
            if(flag != 0) printf("%d", res); //从第一位不是0的数开始输出
        }
        printf("\n");
    }
    return 0;
}
