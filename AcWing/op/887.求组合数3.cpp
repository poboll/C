//
// Created by 大妖怪 on 2023/9/20.
//
#include <iostream>

int main() {
    int sum = 0;
    for (int i = 3; i < 100; i += 3) {
        sum += i;
    }
    std::cout << "100以内的3倍数之和为: " << sum << std::endl;

    return 0;
}
