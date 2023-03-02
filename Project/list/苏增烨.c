#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define MAX  20
#define _CRT_SECURE_NO_WARNINGS//忽略ide警告和错误
typedef struct {
	int no;  //12位学号 
	char name[20];  //姓名
	float price;         //成绩 
}Student;

typedef struct {
	Student* address;  //储存空间的基地址
	int length;     //数据内容个数
}SqList;

void InitList(SqList &L) {//初始化 
	L.address = (Student*)malloc(MAX * sizeof(Student));//数组MAX空间
	//L.address= new Student[MAX];
	L.length = 0;
	if (!L.address) {
		printf("初始化失败"); //储存分配失败退出
	}
	else printf("初始化成功");
}

//void GetElem取值定义

void LocateElem(SqList& L, int i) {//对指定位置进行查找，并返回其信息 
	if (1 <= i && i <= L.length) {
		printf("姓名：%s\n", L.address[i - 1].name);
		printf("学号：%d\n", L.address[i - 1].no);
		printf("成绩：%f\n", L.address[i - 1].price);
	}
	else printf("没有该同学");
	system("PAUSE");    //暂停，按任意键继续
	system("cls");  //清屏
}

void FindElem(SqList& L, char e[])  //根据姓名进行查找，并返回此学生的学号和成绩 
{
	int l = 0;
	for (int i = 0; i < L.length; i++) {
		if (strcmp(L.address[i].name, e) == 0) {
			printf("学号：%d,", L.address[i].no);
			printf("成绩：%f.", L.address[i].price);
			l++;
		}
	}
	if (l == 0) {
		printf("没有该同学信息");
	}
	system("PAUSE");
	system("cls");
}
void  ListInsert(SqList& L, int i)  //在顺序表L中第i个位置插入新的元素e,并判断插入范围是否合法 
{
	system("cls");
	if ((i < 1) || (i > L.length + 1)) {
		printf("输入的i不合法");
	}
	system("PAUSE");
	system("cls");
	if (L.length == MAX) {
		printf("已满");
		system("PAUSE");
		system("cls");
	}

	for (int j = L.length - 1; j >= i - 1; j--) {
		L.address[j + 1] = L.address[j];
	}             //插入位置以及之后的元素后移 
	printf("请输入您想要插入的学生信息的学号、姓名、成绩：");
	scanf("%d%s%f", &L.address[i - 1].no, &L.address[i - 1].name, &L.address[i - 1].price);           //将新元素e放在第i个位置上 
	++L.length;
	printf("成功\n");
	printf("按任意键返回");
	system("PUASE");
	system("cls");
}

int  ListDelete(SqList& L, int i)  //在顺序表中删除第i个元素 
{
	if (i<1 || i>L.length)
	{
		printf("i值不合法");
		system("PAUSE");
		system("cls");
		return 0;
	}
	int j;
	j = i;
	for (int j = i; j <= L.length - 1; j++)
	{
		L.address[j - 1] = L.address[j];
	}
	--L.length;
	printf("删除成功");
	system("PAUSE");
	system("cls");
}

void InitSqList(SqList& L, int n)   // 传入初始化好的顺序表地址，以及要录入学生的人数 
{
	int m, i;
	printf("请输入 学号 姓名 成绩\n");
	for (i = 0; i < n; i++)
	{
		m = 1;
		printf("请输入第%d位学生的信息\n", i + 1);
		printf("学号：");
		while (m)
		{
			scanf("%d", &L.address[i].no);
			if (L.address[i].no < 0)
			{
				printf("i值不合法\n请重新输入第%d位学生的学号：", i + 1);
			}
			else m = 0;
		}
		printf("姓名：");
		m++;
		while (m)
		{
			scanf("%s", &L.address[i].name);
			if (L.address[i].name < 0)
			{
				printf("i值不合法\n请重新输入第%d位学生的姓名：", i + 1);
			}
			else m = 0;
		}
		printf("成绩: ");
		m++;
		while (m)
		{
			scanf("%f", &L.address[i].price);
			if (L.address[i].price < 0)
			{
				printf("您输入的成绩不合法\n请重新输入第%d位学生的成绩：", i + 1);
			}
			else m = 0;
		}
	}
	L.length = n + L.length;
	printf("录入信息成功。");
	system("PAUSE"); //防止窗口关闭
	system("cls"); //清屏 
}
void OutSqList(SqList& L)
{
	system("cls");
	printf("学生信息：");
	printf("学号            姓名            成绩\n");
	for (int i = 0; i < L.length; i++)
	{
		printf("\t%d", L.address[i].no);
		printf("\t\t%s", L.address[i].name);
		printf("\t\t%f", L.address[i].price);
		printf("\n");
	}
	printf("共有%d人\n", L.length);
	system("PAUSE");
	system("cls");
}

void Display()
{
    printf("\n\n");
	printf("-------------------");
	printf("学生信息查询系统-------------------\n");
	printf("1.信息添加\n");
	printf("2.信息删除\n");
	printf("3.显示信息\n");
	printf("4.插入信息\n");
	printf("5.查找信息\n");
    printf("--------------------------------------");
	printf("\n\n");
}

int main(void) {
	int op, n;
	SqList L;
	InitList(L);  //初始化顺序表 
	while (1) {
		Display();
		printf("请选择功能：");
		scanf("%d", &op);
		switch (op) {
		case 1:
			system("cls");
			printf("请输入录入人数：");
			scanf("%d", &n);
			InitSqList(L, n);
			break;
		case 2:
			int m;
			system("cls");
			printf("请输入删除的学生信息:");
			scanf("%d", &m);
			ListDelete(L, m);
			break;
		case 3:
			OutSqList(L);
			break;
		case 4:
			int i;
			printf("请输入要在第几个位置插入：");
			scanf("%d", &i);
			ListInsert(L, i);
			system("PUASE");
			system("cls");
			break;
		case 5:
			int n, q;
			char e[20];
			system("cls");
			printf("1.姓名查找\n");
			printf("2.位置查找\n");
			printf("请输入需要进行查找的类型:");
			scanf("%d", &n);
			if (n == 1)
			{
				printf("请输入要查找的姓名:");
				scanf("%s", &e);
				FindElem(L, e);
			}
			else
			{
				printf("请输入要查找的序号:");
				scanf("%d", &q);
				LocateElem(L, q);
			}

		}
	}
}