#include<stdio.h>
int main(void) {
    int x;
    int y;
    int h;
    h = (y = 8, y + 1, x = y, x + 1);
    printf("%d", h);
    return 0;
}
