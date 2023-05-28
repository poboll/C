#include<stdio.h>
void hh(int n);
int main() {
    int n;
    n = 1;
    void hh(int n);
    printf("%d", n);
    return 0;
}
void hh(int n){
    n = 10;
    printf("%d", n);
}