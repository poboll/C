#include <algorithm>
#include <vector>
#include <iostream>

int main() {
	std::vector<int> vec = {5, 2, 8, 3, 1};
	std::sort(vec.begin(), vec.end());
	for (int num : vec) {
		std::cout << num << " ";
	}
	return 0;
}
// 输出结果：1 2 3 5 8

