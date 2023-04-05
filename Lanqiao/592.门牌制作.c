#include <stdio.h>
#include <stdlib.h>
int main() {
    int count = 0;
    for(int i = 0; i <= 2020; i ++) {
        for(int j = i; j > 0; j /= 10) {
            if(j % 10 == 2) {
                count ++;
            }
        }
    }
    printf("%d", count);
    return 0;
}