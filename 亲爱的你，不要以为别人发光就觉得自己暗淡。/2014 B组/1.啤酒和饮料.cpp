//A 啤酒和饮料
//题目描述：
//啤酒每罐2.3元，饮料每罐1.9元。小明买了若干啤酒和饮料，一共花了82.3元。我们还知道他买的啤酒比饮料的数量少，请你计算他买了几罐啤酒。
//分析分析：
//对于这种题目，我最喜欢的就是暴力了，直接模拟运算
#include <stdio.h>

int main() {
	float beer_price = 2.3;
	float drink_price = 1.9;
	float total_cost = 82.3;
	int beer_count, drink_count;
	
	for (beer_count = 0; beer_count <= total_cost / beer_price; beer_count++) {
		float current_cost = beer_count * beer_price;
		drink_count = (total_cost - current_cost) / drink_price;
		if (current_cost + drink_count * drink_price == total_cost && beer_count < drink_count) {
			printf("%d\n", beer_count); // 11
			break;
		}
	}
	
	return 0;
}

