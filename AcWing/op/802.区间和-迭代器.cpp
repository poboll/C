#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
const int N = 300010;
//设置一个离散数据连续化之后存储add操作数据的数组a[N]，以及其前缀和数组s[N]
int a[N],s[N];
//定义一个vector数组把所有题目中操作涉及到的下标存储进去
vector<int>alls;
//定义一个数对类型来表示每次的加c操作和询问
typedef pair<int,int> PII;
//设置一个vector数组来存储每次的加c操作和询问操作的数对（数对作为一个基本元素,vector数组是存储若干个这样的数对）
vector<PII>add, query;
//默写一下二分模板 待会要用
int find(int x) {
    int l = 0,r = alls.size() - 1;
    while (l<r) {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;//也可以返回r r+1是将数据离散化成1,2,3,4...n(从1开始，而不是从0开始)
}
vector<int>::iterator unique(vector<int> &a) {
    int j = 0;
    for (int i = 0; i < a.size(); i ++) {
        if(!i || a[i] != a[i - 1]) {
            a[j ++ ] = a[i];
        }
    }
    return a.begin() + j;
}
int main() {
    cin >> n >> m;
    //现在开始循环执行n次加c操作，初始化add和alls数组
    for (int i = 0; i < n; i ++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    //现在开始循环执行m次询问操作，初始化query和alls数组
    for (int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    //然后我们开始对alls数组进行排序和去重
    //这里补充一下，alls数组存在的意义其实为了将下标排序，看每次的l和r之间有哪些x是在里面的
    //这些离散的x在连续化映射之后得到的值就会作为之后利用a[N]前缀和求和的下标依据
    sort(alls.begin(),alls.end());//排序
    alls.erase(unique(alls),alls.end());//去重。unique函数是ctl中自带的函数
    //现在我们开始处理并统计数轴中经过add操作之后不是0的那些部分
    //也就是初始化a数组，把原来数轴中不为0的那些位置上的数字统计过来
    //存储的下标x依据就是利用二分来寻找其在alls数组中的相对位置
    for (auto item:add) {
        int x = find(item.first);
        a[x] += item.second;
    }
    //预处理前缀和，这一步是用来求最后[l,r]区间的依据
    for (int i = 1; i <= alls.size(); i ++) s[i] = s[i-1]+a[i];
    //处理询问
    for (auto item:query) {
        //item.first和item.second其实就是原来键盘中输入的每次询问的l和r
        //下面的l和r是经过映射之后的下标
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l-1] << endl;
    }
    return 0;
}