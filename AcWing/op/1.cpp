#include<cstring>
#include<iostream>
using namespace std;
//我们哈希表的存储应尽可能采用质数
//因此这里我们需要找一个比比100000大的最小质数
int main()
{
    for(int i = 100000; ;i++) {
        bool flag = true;
        for(int j = 2; j * j < i; j ++) {
            if(i % j == 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << i;
            break;
        }
    }
    return 0;
}