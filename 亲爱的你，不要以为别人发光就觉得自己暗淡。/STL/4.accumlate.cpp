#include <numeric>
#include <vector>
#include <iostream>

int main() {
	std::vector<int> vec = {1, 2, 3, 4, 5};
	int sum = std::accumulate(vec.begin(), vec.end(), 0);
	std::cout << "Sum: " << sum;
	return 0;
}
// 输出结果：Sum: 15

