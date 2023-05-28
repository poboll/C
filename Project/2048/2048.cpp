//2048
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void move_up(int a[][4])
{
	int i,j,k,n;
	int flag=0;
	for(j=0;j<4;j++)	//列 
	{	
		flag=0;
		for(i=1;i<4;i++)	//行 
		{
			n=4;
			while(n--)
			{
				if(a[i-1][j]==0)
				{
					for(k=i;k<4;k++)
					{
						a[k-1][j]=a[k][j];
						a[k][j]=0;
					}
				}
			}
		}
		//相加部分,从上第二个元素开始向下执行 
		for(i=1;i<4;i++)
		{
			n=4;
			if(flag==0)
			if(a[i-1][j]==a[i][j])
			{
				a[i-1][j]*=2;
				a[i][j]=0;
				flag=1;
			}
			while(n--)
			{
				if(a[i-1][j]==0)
				for(k=i;k<4;k++)
				{
					a[k-1][j]=a[k][j];
					a[k][j]=0;
				}
			}
		} 
	}
}
void move_down(int a[][4])
{
	int i,j,k,n;
	int flag=0;
	for(j=0;j<4;j++)	//列 
	{	
		flag=0;
		for(i=3;i>=1;i--)	//行 
		{
			n=4;
			while(n--)
			{
				if(a[i][j]==0)
				{
					for(k=i;k>=1;k--)
					{
						a[k][j]=a[k-1][j];
						a[k-1][j]=0;
					}
				}
			}
		}
		for(i=2;i>=0;i--)
		{
			n=4;
			if(flag==0)
			if(a[i+1][j]==a[i][j])
			{
				a[i+1][j]*=2;
				a[i][j]=0;
				flag=1;
			}
			while(n--)
			{
				if(a[i][j]==0)
				for(k=i;k>=1;k--)
				{
					a[k][j]=a[k-1][j];
					a[k-1][j]=0;
				}
			}
		} 
	}
}
void move_left(int a[][4])
{
	int i,j,k,n;
	int flag=0;
	for(i=0;i<4;i++)	//行 
	{	
		flag=0;
		for(j=1;j<4;j++)	//列 
		{
			n=4;
			while(n--)
			{
				if(a[i][j-1]==0)
				{
					for(k=j;k<4;k++)
					{
						a[i][k-1]=a[i][k];
						a[i][k]=0;
					}
				}
			}
		}
		for(j=1;j<4;j++)
		{
			n=4;
			if(flag==0)
			if(a[i][j-1]==a[i][j])
			{
				a[i][j-1]*=2;
				a[i][j]=0;
				flag=1;
			}
			while(n--)
			{
				if(a[i][j-1]==0)
				for(k=j;k<4;k++)
				{
					a[i][k-1]=a[i][k];
					a[i][k]=0;
				}
			}
		} 
	}	
}
void move_right(int a[][4])
{
	int i,j,k,n;
	int flag=0;
	for(i=0;i<4;i++)	//行
	{	
		flag=0;
		for(j=3;j>=1;j--)	// 列 
		{
			n=4;
			while(n--)
			{
				if(a[i][j]==0)
				{
					for(k=j;k>=1;k--)
					{
						a[i][k]=a[i][k-1];
						a[i][k-1]=0;
					}
				}
			}
		}
		for(j=2;j>=0;j--)
		{
			n=4;
			if(flag==0)
			if(a[i][j+1]==a[i][j])
			{
				a[i][j+1]*=2;
				a[i][j]=0;
				flag=1;
			}
			while(n--)
			{
				if(a[i][j]==0)
				for(k=j;k>=1;k--)
				{
					a[i][k]=a[i][k-1];
					a[i][k-1]=0;
				}
			}
		} 
	}	
}
void output(int a[][4])
{
    int i,j;  
  	char c;
  	printf("\t2048\n");
    printf("+");  
    for(j=0;j<4;j++)  
    {  
       printf("-----");  
    }  
    printf("+\n");  
  
    for(i=0;i<4;i++)  
    {  
        printf("|");  
       for(j=0;j<4;j++)  
        {  
           if(a[i][j]==0)  
          {  
              c='.';  
              printf("%5c",c);  
            }  
            else  
            {  
                 printf("%5d",a[i][j]);  
            }  
        }  
        printf("|\n\n");  
    }  
  
    printf("+");  
    for(j=0;j<4;j++)  
    {  
        printf("-----");  
    }  
    printf("+\n");    
}
void rand_value(int a[][4])	//检索为0的元素并赋值随机数 
{
	int i,j;
	int r,c;
	srand(time(NULL));
	A:
		{
			r=rand()%4;
			c=rand()%4;			
		
			if(a[r][c]==0)
				a[r][c]=rand()%4?2:4;
			else{
				goto A;
				}
		}
	output(a);
}
int isEnd(int a[][4])
{
	int i,j,cnt1=0,cnt2=0,cnt=0;
	for(i=0;i<4;i++)	//判断是否所有元素非空 
		for(j=0;j<4;j++)
		{
			if(a[i][j]==2048)
			{
				printf("Good Job!");
				return 0;	
			}
			if(a[i][j]!=0) cnt++;
		}
	if(cnt==16)
	{
	for(j=0;j<4;j++)	//判断相邻行是否不等 
	{
		for(i=1;i<4;i++)
		if(a[i][j]!=a[i-1][j])
			cnt1++;	
	}
	for(i=0;i<4;i++)	//判断相邻列是否不等 
	{
		for(j=1;j<4;j++)
		if(a[i][j]!=a[i][j-1])
			cnt2++;
	}
	cnt1+=cnt2;
	if(cnt1==24)
	{
		system("cls");
		printf("Game Over!");
		return 0;	
	}		
	}
	return 1;
}
int main()
{
	int a[4][4]={0};
	int i,j,flag=1;
	char ch;
	rand_value(a);
	while((ch=getch())&&flag)
	{
		switch(ch)
		{
			case 'w':
				move_up(a);system("cls");rand_value(a);flag=isEnd(a);break;
			case 's':
				move_down(a);system("cls");rand_value(a);flag=isEnd(a);break; 
			case 'a':
				move_left(a);system("cls");rand_value(a);flag=isEnd(a);break;
			case 'd':
				move_right(a);system("cls");rand_value(a);flag=isEnd(a);break;
		}
	}
	return 0;
} 
 
