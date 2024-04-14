#include <iostream>
#include <string>
#include <string.h>
// #include <windows.h>
using namespace std;

int menu_select(void);
int menu_out; // 定义一个返回上一级菜单
// 哈夫曼树的存储结构
typedef struct
{
    char data;                  // 存储数据
    int weight;                 // 结点的权重
    string num;                 // 存放哈夫曼码
    int parent, lchild, rchild; // 结点的双亲、左孩子、右孩子的下标
} HTNode, *HuffmanTree;

// 两个最小结点
typedef struct
{
    int s1;
    int s2;
} MIN;

// 选择结点权值最小的两个结点
MIN Select(HuffmanTree HT, int n)
{
    int min, secmin, s1, s2;
    min = 10000;
    secmin = 10000;
    MIN code;
    s1 = 1;
    s2 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0 && (HT[i].weight < min))
        {
            min = HT[i].weight;
            s1 = i;
        }
    }
    for (int i = 1; i <= n; i++)
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

// 创造哈夫曼树
void CreateHuffman(HuffmanTree &HT, int num)
{

    int m;
    m = 2 * num - 1;
    HT = new HTNode[m + 1];      // 分配空间
    for (int i = 1; i <= m; i++) // 初始化
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    cout << "请输入各个节点的权值：" << endl;
    for (int i = 1; i <= num; i++)
    {
        cin >> HT[i].weight;
        HT[i].data = 'a' + i - 1;
    }

    for (int i = num + 1; i <= m; i++) // 构建哈夫曼树
    {
        MIN min;
        min = Select(HT, i - 1); // 选择二叉树
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
    //	for (int i = 1; i <= m; i++)  //进行每个字符哈夫曼码的输出
    //	{
    //		if(HT[i].data != -1)
    //		{
    //			cout<<HT[i].data<<" 权重为"<<HT[i].weight<<"  ，哈夫曼码为："<<HT[i].num<<endl;
    //		}
    //	}
}

void PrintCode(HuffmanTree HT, int n)
{
    for (int i = 1; i <= n; i++)
    {
        HT[i].data = 'a' + i - 1;
        cout << HT[i].data << " 权重为 " << HT[i].weight << ",哈夫曼编码为: "
             << HT[i].num << endl;
    }
}

// 打印哈夫曼树
void Print(HuffmanTree HT, int n)
{
    cout << "下标\t字符\t权\t父节点\t左孩子\t右孩子\t" << endl;
    cout << "-\t-\t-\t-\t-\t-\t" << endl;
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
        cout << HT[i].data << " " << endl;
    }
}

int main(void)
{
    // 关闭输入输出缓存，使效率提升
	ios::sync_with_stdio(false);
	// 解除cin和cout的默认绑定，来降低IO的负担使效率提升
	cin.tie(NULL); cout.tie(NULL);
    int n; // 结点个数
    HuffmanTree HT;
    cout << "====欢迎使用====\r" << endl;
    cout << "   本系统可以\r" << endl;
    cout << "构造一棵哈夫曼树\r" << endl;
    cout << "请输入树的结点的个数：";
    cin >> n;
    CreateHuffman(HT, n); // 创建哈夫曼树
    while (1)
    {
        switch (menu_select())
        {
        case 1:
            PrintCode(HT, n);
            break;
        case 2:
            PrintCode(HT, n);
            Interpretation(HT, n);
            break;
        case 3:
            Print(HT, n); // 输出哈夫曼树
        case 0:
            cout << "退出成功" << endl;
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}

int menu_select(void)
{
    int select;
    // system("cls");
    cout << "1.输出节点对应的哈夫曼编码\r" << endl;
    cout << "2.对输入的二进制码进行译码\r" << endl;
    cout << "3.按输入顺序输出哈夫曼树表\r" << endl;
    cout << "0.退出系统" << endl;
    cout << "请输入你的操作：" << endl;
    cin >> select;
    return select;
}