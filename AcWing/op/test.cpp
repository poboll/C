//
// Created by 大妖怪 on 2023/11/6.
//
#include <iostream>
using namespace std;
int main (void) {
     int n = 3;
     while (n) {
         printf("%2d is true\n", n--);
     }
     printf("%2d is false\n", n);

     n= -3;
     while (n) {
         printf("%2d is true\n", n++);
     }
     printf("%2d is false\n", n);

     return 0;
}