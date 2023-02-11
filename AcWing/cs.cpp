#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> add(vector<int> &A, vector<int> &B){
    if (A.size() < B.size()) return add(B,A);//若a<b，则交换位置
    
    vector<int> C;                            //定义数组C存两数之和
    int t = 0;                                //
    for (int i =0; i < A.size(); i++){
        t +=A[i];                              //按位做加法
        if (i < B.size()) t+=B[i];             //B的高位全加进去
        C.push_back(t%10);                     //t存储该位a，b和模10即为结果
        t /= 10;                               //t存储进位为0或1
    }
    if (t) C.push_back(t);
    return C;
}
 
int main(){
    string a,b;                //定义字符串a，b
    vector<int> A,B;           //定义数组A,B
    cin >> a >> b;             //输入两个数a，b   
    for(int i =a.size() - 1;i >=0;i--)    
        A.push_back(a[i] - '0');        //把字符串中字符变为整型数字并逆序存入数组
    for(int i =b.size() - 1;i >=0;i--) 
        B.push_back(b[i] - '0');
    vector<int> C = add(A,B);           //调用函数，返回和存入数组C
    for (int i = C.size() - 1; i>= 0; i--) //遍历输出C中元素即为两数和
        cout << C[i] ;
        return 0;
}
 
 
 