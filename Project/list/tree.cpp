#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string.h>
// #include <windows.h>
#include <stdlib.h>

using namespace std;

typedef double DataType;      // 权值的数据类型
typedef char **HuffmanEncode; // 二级指针进行编码存储操作（相当于利用二维数组存储一样）

// 哈夫曼树的存储结构
typedef struct
{
    char data;                  // 存储数据
    int weight;                 // 结点的权重
    string num;                 // 存放哈夫曼码
    int parent, rchild, lchild; // 结点的双亲、左孩子、右孩子的下标
} HTNode, *HuffmanTree;

// 两个最小结点
typedef struct
{
    int s1;
    int s2;
} MIN;

// 挑选权最小的两个结点
MIN SelectNode(HuffmanTree &HT, int n)
{
    int min, secmin, s1, s2;
    min = 0x3f3f3f3f;
    secmin = 0x3f3f3f3f;
    MIN code;
    s1 = 1;
    s2 = 1;
    // 找第一个最小权结点
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0 && (HT[i].weight < min))
        {
            min = HT[i].weight;
            s1 = i;
        }
    }
    for (int i = min + 1; i <= n; i++)
    {
        if (HT[i].parent == 0 && (HT[i].weight < secmin) && (i != s1))
        {
            secmin = HT[i].weight;
            s2 = i;
        }
    }
    code.s1 = s1;
    code.s2 = s2;
    return code;
}

// 将哈夫曼码存储在结构体num中
void putlorinnum(HuffmanTree &hft, int num)
{
    for (int i = num; i >= 1; i--)
    {
        if (hft[hft[i].parent].parent)
        {
            hft[i].num = hft[hft[i].parent].num + hft[i].num;
        }
    }
}

// 创建哈夫曼树
void CreatHuffman(HuffmanTree &HT, int num)
{
    int m = 2 * num - 1;    // 哈夫曼树的结点个数
    HT = new HTNode[m + 1]; // 开辟m+1个结点，下标为0的位置不存放数据，以防判断根节点和叶子节点时发生混淆
    // 初始化
    for (int i = 1; i <= m; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].data = 'a' + i - 1;
    }
    cout << "请输入各个结点的权:" << endl;
    for (int i = 1; i <= num; i++)
    {
        cin >> HT[i].weight;
    }

    for (int i = num + 1; i <= m; i++) // 构建哈夫曼树
    {
        MIN min;                     // 挑选出权值最小的两个结点，这里使用结构体储存数据
        min = SelectNode(HT, i - 1); // 在1到i-1内查找最小两个的权结点的下标

        HT[min.s1].parent = i;
        HT[min.s2].parent = i;
        HT[i].lchild = min.s1;
        HT[min.s1].num = "0";
        HT[i].rchild = min.s2;
        HT[min.s2].num = "1";
        HT[i].weight = HT[min.s1].weight + HT[min.s2].weight;
        HT[i].data = -1;
    }
    putlorinnum(HT, m);
    for (int i = 1; i <= m; i++) // 进行每个字符哈夫曼码的输出
    {
        if (HT[i].data != -1)
        {
            cout << HT[i].data << " 权重为" << HT[i].weight << "  ，哈夫曼码为：" << HT[i].num << endl;
            cout << endl;
        }
    }
}

// 哈夫曼编码
void Encode(HuffmanTree &HT, HuffmanEncode &HD, int n)
{
    // 首先开辟指向各个叶子结点对应存储编码数组的数组
    HD = new char *[n + 1]; // 下标为0不存储，为了与哈夫曼树相对应

    // 开辟存储一个叶子结点编码的数组
    char *code = new char[n];
    code[n - 1] = '\0'; // 将编码最后一位设置字符串结束符标志

    for (int i = 1; i <= n; i++)
    {
        int start = n - 1; // 每记录一个叶子节点后将start指针回溯到指向'\0’的位置
        int c = i;         // 记录当前编码的结点下标
        int p = HT[i].parent;
        while (p != 0) // 当为父节点为0时结束记录编码
        {
            if (HT[p].rchild == c)
                code[--start] = '1';
            else
                code[--start] = '0';

            c = p; // 记下父节点，下一轮循环编码做孩子
            p = HT[p].parent;
        }

        HD[i] = new char[n - start]; // 开辟第i行n-start个空间的数组进行编码的存放
        strcpy(HD[i], &code[start]); // 将编码拷贝到字符指针数组中的相应位置
    }
}

void PrintCode(HuffmanTree HT, HuffmanEncode HD, int n)
{
    for (int i = 1; i <= n; i++)
    {
        HT[i].data = 'a' + i - 1;
        string s(HD[i]);
        cout << HT[i].data << " 权重为 " << HT[i].weight << ",哈夫曼编码为: "
             << s << endl;
    }
}

// 打印哈夫曼树
void Print(HuffmanTree HT, int n)
{
    cout << "下标\t字符\t权\t父节点\t左孩子\t右孩子\t" << endl;
    cout << "-\t-\t-\t-\t-\t" << endl;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        HT[i].data = 'a' + i - 1;
        cout << i << "\t"
             << HT[i].data << "\t"
             << HT[i].weight << "\t"
             << HT[i].parent << "\t"
             << HT[i].lchild << "\t"
             << HT[i].rchild << "\t"
             << endl;
    }
}

// 进行解码
void Interpretation(HuffmanTree HT, int n)
{
    string code;
    int m = 2 * n - 1;
    int i;
    int j = 0;
    cout << "请输入要进行解码的二进制串(以#结束):";
    cin >> code;
    while (code[j] != '#') // 二进制译码以#为结束标志
    {
        i = m; // 第一个根节点的下标
        while (HT[i].lchild != 0 && HT[i].rchild != 0)
        {
            if (code[j] == '0') // 转到左子节点
                i = HT[i].lchild;
            else
                i = HT[i].rchild; // 转到右子节点
            ++j;                  // 记录字符串解码的位置
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
    int n; // 结点个数
    int choice = 1;
    HuffmanTree HT;
    HuffmanEncode HD = NULL;
    DataType *weight;

    cout << "请输入结点的个数：";
    cin >> n;
    weight = new DataType[n];

    CreatHuffman(HT, n); // 创建哈夫曼树
    Encode(HT, HD, n);   // 进行编码

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
            Interpretation(HT, n);
            test();
            break;
        case 3:
            Print(HT, n); // 输出哈夫曼树
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
