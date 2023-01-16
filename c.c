#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(void)
{
  int x,y;
	int *p=&x,*q=&y,*s;
  int a[10];
  p=a;
  q=a+1;
  s=q-p;
  printf("1=%d",s);
	return 0;
}

