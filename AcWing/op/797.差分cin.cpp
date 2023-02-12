#include <iostream>
using namespace std;
const int N = 100010;
int a[N], d[N];
int n, m, l, r, c;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        d[i] += a[i]; 
        if (i + 1 < n)
            d[i + 1] -= a[i];
    }
    while (m--) {
        cin >> l >> r >> c;
        d[l - 1] += c;
        d[r] -= c;
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += d[i];
        printf("%d ", s);
    }
    return 0;
}
