/*
                                ^....0
                               ^ .1 ^1^
                               ..     01
                              1.^     1.0
                             ^ 1  ^    ^0.1
                             1 ^        ^..^
                             0.           ^ 0^
                             .0            1 .^
                             .1             ^0 .........001^
                             .1               1. .111100....01^
                             00                 11^        ^1. .1^
                             1.^                              ^0  0^
                               .^                                 ^0..1
                               .1                                   1..^
                             1 .0                                     ^  ^
                              00.                                     ^^0.^
                              ^ 0                                     ^^110.^
                          0   0 ^                                     ^^^10.01
                   ^^     10  1 1                                      ^^^1110.1
                   01     10  1.1                                      ^^^1111110
                   010    01  ^^                                        ^^^1111^1.^           ^^^
                   10  10^ 0^ 1                                            ^^111^^^0.1^       1....^
                    11     0                                               ^^11^^^ 0..  ....1^   ^ ^
                    1.     0^                                               ^11^^^ ^ 1 111^     ^ 0.
                   10   00 11                                               ^^^^^   1 0           1.
                   0^  ^0  ^0                                                ^^^^    0            0.
                   0^  1.0  .^                                               ^^^^    1 1          .0
                   ^.^  ^^  0^                             ^1                ^^^^     0.         ^.1
                   1 ^      11                             1.                ^^^     ^ ^        ..^
                  ^..^      ^1                             ^.^               ^^^       .0       ^.0
                  0..^      ^0                              01               ^^^       ..      0..^
                 1 ..        .1                             ^.^              ^^^       1 ^  ^0001
                ^  1.        00                              0.             ^^^        ^.0 ^.1
                . 0^.        ^.^                             ^.^            ^^^         ..0.0
               1 .^^.         .^                  1001        ^^            ^^^         . 1^
               . ^ ^.         11                0.    1         ^           ^^          0.
                0  ^.          0              ^0       1                   ^^^          0.
              0.^  1.          0^             0       .1                   ^^^          ..
              .1   1.          00            .        .1                  ^^^           ..
             1      1.         ^.           0         .^                  ^^            ..
             0.     1.          .^          .         0                                  .
             .1     1.          01          .        .                                 ^ 0
            ^.^     00          ^0          1.       ^                                 1 1
            .0      00           .            ^^^^^^                                   .
            .^      00           01                                                    ..
           1.       00           10                                                   1 ^
          ^.1       00           ^.                                            ^^^    .1
          ..        00            .1                                        1..01    ..
         1.1         00           1.                                       ..^      10
        ^ 1^         00           ^.1                                      0 1      1
        .1           00            00                                       ^  1   ^
         .           00            ^.^                                        10^  ^^
       1.1           00             00                                              10^
       ..^           1.             ^.                                               1.
      0 1            ^.              00                 00                            .^
        ^            ^.              ^ 1                00   ^0000^     ^               01
     1 0             ^.               00.0^              ^00000   1.00.1              11
     . 1              0               1^^0.01                      ^^^                01
      .^              ^                1   1^^                                       ^.^
    1 1                                                                              0.
    ..                                                                              1 ^
     1                                                                               1
   ^ ^                                                                             .0
   1                                                                             ^ 1
   ..                                                          1.1            ^0.0
  ^ 0                                                           1..01^^100000..0^
  1 1                                                            ^ 1 ^^1111^ ^^
  0 ^                                                             ^ 1      1000^
  .1                                                               ^.^     .   00
  ..                                                                1.1    0.   0
  1.                                                                  .    1.   .^
  1.                                                                 1    1.   ^0
 ^ .                                                                 ^.1 00    01
 ^.0                                                                  001.     .^
 */
// VB_king —— 2016_Finals_B_C++_3.cpp created by VB_KoKing on 2019-05-19:23.
/* Procedural objectives：

 Variables required by the program:

 Procedural thinking：
 程序的第一个循环处理的是可以跳的情况，第二个循环处理的是可以走的情况，而在while循环中都是先把能跳的处理完之后在处理能走的；
 需要填空的地方代表可以走但是不走的情况，对比源程序走法和正确走法：

 源程序走法为：
AA.ABBB
AABA.BB
AAB.ABB 
A.BAABB
.ABAABB
BA.AABB
B.AAABB 
 正确的走法为：
AA.ABBB
AABA.BB
AABAB.B 
AAB.BAB 
A.BABAB
.ABABAB 
BA.ABAB  
BABA.AB 
BABABA. 
BABAB.A 
BAB.BAA
B.BABAA 
BB.ABAA
BBBA.AA 
BBB.AAA

这个规律比较诡异，当左右两边的字母不相同（"."不算在内）时，可以移动的那个字母；当左右两边的字母相同时，可以移动但不要移动。
 Functions required by the program:
 
 Determination algorithm:
 
 Determining data structure:
 

*/
/* My dear Max said：
"I like you,
So the first bunch of sunshine I saw in the morning is you,
The first gentle breeze that passed through my ear is you,
The first star I see is also you.
The world I see is all your shadow."

FIGHTING FOR OUR FUTURE！！！
*/
#include <stdio.h>
#include <string.h>

void move(char* data, int from, int to)
{
    data[to] = data[from];
    data[from] = '.';
}

int valid(char* data, int k)
{
    if(k<0 || k>=strlen(data)) return 0;
    return 1;
}

void f(char* data)
{
    int i;
    int tag;
    int dd = 0; // 移动方向

    while(1){
        tag = 0;
        for(i=0; i<strlen(data); i++){
            if(data[i]=='.') continue;
            if(data[i]=='A') dd = 1;
            if(data[i]=='B') dd = -1;

            if(valid(data, i+dd) && valid(data,i+dd+dd)
               && data[i+dd]!=data[i] && data[i+dd+dd]=='.'){
                //如果能跳...
                move(data, i, i+dd+dd);
                printf("%s\n", data);
                tag = 1;
                break;
            }
        }

        if(tag) continue;

        for(i=0; i<strlen(data); i++){
            if(data[i]=='.') continue;
            if(data[i]=='A') dd = 1;
            if(data[i]=='B') dd = -1;

            if(valid(data, i+dd) && data[i+dd]=='.'){
                // 如果能移动...
                if(valid(data, i+dd+dd) && (valid(data,i-dd)) && data[i+dd+dd] == data[i-dd]) 
                    continue;
                move(data, i, i+dd);
                printf("%s\n", data);
                tag = 1;
                break;
            }
        }

        if(tag==0) break;
    }
}

int main()
{
    char data[] = "AAA.BBB";
    f(data);
    return 0;
}
