#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>
//#include<windows.h>
#include<stdlib.h>


typedef double DataType;  //权值的数据类型
typedef char** HuffmanEncode; //二级指针进行编码存储操作（相当于利用二维数组存储一样）

typedef struct HTNode
{
    DataType weight;
    int parent;
    int rchild;
    int lchild;
}*HuffmanTree, HTNode;

//挑选权最小的两个结点
void SelectNode(HuffmanTree& HT, int n, int& one, int& two)
{
    int min;

    //找第一个最小权结点
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0)
        {
            min = i;
            break; //注意这里一定要退出，只是为了找到一个未进行构造哈夫曼树的叶子结点而已
        }
    }
    for (int i = min + 1; i <= n; i++)
    {
        if (HT[i].parent == 0 && HT[i].weight < HT[min].weight)
        {
            min = i;
        }
    }
    one = min;

    //找第二个较小权的结点
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0 && i != one)
        {
            min = i;
            break; //注意这里一定要退出
        }
    }
    for (int i = min + 1; i <= n; i++)
    {
        if (HT[i].parent == 0 && HT[i].weight < HT[min].weight && i != one)
        {
            min = i;
        }
    }
    two = min;
}

//创建哈夫曼树
void CreatHuffman(HuffmanTree& HT, DataType* w, int n)
{
    int m = 2 * n - 1; //哈夫曼树的结点个数
    HT = new HTNode[m + 1];
    //开辟m+1个结点，下标为0的位置不存放数据，以防判断根节点和叶子节点时发生混淆

    //赋值权
    for (int i = 1; i <= n; i++)
    {
        HT[i].weight = w[i - 1];
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].parent = 0;
    }

    for (int i = n + 1; i <= m; i++)
    {
        int one, two;//挑选出权值最小的两个结点
        SelectNode(HT, i - 1, one, two); //在1到i-1内查找最小两个的权结点的下标

        HT[i].weight = HT[one].weight + HT[two].weight;
        HT[i].parent = 0;

        HT[i].lchild = one;
        HT[i].rchild = two;

        HT[one].parent = i;
        HT[two].parent = i;
    }
}

//哈夫曼编码
void Encode(HuffmanTree& HT, HuffmanEncode& HD, int n)
{
    //首先开辟指向各个叶子结点对应存储编码数组的数组
    HD = new char* [n + 1]; //下标为0不存储，为了与哈夫曼树相对应

    //开辟存储一个叶子结点编码的数组
    char* code = new char[n];
    code[n - 1] = '\0'; //将编码最后一位设置字符串结束符标志

    for (int i = 1; i <= n; i++)
    {
        int start = n - 1; //每记录一个叶子节点后将start指针回溯到指向'\0’的位置
        int c = i; //记录当前编码的结点下标
        int p = HT[i].parent;
        while (p != 0) //当为父节点为0时结束记录编码
        {
            if (HT[p].rchild == c)
                code[--start] = '1';
            else
                code[--start] = '0';

            c = p; //记下父节点，下一轮循环编码做孩子
            p = HT[p].parent;
        }

        HD[i] = new char[n - start]; //开辟第i行n-start个空间的数组进行编码的存放
        strcpy(HD[i], &code[start]); //将编码拷贝到字符指针数组中的相应位置
    }
}

void PrintCode(HuffmanTree HT, HuffmanEncode HD, int n)
{
    for (int i = 1; i <= n; i++)
    {
        string s(HD[i]);
        cout << "权 " << HT[i].weight << " 的哈夫曼编码为: "
            << s << endl;
    }
}

//打印哈夫曼树
void Print(HuffmanTree HT, int n)
{
    cout << "下标\t权\t父节点\t左孩子\t右孩子\t" << endl;
    cout << "0\t0\t0\t0\t0\t" << endl;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        cout << i << "\t"
            << HT[i].weight << "\t"
            << HT[i].parent << "\t"
            << HT[i].lchild << "\t"
            << HT[i].rchild << "\t"
            << endl;
    }
}

//进行译码
void Interpretation(HuffmanTree HT,int n)
{
    string code;
    int m = 2 * n - 1;
    int i;
    int j = 0;
    cout << "请输入要进行译码的二进制串(以#为结束标志):";
    cin >> code;
    while (code[j] != '#') //二进制译码以#为结束标志
    {
        i = m ; //第一个根节点的下标
        while (HT[i].lchild != 0 && HT[i].rchild != 0)
        {
            if (code[j] == '0')  //左子树
                i = HT[i].lchild;
            else
                i = HT[i].rchild;  //右子树
            ++j; //记录字符串解码的位置
        }
        cout << HT[i].weight << endl;
    }

}

void test()
{
    cout << "请输入你要进行的操作" << endl;
    cout << "1.输出每个叶子节点对应的哈夫曼编码" << endl;
    cout << "2.对输入的二进制进行译码" << endl;
    cout << "3.输出哈夫曼树表" << endl;
    cout << "0.退出系统" << endl;
    cout << "请输入你的操作：" << endl;
}

void test01()
{
    system("pause");
    system("clear");
    test();
}

int main(void)
{
    DataType s;
    int n; //结点个数
    int choice =1;
    HuffmanTree HT;
    HuffmanEncode HD = NULL;
    DataType* weight;

    cout << "请输入结点的个数：";
    cin >> n;
    weight = new DataType[n];
    cout << "请输入各个结点的权:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        weight[i] = s;
    }
    CreatHuffman(HT, weight, n); // 创建哈夫曼树
    Encode(HT, HD, n);  //进行编码

    test();
    while (choice)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            PrintCode(HT, HD, n);
            test();
            break;
        case 2:
            PrintCode(HT, HD, n);
            Interpretation(HT,n);
            test();
            break;
        case 3:
            Print(HT, n);//输出哈夫曼树
            test();
        case 0:
            cout << "退出成功" << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
