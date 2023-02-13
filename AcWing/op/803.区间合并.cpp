/*803.区间合并
给定n个区间[l, r]。
合并所有有交集的区间。
输出合并完成后的区间个数。
例如：[1,3]和[2,6]可以合并为一个区间[1,6]。
输入格式
第一行包含整数n。
接下来n行，每行包含两个整数 l 和 r。
输出格式
共一行，包含一个整数，表示合并区间完成后的区间个数。
样例
输入样例：
5
1 2
2 4
5 6
7 8
7 9
输出样例：
3
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;// 优先以左端点排序
const int N = 1e5 + 10;
int n;
vector<PII> segs;
void merge(vector<PII> &segs) {
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for (auto seg : segs) {
        if (ed < seg.first) {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);
    }
    if (st != -2e9) res.push_back({st,ed});
    segs = res;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l,r});
    }
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}