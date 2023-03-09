#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
typedef int Status;
//学生信息定义 
typedef struct {
	char no[8];   //8位学号
	char name[20]; //姓名
	double price;     //成绩
}student;
typedef student ElemType;
//链表存储结构
typedef struct LNode {
	ElemType   data;       //数据域
	struct LNode* next;   //指针域
}LNode, * LinkList;
//链表初始化 
Status InitList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return 1;
}
//显示学生表信息 
Status GetElem(LinkList L, int i, ElemType& e) {
	LinkList p;
	p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return 0;
	e = p->data;
	return 1;
}
// 根据名字进行查找 
Status Search(LNode L, char str[], LinkList& p) {
	p = L.next;
	while (p)
	{
		if (strcmp(p->data.name, str) == 0)
			return 1;
		p = p->next;
	}
	return 0;
}
// 在指定位置插入某个学生的信息
Status ListInsert(LinkList L, int i, ElemType e) {
	LinkList p, s;
	p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return 0;
	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}
//删除指定位置的学生信息 
Status ListDelete(LinkList p, int i) {
	int j = 0;
	while ((p->next) && (j < i - 1))
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1))	return 0;
	LinkList q;
	q = p->next;
	p->next = q->next;
	delete q;
	return 1;
}
void Input(ElemType* e) {
	printf("姓名:");	scanf("%s", e->name);
	printf("学号:");	scanf("%s", e->no);
	printf("成绩:");	scanf("%lf", &e->price);
	printf("输入完成\n\n");
}
void Output(ElemType* e) {
	printf("姓名:%-20s\n学号:%-10s\n成绩:%-10.2lf\n\n", e->name, e->no, e->price);
}
int main() {
    LNode L;
	LinkList p;
	ElemType a, b, c, d;
	printf("-------------------");
	printf("学生信息查询系统-------------------\n");
	printf("\n1.输入学生信息\n");
	printf("2.显示学生表信息\n");
	printf("3.根据姓名进行查找\n");
	printf("4.显示指定的位置学生信息\n");
	printf("5.在指定位置插入学生信息\n");
	printf("6.删除指定位置的学生记录\n");
	printf("7.统计学生人数\n");
	printf("0.退出\n");
    printf("--------------------------------------\n\n");
	int n, choose, temp = 1;
    if (InitList(p)) {
        printf("链表初始化内存空间成功\n");
    } else {
        printf("链表初始化失败，请检查内存空间\n程序将在3秒后退出");
        temp = 0;
        Sleep(3000);
        return 0;
    }
	while (temp) {
		printf("请选择：");
		scanf("%d", &choose);
		if (choose == 9) break;
		switch (choose) {
            case 1:	
                printf("请输入要录入的学生人数:");
                scanf("%d", &n);
                for (int i = 1; i <= n; i++) {
                    printf("第%d个学生:\n", i);
                    Input(&a);
                    ListInsert(&L, i, a);
                }
                break;
            case 2:
                for (int i = 1; i <= n; i++) {
                GetElem(&L, i, b);
                Output(&b);
                }
                break;
            case 3:	
                char str[15];
                printf("请输入要查找的学生姓名:");
                scanf("%s", str);
                if (Search(L, str, p))
                    Output(&(p->data));
                else
                    printf("没有此学生信息！\n");
                break;
            case 4:
                printf("请输入要查询的位置:");
                int d1;
                scanf("%d", &d1);
                GetElem(&L, d1, c);
                Output(&c);
                break;
            case 5:	
                printf("请输入要插入的位置:");
                int d2;
                scanf("%d", &d2);
                printf("请输入学生信息:\n");
                Input(&c);
                if (ListInsert(&L, d2, c)) {
                    n++;
                    puts("插入成功");
                } else {
                    puts("插入失败");
                }
                break;
            case 6:
                printf("请输入要删除的位置:");
                int d3;
                scanf("%d", &d3);
                if (ListDelete(&L, d3)) {
                    n--;
                    puts("删除成功");
                } else {
                    puts("删除失败");
                }
                break;
            case 7:printf("已录入的学生个数为:%d\n\n", n);
                break;
            case 0:
                printf("程序将在1秒后退出");
                Sleep(1000);
                exit(0);
                break;
            }
	}
	return 0;
}