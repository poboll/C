/*792.高精度减法
给定两个正整数（不含前导0），计算它们的差，计算结果可能为负数。
输入格式
共两行，每行包含一个整数。
输出格式
共一行，包含所求的差。
数据范围
1≤整数长度≤10^5
输入样例：
32
11
输出样例：
21
*/
/*vector是一种顺序容器，事实上和数组差不多，但它比数组更优越。一般来说数组不能动态拓展，因此在程序运行的时候不是浪费内存，就是造成越界。而vector正好弥补了这个缺陷，它的特征是相当于可分配拓展的数组，它的随机访问快，在中间插入和删除慢，但在末端插入和删除快，而且如果用.at()访问的话，也可以做越界检查。
v.push_back(t)  //在数组的最后添加一个值为t的数据
v.size()   //当前使用数据的大小
v.pop_back();  // 弹出容器中最后一个元素（容器必须非空）
v.back();   // 返回容器中最后一个元素的引用
*/
#include <iostream>
#include <vector>
using namespace std;
//判断是否有 A >=B
bool cmp(vector<int> &A, vector<int> &B) {//判断A,B大小关系
    if (A.size() != B.size()) return A.size() > B.size();//直接ruturn 了就不用else
    for (int i = A.size() - 1; i >= 0; i --) {
        if(A[i] != B[i]) {
            return A[i] > B[i];//逐位看A和B哪个数较大
        }
    }
    return true;//所有都相等返回true
}
// C = A + B
vector<int> sub(vector<int> &A, vector<int> &B) {//C++11新特性  添加引用-->提高效率
    vector<int> C;
    for(int i = 0, t = 0; i < A.size(); i ++ ) {
        t = A[i] - t;//t表示进位
        if (i < B.size()) t -= B[i];//判断B是否还存在
        C.push_back((t + 10) % 10);
        // 若t>=0,则返回t，若小于0则表示借位需+10，合并即为(t + 10) % 10 )
        if (t < 0) t = 1;
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();//去掉前导0，如果c=0则不能去掉该0；
    }
    return C;
}
int main() {
    string a, b;//定义字符串a，b
    vector<int> A, B;//定义数组A,B
    cin >> a >> b; //输入两个数a，b    a = "123456"
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');// A = [6, 5, 4, 3, 2, 1]  把字符串中字符变为整型数字并逆序存入数组
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');
    if (cmp(A, B)) {
        auto C = sub(A , B);//调用函数，返回和存入数组C。auto编译器自己推断类型等价于 vector<int> C
        for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);//遍历输出C中元素即为两数差
    } else {//当A<B时计算B-A在前边添加负号即可
        auto C = sub(B, A);
        printf("-");
        for(int i = C.size() - 1; i >= 0; i --) {
          printf("%d",C[i]);
        }
    }
    return 0;
}