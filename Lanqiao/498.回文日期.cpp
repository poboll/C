#include <iostream>
using namespace std;
int main() {
  // 请在此输入您的代码
    int i, n, a, b, c, d, e, f, g, h;
    int j = 0;
    scanf("%d", &n);
    for(i = n + 1; i <= 99999999;i ++) {
        a = i % 10;
        b = (i / 10) % 10;
        c = (i / 100) % 10;
        d = (i / 1000) % 10;
        e = (i / 10000) % 10;
        f = (i / 100000) % 10;
        g = (i / 1000000) % 10;
        h = (i / 10000000) % 10;
        if((a == h) && (b == g) && (c == f) && (d == e)) {
            if(j == 0) {
                printf("%d\n", i);
                j ++;
            }
        }
        if((a == h) && (b == g) && (c == f) && (d == e) && (a == c) && (b == d)) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}