//使用C++STL函数中queue函数实现
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	while (1) {
		int n;
        printf("请输入要打印的层数：");
		scanf("%d", &n);
		queue<int>q;//队列
		q.push(1);//存1
		for (int i = 1; i <= n; i++) { 
			int front = q.front();
			int back = q.back();
			int cnt;//层数
			//如果只有一层
			if (i == 1) {
				for (int j = 0; j < n - i; j++)
					cout << " ";
				cout << q.front() << endl;
				q.push(front);
				q.push(back);
				q.pop();
				continue;
			}
			cnt = i - 1;
			q.push(front);//进队
			for (int j = 0; j < n - i; j++)
				cout << " ";
			while (cnt--) {
				int temp = q.front();
				cout << temp << " ";
				q.pop();
				q.push(temp + q.front());
			}
			cout << q.front() << " " << endl;
			q.pop();
			q.push(back);
		}
	}
	return 0;
}