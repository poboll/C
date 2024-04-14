#include <stdio.h>

int fun(int n); // 函数声明

int main(void)
{
    int n, i, sum = 0;

    // 输入数字 n
    printf("请输入一个正整数 n（n ≤ 16）：");
    scanf("%d", &n);

    // 计算 21 + 22 + … + 2n 的和
    for (i = 1; i <= n; i++)
    {
        sum += fun(i);
    }

    // 输出结果
    printf("21 + 22 + … + 2n = %d\n", sum);

    return 0;
  }

  // 定义函数 fun(n)，计算 n 的阶乘 2n
  int fun(int n)
  {
    int result = 1, i;

    for (i = 1; i <= n; i++)
    {
        result *= 2;
    }

    return result;
}