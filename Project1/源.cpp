/*	第十一次实验报告
	实验目的
		(1)掌握结构变量的基本使用方法。
		(2)掌握结构数组的基本使用方法。
		(3)掌握结构的简单嵌套应用。
		(4)掌握结构指针的概念，以及结构指针作为函数参数的编程方法。

	实验内容
		计算平均成绩：建立一个学生的结构记录，要求包括学号、姓名和成绩。输入整数n(n<10)，再输入n个学生的基本信息，要求计算并输出他们的平均成绩(保留2位小数)。试编写相应程序。
*/

#include <stdio.h>

struct student
{
	int id;          // 学号
	char name[64];   // 姓名
	float score;     // 成绩
};

int main()
{
	// 定义一个结构体数组来存储学生的信息
	struct student students[10];

	// 读入学生的个数
	int n;
	printf("请输入学生的个数：");
	scanf("%d", &n);

	// 循环读入每个学生的信息
	for (int i = 0; i < n; i++)
	{
		printf("请输入第 %d 个学生的学号、姓名和成绩：", i + 1);
		scanf("%d %s %f", &students[i].id, students[i].name, &students[i].score);
	}

	// 计算所有学生的平均成绩
	float total = 0;
	for (int i = 0; i < n; i++)
	{
		total += students[i].score;
	}
	float average = total / n;

	// 输出平均成绩
	printf("所有学生的平均成绩是：%.2f\n", average);

	return 0;
}
