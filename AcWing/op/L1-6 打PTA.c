/*L1-6 打PTA
传说这是集美大学的学生对话。本题要求你做一个简单的自动问答机，对任何一个问句，只要其中包含 PTA 就回答 Yes!，其他一概回答 No.。
输入格式：
输入第一行给出一个整型范围内的正整数 N，随后 N 行，每行给出一个长度不超过 80 的字符串，为用户输入的句子，由英文字母、数字、空格和标点符号组成，以回车结束。
输出格式：
对每一行句子，如果其结尾字符为问号 ? 则判断此句中有无 PTA？如果有则在一行中输出 Yes!，否则输出 No.。如果不是问号结尾，则敷衍地回答 enen。
输入样例：
Hello!
Do you still play WZRY?
Chi Ji?
you play PTA ah?
how about pta site?
输出样例：
enen
No.
No.
Yes!
No.
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB*/
#include <stdio.h>
