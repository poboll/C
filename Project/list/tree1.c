#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <windows.h>
#define MAX_LEAF_NODE 26

int menu_select(void);
int menu_out; // 定义一个返回上一级菜单

// 定义哈夫曼树的节点
struct huffman_node
{
    int weight;                 // 节点权重
    char data;                  // 叶子节点存储的字符
    struct huffman_node *left;  // 左子节点指针
    struct huffman_node *right; // 右子节点指针
};

// 构造哈夫曼树函数
struct huffman_node *construct_huffman_tree(int n, int *weights)
{
    struct huffman_node *nodes[MAX_LEAF_NODE];
    int i, j, k;
    for (i = 0; i < n; ++i)
    {
        nodes[i] = (struct huffman_node *)malloc(sizeof(struct huffman_node));
        nodes[i]->weight = weights[i];
        nodes[i]->data = 'a' + i;
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
    }
    for (i = 0; i < n - 1; ++i)
    {
        int min1 = -1, min2 = -1;
        for (j = 0; j < n + i; ++j)
        {
            if (nodes[j] != NULL)
            {
                if (min1 == -1 || nodes[min1]->weight > nodes[j]->weight)
                {
                    min2 = min1;
                    min1 = j;
                }
                else if (min2 == -1 || nodes[min2]->weight > nodes[j]->weight)
                {
                    min2 = j;
                }
            }
        }
        struct huffman_node *new_node = (struct huffman_node *)malloc(sizeof(struct huffman_node));
        new_node->weight = nodes[min1]->weight + nodes[min2]->weight;
        new_node->data = '\0';
        new_node->left = nodes[min1];
        new_node->right = nodes[min2];
        nodes[min1] = new_node;
        nodes[min2] = NULL;
    }
    return nodes[0];
}

// 输出哈夫曼编码函数
void display_huffman_code(struct huffman_node *root, char *code, int len)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data != '\0')
    { // 叶子节点，输出编码
        code[len] = '\0';
        printf("%c：%s\n", root->data, code);
    }
    if (root->left)
    {
        code[len] = '0';
        display_huffman_code(root->left, code, len + 1); // 遍历左子树
    }
    if (root->right)
    {
        code[len] = '1';
        display_huffman_code(root->right, code, len + 1); // 遍历右子树
    }
}

// 解码函数
void decode_huffman_string(struct huffman_node *root, const char *encoded)
{
    struct huffman_node *node = root;
    while (*encoded)
    {
        if (*encoded == '0')
        {
            node = node->left; // 转到左子节点
        }
        else if (*encoded == '1')
        {
            node = node->right; // 转到右子节点
        }
        if (node->left == NULL && node->right == NULL)
        { // 叶子节点，存储对应字符
            printf("%c", node->data);
            node = root; // 回到根节点
        }
        encoded++;
    }
}

int main()
{
    while (1)
    {
        switch (menu_select())
        {
        case 1:
        { // system("cls");
            menu_out = 1;
            printf("这是二级菜单1内部\r\n");
            int n; // 叶子节点个数
            printf("请输入叶子节点的个数：");
            scanf("%d", &n);

            int weights[MAX_LEAF_NODE]; // 叶子节点权值
            printf("请依次输入%d个叶子节点的权值：", n);
            for (int i = 0; i < n; ++i)
            {
                scanf("%d", &weights[i]);
            }

            struct huffman_node *root = construct_huffman_tree(n, weights);

            printf("哈夫曼编码如下：\n");
            char code[MAX_LEAF_NODE];
            display_huffman_code(root, code, 0);

            char encoded[MAX_LEAF_NODE]; // 要解码的二进制串
            printf("请输入要解码的二进制串：");
            scanf("%s", encoded);

            printf("译码结果为：");
            decode_huffman_string(root, encoded);
            printf("\n");

            printf("输入0返回上一级菜单：\r\n");
            while (menu_out)            // 只有当键盘输入为0时，才退出当前菜单
                scanf("%d", &menu_out); // 否则一直循环获取键盘输入
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
int menu_select(void)
{
    int select;
    system("clear");
    printf("====欢迎使用====\r\n");
    printf("   本系统可以\r\n");
    printf("构造一棵哈夫曼树\r\n");
    printf("输出节点对应编码\r\n");
    printf("对输入二进制译码\r\n按1进入系统\n按任意键退出\n");
    scanf("%d", &select);
    return select;
}