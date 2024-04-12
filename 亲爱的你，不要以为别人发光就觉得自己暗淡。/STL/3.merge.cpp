#include <algorithm>
#include <vector>
#include <iostream>

int main() {
	std::vector<int> vec1 = {1, 3, 5};
	std::vector<int> vec2 = {2, 4, 6};
	std::vector<int> merged(vec1.size() + vec2.size());
	std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), merged.begin());
	for (int num : merged) {
		std::cout << num << " ";
	}
	return 0;
}
// 输出结果：1 2 3 4 5 6

