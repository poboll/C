//
// Created by 大妖怪 on 2024/3/14.
//
// P1055[NOIP2008 普及组] ISBN 号码
// 题目描述
// 每一本正式出版的图书都有一个 ISBN 号码与之对应，ISBN 码包括 $9$ 位数字、$1$ 位识别码和 $3$ 位分隔符，其规定格式如 `x-xxx-xxxxx-x`，其中符号 `-` 就是分隔符（键盘上的减号），最后一位是识别码，例如 `0-670-82162-4`就是一个标准的 ISBN 码。ISBN 码的首位数字表示书籍的出版语言，例如 $0$ 代表英语；第一个分隔符 `-` 之后的三位数字代表出版社，例如 $670$ 代表维京出版社；第二个分隔符后的五位数字代表该书在该出版社的编号；最后一位为识别码。
// 识别码的计算方法如下：
// 首位数字乘以 $1$ 加上次位数字乘以 $2$ ……以此类推，用所得的结果 $ \bmod 11$，所得的余数即为识别码，如果余数为 $10$，则识别码为大写字母 $X$。例如 ISBN 号码 `0-670-82162-4` 中的识别码 $4$ 是这样得到的：对 `067082162` 这 $9$ 个数字，从左至右，分别乘以 $1,2,\dots,9$ 再求和，即 $0\times 1+6\times 2+……+2\times 9=158$，然后取 $158 \bmod 11$ 的结果 $4$ 作为识别码。
// 你的任务是编写程序判断输入的 ISBN 号码中识别码是否正确，如果正确，则仅输出 `Right`；如果错误，则输出你认为是正确的 ISBN 号码。
// 输入格式
// 一个字符序列，表示一本书的 ISBN 号码（保证输入符合 ISBN 号码的格式要求）。
// 输出格式
// 一行，假如输入的 ISBN 号码的识别码正确，那么输出 `Right`，否则，按照规定的格式，输出正确的 ISBN 号码（包括分隔符 `-`）。
// 样例输入1
// 0-670-82162-4
// 样例输出1
// Right
// 样例输入2
// 0-670-82162-0
// 样例输出2
// 0-670-82162-4
#include <iostream>
#include <string>
using namespace std;

int main() {
    string isbn;
    cin >> isbn;

    int sum = 0;
    int count = 1;
    for (int i = 0; i < isbn.length(); i++) {
        if (isdigit(isbn[i])) {
            sum += (isbn[i] - '0') * count;
            count++;
        }
    }

    int mod = sum % 11;
    char correct_check_digit;
    if (mod == 10) {
        correct_check_digit = 'X';
    } else {
        correct_check_digit = mod + '0';
    }

    if (correct_check_digit == isbn[isbn.length() - 1]) {
        cout << "Right" << endl;
    } else {
        isbn[isbn.length() - 1] = correct_check_digit;
        cout << isbn << endl;
    }

    return 0;
}