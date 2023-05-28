1、Qt Creator 新建一个纯C++的项目，在项目文件配置：CONFIG += c++11
2、终端，g++ xxx.cpp  -std=c++11

在C中，auto修饰局部变量，局部变量也叫auto变量，自动变量
{
	int a;
	auto int a;
}

C++11, auto根据用户初始化内容自动推导类型

#include <iostream>
using namespace std;


int main()
{



    return 0;
}

