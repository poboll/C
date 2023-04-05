#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

//#include"2048base.h"

/*矩阵转置*/
void transform(int *p, int len)
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            if (i>j) //转置时只需要更新对角部分即可
            {
                int tmp = *(p + i*len + j);
                *(p + i*len + j) = *(p + j*len + i);
                *(p + j*len + i) = tmp;
            }
}

/*删除某一行数据中的零元素——把零元素根据rev往一个方向去堆叠*/
void delZeros(int *p, int len, bool rev)
{
    int k = rev ? (len - 1) : 0;
    int step = rev ? -1 : 1;
    for (int j = rev ? (len - 1) : 0; j < len && j >= 0;)
    {
        if (*(p + j) != 0)
        {
            *(p + k) = *(p + j);
            k += step;
        }
        j += step;
    }
    for (int j = k; j < len && j >= 0;)
    {
        *(p + j) = 0;
        j += step;
    }
}

/*合并一行数据的相同元素,返回得分*/
int combine(int *p, int len, bool rev)
{
    int score = 0;				 // 得分
    int k = rev ? (len - 1) : 0; // 主要的顺序变量
    int step = rev ? -1 : 1;	 // 步长，和是否反向有关
    for (int i = rev ? (len - 1) : 0; i < len && i >= 0; i += step)
    {
        if ((*(p + i) != *(p + i + step)) || (i == (rev ? 0 : (len - 1))))
        {
            *(p + k) = *(p + i);
            k += step;
        }
        else
        {
            *(p + k) = *(p + i) * 2;
            i += step; // i跳过重复数字的位置
            k += step;
            score += *(p + i) * 2;
        }
    }
    for (int j = k; j < len && j >= 0; j += step)
        *(p + j) = 0; // k没遍历完，补零
    return score;
}

/*输出二维数组*/
void out(int *p, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
            cout << *(p + i * len + j) << ' ';
        cout << endl;
    }
    cout << endl;
}

/*判断移动前后数组是否发生改变*/
bool ifchange(int *p, int *q, int len)
{
    bool flag = false;
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            if (*(p + i*len + j) != *(q + i*len + j)) flag = true;
    return flag;
}

/*对数组进行堆叠。p为需要堆叠的一行/列数据，len为边长，rev判断是否反向[从左至右], transform判断是否需要转置[上/下]。
 *默认的矩阵顺序：行从上到下；列从左至右。计算时，遍历每一行，堆叠每一列
 *返回数组堆叠前后是否发生变化
 */
bool pileRows(int *p, int len, bool rev, bool trans, int *score)
{
    int *q = new int[len*len];
    for (int i = 0; i<len; i++)
        for (int j = 0; j<len; j++)
            *(q + i*len + j) = *(p + i*len + j); //先复制一遍，方便判断数组是否发生改变
    if (trans) transform(p, len); // 转置
    // out(p, len);
    for (int i = 0; i < len; i++) // 遍历每一行
    {
        int *q = p + i * len;     // 构造一行数据对应的指针
        // for(int i=0;i<len;i++) cout << *(q+i) << " ";cout << endl;
        delZeros(q, len, rev);    // 先把这一行中的零元素往一个方向堆叠
        // for(int i=0;i<len;i++) cout << *(q+i) << " ";cout << endl;
        *score += combine(q, len, rev); //合并相同元素，并获得得分
        // for(int i=0;i<len;i++) cout << *(q+i) << " ";cout << endl;
    }
    // out(p, len);
    if (trans) transform(p, len); // 操作完了，再转置回来
    return ifchange(p, q, len);   // 返回数组是否发生变化的标志
}

/*添加随机数*/
void AddNum(int *p, int len)
{
    int x, y;
    do
    {
        x = rand() % 4;
        y = rand() % 4;
    } while (*(p + x * len + y) != 0); // 找到数字为零的位置
    if (rand() % 9 >= 5)  // 4出现的概率为4/9
        *(p + x * len + y) = 4;
    else
        *(p + x * len + y) = 2;
}

/*运行2048*/
void run(int *p, int len, int *score)
{
    char key = getch();
    switch (key)
    {
    case 72: //"up"
    case 'w':
    case 'W':
        if (pileRows(p, len, false, true, score)) AddNum(p, len); //只有数组发生改变才增加一个随机数
        //out(p, len);
        break;
    case 80: //"down"
    case 's':
    case 'S':
        if (pileRows(p, len, true, true, score)) AddNum(p, len);
        //out(p, len);
        break;
    case 75: //"left"
    case 'a':
    case 'A':
        if (pileRows(p, len, false, false, score)) AddNum(p, len);
        //out(p, len);
        break;
    case 77: //"right"
    case 'd':
    case 'D':
        if (pileRows(p, len, true, false, score)) AddNum(p, len);
        // out(p, len);
        break;
    default:
        break;
    }
}

/*主程序，测试用*/
//int main()
//{
//    int b[4][4] = { 4, 0, 0, 0,
//        2, 0, 0, 0,
//        8, 0, 0, 0,
//        2, 0, 0, 0 };
//    int *score = new int;
//    *score = 0;
//    int *x = (int *)b;
//    while (1)
//    {
//        run(x, 4, score);
//        out(x, 4);
//    }
//
//    // int a[] = {2,2,1,2};
//    // cout << combine(a,4,true);
//    // for(int i=0; i<4; i++) cout << a[i] << " ";
//    return 0;
//}
