//
// Created by 大妖怪 on 2023/12/11.
//
// 问题 1
// 请输出 I love Luogu!
// 问题 2
// 这里有10 个苹果，小 A 拿走了2 个，Uim 拿走了 4 个，八尾勇拿走剩下的所有的苹果。我们想知道：
// 小A 和 Uim 两个人一共拿走多少苹果？
// 八尾勇能拿走多少苹果？
// 现在需要编写一个程序，输出两个数字作为答案，中间使用空格分开。
// 问题 3
// 现在有14 个苹果。要均分给 4 名同学，分不掉的苹果放回冰箱。请问：
// 每位同学能分得几个苹果？
// 一共分出去多少苹果？
// 把几个苹果放回冰箱？
// 现在需要编写一个程序，输出三个数字作为答案，每个数字一行。
// 问题 4
// 现在有500 毫升的肥宅快乐水，要均分给 3 名同学，每位同学可以分到多少毫升？请输出一个数字作为输出。保留 6 位有效数字，且不使用科学计数法。
// 问题 5
// 甲列火车长 260 米，每秒行 12 米；乙列火车长 220 米，每秒行 20 米，两车相向而行，从两车车头相遇时开始计时，多长时间后两车车尾相离？已知答案是整数。
// 问题 6
// 一个长方形长宽分别是6 cm、9 cm，求它的对角线长度（cm）。直接使用 cout 输出。
// 问题 7
// Uim 银行账户里面有 100 元。经过了下面的操作：往里面存了 10 元；购物花掉了 20 元；把里面的钱全部取出。请在每次操作后输出账户余额，并使用换行符隔开。
// 问题 8
// 当半径为r=5，请输出圆的周长、面积和球体积。取π=3.141593。请直接使用 cout 输出答案，每行一个数字。
// 问题 9
// 一只小猴买了若干个桃子。第一天他刚好吃了这些桃子的一半，又贪嘴多吃了一个；第二天他也刚好吃了剩余桃子的一半，贪嘴多吃了一个；第三天他又刚好吃了剩下的桃子的一半，并贪嘴多吃了一个。第四天起来一看，发现桃子只剩下一个了。请问小猴买了几个桃子？
// 问题 10
// 洛谷的评测任务是单位时间内均匀增加的。
// 8 台评测机 30 分钟可以刚好把评测队列中的程序评测完毕，10 台评测机 6 分钟可以刚好把评测队列中的程序评测完毕，请问几台评测机可以在 10 分钟时刚好把评测队列中的程序评测完毕？
// 问题 11
// 小 A 跑步速度
// 5
// m/s
// 5 m/s，八尾勇跑步速度
// 8
// m/s
// 8 m/s，八尾勇在小 A 后面
// 100
// m
// 100 m，他们同时起跑，请问需要多长时间八尾勇可以追上小 A？输出一个数字表示答案，使用 cout 直接输出。
// 
// 问题 12
// 大家都知道有 26 个英文字母，其中 A 是第一个字母。现在请编程求出：
// M 是字母表中的第几个字母？
// 第 18 个字母是什么？
// 输出一个数字和一个字母，使用换行隔开。
// 问题 13
// 小 A 有两块球形橡皮泥，一个半径是4，一个半径是10。他想把这两块橡皮泥揉在一起，然后塑造成一个正方体，请问这个正方体的棱长是多少？如果结果不是整数，则舍去小数点之后的数字。取π=3.141593。
// 问题 14
// 根据咕咕网校的预测，当课程定价为 110 元时，会有 10 人报名。如果课程价格每降低 1 元，就会多 1 名报名者（反之亦然）。如果希望总共能收到 3500 元学费的话，那么应该定价多少呢？已知本题有两个答案符合要求，则取较小的那一个。如果这个答案不是整数，则需四舍五入精确到整数。
// 输入输出样例
// 输入
// 2
// 输出
// 6 4
#include <cstdio>
#include <cmath>

int main() {
    int T;
    scanf("%d", &T);
    if (T == 1) {
        printf("I love Luogu!\n");
    } else if (T == 2) {
        printf("%d %d\n", 2 + 4, 10 - 2 - 4);
    } else if (T == 3) {
        int apples = 14;
        int students = 4;
        int applesPerStudent = apples / students;
        int remainingApples = apples % students;
        printf("%d\n", applesPerStudent);
        printf("%d\n", apples - remainingApples);
        printf("%d\n", remainingApples);
    } else if (T == 4) {
        int totalVolume = 500;
        int numStudents = 3;
        int volumePerStudent = totalVolume / numStudents;
        printf("%.6f\n", static_cast<double>(volumePerStudent));
    } else if (T == 5) {
        int trainALength = 260;
        int trainASpeed = 12;
        int trainBLength = 220;
        int trainBSpeed = 20;
        int distance = trainALength + trainBLength;
        int relativeSpeed = trainASpeed + trainBSpeed;
        int time = distance / relativeSpeed;
        printf("%d\n", time);
    } else if (T == 6) {
        int length = 6;
        int width = 9;
        double diagonal = sqrt(length * length + width * width);
        printf("%.6f\n", diagonal);
    } else if (T == 7) {
        int balance = 100;
        printf("%d\n", balance);
        balance += 10;
        printf("%d\n", balance);
        balance -= 20;
        printf("%d\n", balance);
        balance = 0;
        printf("%d\n", balance);
    } else if (T == 8) {
        double radius = 5.0;
        double pi = 3.141593;
        double circumference = 2 * pi * radius;
        double area = pi * radius * radius;
        double volume = (4.0 / 3.0) * pi * radius * radius * radius;
        printf("%.6f\n", circumference);
        printf("%.6f\n", area);
        printf("%.6f\n", volume);
    } else if (T == 9) {
        int peaches = 1;
        while (true) {
            int temp = peaches;
            for (int i = 0; i < 3; i++) {
                if (temp % 2 != 0) {
                    break;
                }
                temp /= 2;
            }
            if (temp == 1) {
                break;
            }
            peaches++;
        }
        printf("%d\n", peaches);
    } else if (T == 10) {
        int totalTime = 10;
        int numMachines = 8;
        int timePerMachine = 30;
        int numMachinesNeeded = (totalTime * numMachines) / timePerMachine;
        printf("%d\n", numMachinesNeeded);
    } else if (T == 11) {
        int speedA = 5;
        int speedB = 8;
        int distance = 100;
        int time = distance / (speedB - speedA);
        printf("%d\n", time);
    } else if (T == 12) {
        int positionM = 13;
        char letter18 = 'R';
        printf("%d\n", positionM);
        printf("%c\n", letter18);
    } else if (T == 13) {
        double radius1 = 4.0;
        double radius2 = 10.0;
        double volume1 = (4.0 / 3.0) * 3.141593 * radius1 * radius1 * radius1;
        double volume2 = (4.0 / 3.0) * 3.141593 * radius2 * radius2 * radius2;
        double side = pow((volume1 + volume2), 1.0 / 3.0);
        int sideInt = static_cast<int>(side);
        printf("%d\n", sideInt);
    } else if (T == 14) {
        int price = 110;
        int numSignups = 10;
        int targetRevenue = 3500;
        int numCourses = targetRevenue / price;
        while (numCourses - numSignups < 0) {
            price--;
            numCourses = targetRevenue / price;
        }
        printf("%d\n", price);
    }
    return 0;
}
