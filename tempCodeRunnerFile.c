#include <stdio.h>
int main(void)
{	int w='A',x=14,y=15;
   w=((x||y)&&(w<'a'));
  	printf("%d ",w);
}
