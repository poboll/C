/*浮点数二分*/
#include<iostream>
using namespace std;
int main() {
    double x;
    cin >> x;
    double l = 0, r = x;
    //不用精度表示（精度足够小就停止）
    //for (int i = 0; i < 100; i ++)开一百次方-->极小
    while (r - l >1e-8) {//保留四位小数-1e-6 永远多2 一直做
        double  mid = (l + r) / 2;//每次求中点
        if (mid * mid >= x) r = mid;
        else l = mid;
    }
    printf("%lf\n",l);
    return 0;
}