//G 六角填数
//题目描述：
//如图【1.png】所示六角形中，填入1~12的数字。
//使得每条直线上的数字之和都相同。
//图中，已经替你填好了3个数字，请你计算星号位置所代表的数字是多少？
//
//分析分析：
//嘿嘿，我们的全排列来了
//不过在全排列之前，我们可以知道每一条他们相加的和是26喔！
//因为我们一共只有6条线，我们所有的和是78（1到12）
//但是注意我们每一个和都算了两遍，78*2/6=26
//题目代码：
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

bool next_permutation(int *a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) {
		i--;
	}
	if (i <= 0) return false;
	int j = n - 1;
	while (a[j] <= a[i - 1]) {
		j--;
	}
	swap(&a[i - 1], &a[j]);
	j = n - 1;
	while (i < j) {
		swap(&a[i], &a[j]);
		i++;
		j--;
	}
	return true;
}

int main() {
	int a[9] = {2, 4, 5, 6, 7, 9, 10, 11, 12};
	while (next_permutation(a, 9)) {
		if ((8 + a[0] + a[1] + a[2]) == 26 &&
			(1 + a[0] + a[3] + a[5]) == 26 &&
			(1 + a[1] + a[4] + a[8]) == 26 &&
			(8 + a[3] + a[6] + 3) == 26 &&
			(3 + a[2] + a[4] + a[7]) == 26 &&
			(a[5] + a[6] + a[7] + a[8]) == 26) {
			for (int i = 0; i < 9; i++) {
				printf("%d ", a[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
