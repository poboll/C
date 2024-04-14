#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 获取字符串长度的辅助函数
int stringLength(char *str) {
	return strlen(str);
}

// 贪心合并字符串
int mergeStrings(char *strings[], int n) {
	int cost = 0;
	while (n > 1) {
		// 找到两个最短的字符串
		int min1 = 0, min2 = 1;
		for (int i = 2; i < n; i++) {
			if (stringLength(strings[i]) < stringLength(strings[min1])) {
				min2 = min1;
				min1 = i;
			} else if (stringLength(strings[i]) < stringLength(strings[min2])) {
				min2 = i;
			}
		}
		
		// 合并两个字符串
		char *newString = (char *)malloc((stringLength(strings[min1]) + stringLength(strings[min2]) + 1) * sizeof(char));
		strcpy(newString, strings[min1]);
		strcat(newString, strings[min2]);
		
		// 更新成本
		cost += stringLength(strings[min1]) + stringLength(strings[min2]);
		
		// 打印合并步骤
		printf("合并 '%s' 和 '%s' 得到 '%s'\n", strings[min1], strings[min2], newString);
		
		// 将合并后的字符串放入数组中
		strings[min1] = newString;
		strings[min2] = strings[--n];
	}
	
	return cost;
}

int main() {
	char *strings[] = {"红色", "蓝色", "黄色"};
	int n = sizeof(strings) / sizeof(strings[0]);
	
	int minCost = mergeStrings(strings, n);
	printf("合并字符串的最小成本：%d\n", minCost);
	
	return 0;
}

