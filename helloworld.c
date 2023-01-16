#include<stdio.h>


int main(void){
int n1,n2;
scanf("%d",&n2);
while(n2!=0){
n1=n2%10;
n2=n2/10;

printf("%d",n1);

}
return 0;
}