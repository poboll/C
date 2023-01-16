#include <stdio.h>

int main(void)
{
  int x, y;
  char op;

  // 输入数字 x 和 y，以及运算符 op
  printf("请输入两个整数 x 和 y，以及运算符 op（+、-、*、/）：");
  scanf("%d%d %c", &x, &y, &op);

  // 根据 op 的值进行相应的计算
  switch (op)
  {
    case '+':
      printf("%d + %d = %d\n", x, y, x + y);
      break;
    case '-':
      printf("%d - %d = %d\n", x, y, x - y);
      break;
    case '*':
      printf("%d * %d = %d\n", x, y, x * y);
      break;
    case '/':
    if (y == 0)
    {
      printf("除数不能为零！\n");
    }
    else
    {
      printf("%d / %d = %d\n", x, y, x / y);
    }
    break;
    default:
    printf("运算符不合法！\n");
    break;
    }

  return 0;
}