/*	��ʮһ��ʵ�鱨��
	ʵ��Ŀ��
		(1)���սṹ�����Ļ���ʹ�÷�����
		(2)���սṹ����Ļ���ʹ�÷�����
		(3)���սṹ�ļ�Ƕ��Ӧ�á�
		(4)���սṹָ��ĸ���Լ��ṹָ����Ϊ���������ı�̷�����

	ʵ������
		����ƽ���ɼ�������һ��ѧ���Ľṹ��¼��Ҫ�����ѧ�š������ͳɼ�����������n(n<10)��������n��ѧ���Ļ�����Ϣ��Ҫ����㲢������ǵ�ƽ���ɼ�(����2λС��)���Ա�д��Ӧ����
*/

#include <stdio.h>

struct student
{
	int id;          // ѧ��
	char name[64];   // ����
	float score;     // �ɼ�
};

int main()
{
	// ����һ���ṹ���������洢ѧ������Ϣ
	struct student students[10];

	// ����ѧ���ĸ���
	int n;
	printf("������ѧ���ĸ�����");
	scanf("%d", &n);

	// ѭ������ÿ��ѧ������Ϣ
	for (int i = 0; i < n; i++)
	{
		printf("������� %d ��ѧ����ѧ�š������ͳɼ���", i + 1);
		scanf("%d %s %f", &students[i].id, students[i].name, &students[i].score);
	}

	// ��������ѧ����ƽ���ɼ�
	float total = 0;
	for (int i = 0; i < n; i++)
	{
		total += students[i].score;
	}
	float average = total / n;

	// ���ƽ���ɼ�
	printf("����ѧ����ƽ���ɼ��ǣ�%.2f\n", average);

	return 0;
}
