//
// Created by  Apple on 2024/4/21.
//
#include <iostream>
#include <iomanip>
#define M 50
using namespace std;

typedef struct SqQueue {
    int element[M]; //长度
    int front;      //头
    int base;       //尾
} SqQueue;

void InitQueue(SqQueue *Q) {
    Q->front = Q->base = 0;
}

int InserQ(SqQueue *Q, int data) {
    if ((Q->base + 1) % M == Q->front)
        return 0;
    Q->element[Q->base] = data;
    Q->base = (Q->base + 1) % M;
    return 1;
}

int GetHead(SqQueue Q, int *data) {
    if (Q.front == Q.base)
        return 0;
    *data = Q.element[Q.front];
    return 1;
}

int DeQueue(SqQueue *Q, int *data) {
    if (Q->front == Q->base)
        return 0;
    *data = Q->element[Q->front];
    Q->front = (Q->front + 1) % M;
    return 1;
}

int main() {
    SqQueue Q;
    int i, n, x, j, l, data;
    cout << "输入行数n:";
    cin >> n; /* n为杨辉三角行数 */
    InitQueue(&Q);
    InserQ(&Q, 1); /* 第1行的1进队列 */
    for (i = 2; i <= n; i++) { /* 打印第i-1行并生成第i行 */
        InserQ(&Q, 1); /* 第i行中的第一个元素1进队 */
        for (l = n + 1; l > i; l--)
            cout << "  ";
        for (j = 1; j < i - 1; j++) {
            cout << left << setw(4) << Q.element[Q.front]; /* 输出队头 */
            x = GetHead(Q, &data);
            DeQueue(&Q, &x);
            x = x + Q.element[Q.front]; /* 计算第i行的值 */
            InserQ(&Q, x);
        }
        cout << left << setw(4) << Q.element[Q.front] << "\n"; /* 打印第i-1行的最后一个1并换行 */
        DeQueue(&Q, &x);
        InserQ(&Q, 1); /* 第i行中的最后一个元素1进队 */
    }
    while (Q.front != Q.base) { /* 输出最后一行元素 */
        cout << left << setw(4) << Q.element[Q.front];
        DeQueue(&Q, &x);
    }
    return 0;
}
