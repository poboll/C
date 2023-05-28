#include<stdio.h>

void hh(int *n);

int main() {
    int n = 1;
    hh(&n);
    printf("%d", n);
    return 0;
}

void hh(int *n){
    *n = 10;
    printf("%d", *n);
}
