#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

/*******��  ��  ��*******/
#define FrameX 13   		//��Ϸ�������Ͻǵ�X������
#define FrameY 3   			//��Ϸ�������Ͻǵ�Y������
#define Frame_height  20 	//��Ϸ���ڵĸ߶�
#define Frame_width   18 	//��Ϸ���ڵĿ�� 

/*******��  ��  ȫ  ��  ��  �� *******/
int i,j,Temp,Temp1,Temp2; 	//temp,temp1,temp2���ڼ�ס��ת�����������ֵ
int a[80][80]={0};   		//�����Ϸ��Ļ��ͼ����2,1,0�ֱ��ʾ��λ��Ϊ��Ϸ�߿򡢷��顢��ͼ��;��ʼ��Ϊ��ͼ��
int b[4];     				//���4��"��"���飺1��ʾ�з��飬0��ʾ�޷���
struct Tetris		//��������˹����Ľṹ��
{
 	int x;     		//���ķ����x������
 	int y;     		//���ķ����y������
 	int flag;    	//��Ƿ������͵����
 	int next;    	//��һ������˹�������͵����
 	int speed;    	//����˹�����ƶ����ٶ�
 	int number;    	//��������˹����ĸ���
 	int score;    	//��Ϸ�ķ���
 	int level;    	//��Ϸ�ĵȼ�
};
HANDLE hOut;		//����̨���

/*******��  ��  ��  �� *******/
void gotoxy(int x, int y);			//����Ƶ�ָ��λ��
void DrwaGameframe();				//������Ϸ�߿�
void Flag(struct Tetris *);			//��������������͵����
void MakeTetris(struct Tetris *);	//��������˹����
void PrintTetris(struct Tetris *);	//��ӡ����˹����
void CleanTetris(struct Tetris *);	//�������˹����ĺۼ�
int  ifMove(struct Tetris *);		//�ж��Ƿ����ƶ�������ֵΪ1�����ƶ������򣬲����ƶ�
void Del_Fullline(struct Tetris *);	//�ж��Ƿ����У���ɾ�����еĶ���˹����
void Gameplay();					//��ʼ��Ϸ
void regulation();                  //��Ϸ����
void explation();                   //����˵��
void welcom();                      //��ӭ����
void Replay(struct Tetris *);  		//���¿�ʼ��Ϸ
void title();                       //��ӭ�����Ϸ��ı���
void flower();                      //��ӭ�����ϵ��ַ�װ�λ�
void close();                       //�ر���Ϸ

/**
 * ��ȡ��Ļ���λ��
 */
void gotoxy(int x, int y)
{
 	COORD pos;
 	pos.X = x;  //������
 	pos.Y = y;  //������
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/**
 * ������ɫ����      �˺����ľ����ԣ�1��ֻ��Windowsϵͳ��ʹ��   2�����ܸı䱳����ɫ
 */
int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //����������ɫ
	return 0;
}

/**
 * ������Ϸ����
 */
void DrwaGameframe()
{
 	gotoxy(FrameX+Frame_width-7,FrameY-2);   	//��ӡ��Ϸ����
	color(11);
	printf("Ȥζ����˹����");
 	gotoxy(FrameX+2*Frame_width+3,FrameY+7);  	//��ӡѡ��˵�
 	color(2);
	printf("**********");
	gotoxy(FrameX+2*Frame_width+13,FrameY+7);  	//��ӡѡ��˵�
 	color(3);
	printf("��һ���ַ��飺");
 	gotoxy(FrameX+2*Frame_width+3,FrameY+13);
 	color(2);
	printf("**********");
	gotoxy(FrameX+2*Frame_width+3,FrameY+17);
	color(14);
	printf("��������ת");
	gotoxy(FrameX+2*Frame_width+3,FrameY+19);
	printf("�ո���ͣ��Ϸ");
 	gotoxy(FrameX+2*Frame_width+3,FrameY+15);
 	printf("Esc ���˳���Ϸ");
 	gotoxy(FrameX,FrameY);       	
	color(12);
	printf("�X");							//��ӡ���
 	gotoxy(FrameX+2*Frame_width-2,FrameY);
 	printf("�[");
 	gotoxy(FrameX,FrameY+Frame_height);
 	printf("�^");
 	gotoxy(FrameX+2*Frame_width-2,FrameY+Frame_height);
 	printf("�a");
 	a[FrameX][FrameY+Frame_height]=2;       //��ס�ô�����ͼ��
 	a[FrameX+2*Frame_width-2][FrameY+Frame_height]=2;
 	for(i=2;i<2*Frame_width-2;i+=2)
 	{
  		gotoxy(FrameX+i,FrameY);
  		printf("�T");         //��ӡ�Ϻ��
 	}
 	for(i=2;i<2*Frame_width-2;i+=2)
 	{
  		gotoxy(FrameX+i,FrameY+Frame_height);
  		printf("�T");         //��ӡ�º��
  		a[FrameX+i][FrameY+Frame_height]=2;    //��ס�º����ͼ��
 	}
 	for(i=1;i<Frame_height;i++)
	{
  		gotoxy(FrameX,FrameY+i); 
  		printf("�U");         //��ӡ������
  		a[FrameX][FrameY+i]=2;       //��ס��������ͼ��
 	}
 	for(i=1;i<Frame_height;i++)
 	{
  		gotoxy(FrameX+2*Frame_width-2,FrameY+i); 
  		printf("�U");         //��ӡ������
  		a[FrameX+2*Frame_width-2][FrameY+i]=2;   //��ס��������ͼ��
 	}
}

/**
 * ��������˹����
 */
void MakeTetris(struct Tetris *tetris)
{
 	a[tetris->x][tetris->y]=b[0];    //���ķ���λ�õ�ͼ��״̬
 	switch(tetris->flag)      //��7���࣬19������
 	{
  		case 1:         /*���ַ��� ����
		  			               ����  */
   		{
			color(10);
    		a[tetris->x][tetris->y-1]=b[1];
    		a[tetris->x+2][tetris->y-1]=b[2];
    		a[tetris->x+2][tetris->y]=b[3];
   			break;
   		}
  		case 2:         /*ֱ�߷��� ��������*/
   		{
		   	color(13);
    		a[tetris->x-2][tetris->y]=b[1];
    		a[tetris->x+2][tetris->y]=b[2];
    		a[tetris->x+4][tetris->y]=b[3];
    		break;
   		}
  		case 3:         /*ֱ�߷��� ��
		  			               ��
								   ��
								   ��  */
   		{
		   	color(13);
    		a[tetris->x][tetris->y-1]=b[1];
    		a[tetris->x][tetris->y-2]=b[2];
    		a[tetris->x][tetris->y+1]=b[3];
    		break;
   		}
  		case 4:         /*T�ַ��� ������
		  			                ��  */
   		{
		   	color(11);
    		a[tetris->x-2][tetris->y]=b[1];
    		a[tetris->x+2][tetris->y]=b[2];
    		a[tetris->x][tetris->y+1]=b[3];
    		break;
   		}
  		case 5:         /* ˳ʱ��90��T�ַ���   ��
		  			                         ����
									           ��*/
   		{
		   	color(11);
    		a[tetris->x][tetris->y-1]=b[1];
    		a[tetris->x][tetris->y+1]=b[2];
    		a[tetris->x-2][tetris->y]=b[3];
    		break;
   		}
  		case 6:         /* ˳ʱ��180��T�ַ���     ��
		  			                            ������*/
   		{
		   	color(11);
    		a[tetris->x][tetris->y-1]=b[1];
    		a[tetris->x-2][tetris->y]=b[2];
    		a[tetris->x+2][tetris->y]=b[3];
    		break;
   		}
  		case 7:         /* ˳ʱ��270��T�ַ���   ��
		  			                            ����
									            ��  */
   		{
		   	color(11);
    		a[tetris->x][tetris->y-1]=b[1];
    		a[tetris->x][tetris->y+1]=b[2];
    		a[tetris->x+2][tetris->y]=b[3];
    		break;
   		}
  		case 8:         /* Z�ַ���   ����
		  			                   ����*/
   		{
		   	color(14);
    		a[tetris->x][tetris->y+1]=b[1];
    		a[tetris->x-2][tetris->y]=b[2];
    		a[tetris->x+2][tetris->y+1]=b[3];
    		break;
   		}
  		case 9:         /* ˳ʱ��Z�ַ���      ��
		  			                        ����
									        ��  */
   		{
		   	color(14);                                                                                                      
    		a[tetris->x][tetris->y-1]=b[1];
    		a[tetris->x-2][tetris->y]=b[2];
    		a[tetris->x-2][tetris->y+1]=b[3];
    		break;
   		}
  		case 10:        /* ��תZ�ַ���      ����
		  			                      ����  */
   		{
		   	color(14);
    		a[tetris->x][tetris->y-1]=b[1];
    		a[tetris->x-2][tetris->y-1]=b[2];
    		a[tetris->x+2][tetris->y]=b[3];
    		break;
   		}
  		case 11:        /* ˳ʱ��Z�ַ���    ��
		  			                        ����
									          ��  */
   		{
		   	color(14);
    		a[tetris->x][tetris->y+1]=b[1];
    		a[tetris->x-2][tetris->y-1]=b[2];
    		a[tetris->x-2][tetris->y]=b[3];
    		break;
   		}
  		case 12:        /* 7�ַ���    ����
		  			                    ��
									    ��  */
   		{
		   	color(12);
    		a[tetris->x][tetris->y-1]=b[1];
    		a[tetris->x][tetris->y+1]=b[2];
    		a[tetris->x-2][tetris->y-1]=b[3];
    		break;
   		}
  		case 13:        /* ˳ʱ��90��7�ַ���        ��
		  			                            ������*/
   		{
		   	color(12);
    		a[tetris->x-2][tetris->y]=b[1];
    		a[tetris->x+2][tetris->y-1]=b[2];
    		a[tetris->x+2][tetris->y]=b[3];
    		break;
   		}
  		case 14:        /* ˳ʱ��180��7�ַ���      ��
		  			                               ��
									               ����  */
   		{
		   	color(12);
    		a[tetris->x][tetris->y-1]=b[1];
   		 	a[tetris->x][tetris->y+1]=b[2];
    		a[tetris->x+2][tetris->y+1]=b[3];
    		break;
   		}
  		case 15:        /* ˳ʱ��270��7�ַ���    ������
		  			                             ��    */
   		{
		   	color(12);
    		a[tetris->x-2][tetris->y]=b[1];
    		a[tetris->x-2][tetris->y+1]=b[2];
    		a[tetris->x+2][tetris->y]=b[3];
    		break;
   		}
  		case 16:        /* ��ת7�ַ���    ����
		  			                      ��
										  ��    */
   		{
		   	color(12);
    		a[tetris->x][tetris->y+1]=b[1];
    		a[tetris->x][tetris->y-1]=b[2];
    		a[tetris->x+2][tetris->y-1]=b[3];
    		break;
   		}
  		case 17:        /* ˳ʱ��ת90��7�ַ���    ������
		  			                                  ��*/
   		{
		   	color(12);
    		a[tetris->x-2][tetris->y]=b[1];
    		a[tetris->x+2][tetris->y+1]=b[2];
    		a[tetris->x+2][tetris->y]=b[3];
    		break;
   		}
  		case 18:        /* ˳ʱ��ת180��7�ַ���    ��
		  			                               ��
									             ����    */
   		{
		   	color(12);
    		a[tetris->x][tetris->y-1]=b[1];
    		a[tetris->x][tetris->y+1]=b[2];
    		a[tetris->x-2][tetris->y+1]=b[3];
    		break;
   		}
  		case 19:        /* ˳ָ��ת270��7�ַ���    ��
		  			                               ������*/
  		{
		  	color(12);
    		a[tetris->x-2][tetris->y]=b[1];
    		a[tetris->x-2][tetris->y-1]=b[2];
    		a[tetris->x+2][tetris->y]=b[3];
    		break;
  	 	}
 	} 
}

/**
 * ��ӡ����˹����
 */
void PrintTetris(struct Tetris *tetris)
{
 	for(i=0;i<4;i++)
 	{
  		b[i]=1;         				//����b[4]��ÿ��Ԫ�ص�ֵ��Ϊ1
 	}
 	MakeTetris(tetris);      			//������Ϸ����
 	for( i=tetris->x-2; i<=tetris->x+4; i+=2 )
 	{
  		for(j=tetris->y-2;j<=tetris->y+1;j++)
  		{
   			if( a[i][j]==1 && j>FrameY )
   			{
    			gotoxy(i,j);
				printf("��");     //��ӡ�߿��ڵķ���
   			}
  		}
	}
 	//��ӡ�˵���Ϣ
	gotoxy(FrameX+2*Frame_width+3,FrameY+1);
	color(4);
 	printf("level : ");
 	color(12);
 	printf(" %d",tetris->level);
	gotoxy(FrameX+2*Frame_width+3,FrameY+3);
	color(4);
 	printf("score : ");
 	color(12);
 	printf(" %d",tetris->score);
	gotoxy(FrameX+2*Frame_width+3,FrameY+5);
	color(4);
 	printf("speed : ");
 	color(12);
	printf(" %dms",tetris->speed);
}

/**
 * �ж��Ƿ���ƶ�
 */
int ifMove(struct Tetris *tetris)
{
 	if(a[tetris->x][tetris->y]!=0)//�����ķ���λ������ͼ��ʱ������ֵΪ0���������ƶ�
 	{
  		return 0;
 	}
 	else
 	{
  		if( //��Ϊ���ַ����ҳ����ķ���λ���⣬����"��"�ַ���λ������ͼ��ʱ��˵�����λ���ܹ��������ַ��飬�����ƶ������λ�ã�����ֵΪ1�������ƶ�
			//�������ַ��飬�������ķ��������½ǵġ�����������ϣ��ң����ϵ�λ��Ϊ�գ������λ�þͿ��Է�һ�����ַ��飻�����һ��λ���ϲ�Ϊ�գ����Ų���һ����
   		( tetris->flag==1  && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x+2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
   		//��Ϊֱ�߷����ҳ����ķ���λ���⣬����"��"�ַ���λ������ͼ��ʱ������ֵΪ1�������ƶ�
   		( tetris->flag==2  && ( a[tetris->x-2][tetris->y]==0   && 
    	a[tetris->x+2][tetris->y]==0 && a[tetris->x+4][tetris->y]==0 ) )   ||
   		( tetris->flag==3  && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x][tetris->y-2]==0 && a[tetris->x][tetris->y+1]==0 ) )   ||
   		( tetris->flag==4  && ( a[tetris->x-2][tetris->y]==0   &&
    	a[tetris->x+2][tetris->y]==0 && a[tetris->x][tetris->y+1]==0 ) )   ||
   		( tetris->flag==5  && ( a[tetris->x][tetris->y-1]==0   &&
   		 a[tetris->x][tetris->y+1]==0 && a[tetris->x-2][tetris->y]==0 ) )   ||
   		( tetris->flag==6  && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x-2][tetris->y]==0 && a[tetris->x+2][tetris->y]==0 ) )   ||
   		( tetris->flag==7  && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x][tetris->y+1]==0 && a[tetris->x+2][tetris->y]==0 ) )   ||
   		( tetris->flag==8  && ( a[tetris->x][tetris->y+1]==0   &&
    	a[tetris->x-2][tetris->y]==0 && a[tetris->x+2][tetris->y+1]==0 ) ) ||
   		( tetris->flag==9  && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x-2][tetris->y]==0 && a[tetris->x-2][tetris->y+1]==0 ) ) ||
   		( tetris->flag==10 && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x-2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
   		( tetris->flag==11 && ( a[tetris->x][tetris->y+1]==0   &&
    	a[tetris->x-2][tetris->y-1]==0 && a[tetris->x-2][tetris->y]==0 ) ) ||
   		( tetris->flag==12 && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x][tetris->y+1]==0 && a[tetris->x-2][tetris->y-1]==0 ) ) ||
   		( tetris->flag==15 && ( a[tetris->x-2][tetris->y]==0   &&
    	a[tetris->x-2][tetris->y+1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
   		( tetris->flag==14 && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x][tetris->y+1]==0 && a[tetris->x+2][tetris->y+1]==0 ) ) ||
   		( tetris->flag==13 && ( a[tetris->x-2][tetris->y]==0   &&
    	a[tetris->x+2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
   		( tetris->flag==16 && ( a[tetris->x][tetris->y+1]==0   &&
    	a[tetris->x][tetris->y-1]==0 && a[tetris->x+2][tetris->y-1]==0 ) ) ||
   		( tetris->flag==19 && ( a[tetris->x-2][tetris->y]==0   &&
    	a[tetris->x-2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
   		( tetris->flag==18 && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x][tetris->y+1]==0 && a[tetris->x-2][tetris->y+1]==0 ) ) ||
   		( tetris->flag==17 && ( a[tetris->x-2][tetris->y]==0   &&
    	a[tetris->x+2][tetris->y+1]==0 && a[tetris->x+2][tetris->y]==0 ) ) )
   		{
    		return 1;
   		}
	}
 	return 0;
}

/**
 * �����������˹�������͵����
 */
void Flag(struct Tetris *tetris)
{
 	tetris->number++;     				//��ס��������ĸ���
	srand(time(NULL));  		//��ʼ�������
	 if(tetris->number==1)
 	{
  		tetris->flag = rand()%19+1;  	//��ס��һ����������
 	}
 	tetris->next = rand()%19+1;   		//��ס��һ����������
}



/**
 * �������˹����ĺۼ�
 */
void CleanTetris(struct Tetris *tetris)
{
 	for(i=0;i<4;i++)
 	{
  		b[i]=0;         //����b[4]��ÿ��Ԫ�ص�ֵ��Ϊ0
 	}
	MakeTetris(tetris);      //��������˹����
	for( i = tetris->x - 2;i <= tetris->x + 4; i+=2 )       //��X ����  XΪ���ķ���
	{
  		for(j = tetris->y-2;j <= tetris->y + 1;j++)        /* ��
															  ��
															  X
  															  ��	*/
  		{
   			if( a[i][j] == 0 && j > FrameY )
   			{
    			gotoxy(i,j);
    			printf("  ");    //�������
   			}
  		}
 	}
}

/**
 * �ж��Ƿ����в�ɾ�����еĶ���˹����
 */
void Del_Fullline(struct Tetris *tetris)//��ĳ����Frame_width-2������ʱ������������
{      
 	int k,del_rows=0;  //�ֱ����ڼ�¼ĳ�з���ĸ�����ɾ������������ı���
 	for(j=FrameY+Frame_height-1;j>=FrameY+1;j--)
 	{
  		k=0;
  		for(i=FrameX+2;i<FrameX+2*Frame_width-2;i+=2)
  		{  
   			if(a[i][j]==1) //���������δ������ϣ��������������������ж��Ƿ�����
   			{
    			k++;  //��¼���з���ĸ���
    			if(k==Frame_width-2)  //������� 
    			{
     				for(k=FrameX+2;k<FrameX+2*Frame_width-2;k+=2)//ɾ�����еķ���
     				{  
      					a[k][j]=0;
      					gotoxy(k,j);
      					printf("  ");
//      					Sleep(1);
     				}
    	 			for(k=j-1;k>FrameY;k--) //���ɾ�������ϵ�λ���з��飬����������ٽ���������һ��λ��
     				{ 
      					for(i=FrameX+2;i<FrameX+2*Frame_width-2;i+=2)
      					{
       						if(a[i][k]==1)
       						{
        						a[i][k]=0;
        						gotoxy(i,k);
        						printf("  ");
        						a[i][k+1]=1;
        						gotoxy(i,k+1);
        						printf("��");
       						}
      					}
     				}			
     				j++;   //�������ƺ������ж�ɾ�����Ƿ�����
     				del_rows++; //��¼ɾ�����������
    			}
   			}
  		}
 	}
 	tetris->score+=100*del_rows; //ÿɾ��һ�У���100��
 	if( del_rows>0 && ( tetris->score%1000==0 || tetris->score/1000>tetris->level-1 ) )
 	{        //�����1000�ּ��ۼ�ɾ��10�У��ٶȼӿ�20ms����һ��
  		tetris->speed-=20;
  		tetris->level++;
 	}
}

/**
 * ��ʼ��Ϸ
 */
void Gameplay()
{
	int n;
 	struct Tetris t,*tetris=&t;       					//����ṹ���ָ�벢ָ��ṹ�����
 	char ch;         									//������ռ�������ı���
 	tetris->number=0;      								//��ʼ������˹������Ϊ0��
 	tetris->speed=300;      							//��ʼ�ƶ��ٶ�Ϊ300ms
	tetris->score=0;      								//��ʼ��Ϸ�ķ���Ϊ0��
 	tetris->level=1;      								//��ʼ��ϷΪ��1��
 	while(1)											//ѭ���������飬ֱ����Ϸ����
 	{
  		Flag(tetris);     								//�õ���������˹�������͵����
  		Temp=tetris->flag;     							//��ס��ǰ����˹�������
  		tetris->x=FrameX+2*Frame_width+6;				//���Ԥ�����淽���x����
  		tetris->y=FrameY+10;                            //���Ԥ�����淽���y����
  		tetris->flag = tetris->next;                    //�����һ������˹��������
  		PrintTetris(tetris);                           //���ô�ӡ����˹���鷽��
  		tetris->x=FrameX+Frame_width;  					//�����Ϸ�������ķ���x����
  		tetris->y=FrameY-1;     						//�����Ϸ�������ķ���y����
  		tetris->flag=Temp;     							//ȡ����ǰ�Ķ���˹�������
  		while(1)  										//���Ʒ��鷽��ֱ�����鲻������
  		{
   			label:PrintTetris(tetris);					//��ӡ����˹����
   			Sleep(tetris->speed);   					//�ӻ�ʱ��
   			CleanTetris(tetris);  						//����ۼ�
   			Temp1=tetris->x;    						//��ס���ķ���������ֵ
   			Temp2=tetris->flag;    						//��ס��ǰ����˹�������
   			if(kbhit())       				  	 		//�ж��Ƿ��м������룬������ch������
   			{ 
    			ch=getch(); 
    			if(ch==75)     							//�� ���������󶯣����ĺ������2
    			{      
     				tetris->x-=2;
    			}
    			if(ch==77)     							//�� ���������Ҷ������ĺ������2
    			{      
     				tetris->x+=2;    
    			}
    			if(ch==80)     							//�� �������������
    			{    
					if(ifMove(tetris)!=0)
					{
						tetris->y+=2;
					}
					if(ifMove(tetris)==0)
						{
							tetris->y=FrameY+Frame_height-2;
    					}
    			}
    			if(ch==72)     						//�� ���������,����ǰ����˳ʱ��ת90��
    			{      
    	 			if( tetris->flag>=2 && tetris->flag<=3 )
     				{
      					tetris->flag++; 
      					tetris->flag%=2;
      					tetris->flag+=2;
     				}
     				if( tetris->flag>=4 && tetris->flag<=7 )
     				{
      					tetris->flag++;
      					tetris->flag%=4;
      					tetris->flag+=4;
     				}    
     				if( tetris->flag>=8 && tetris->flag<=11 )
     				{
      					tetris->flag++;
      					tetris->flag%=4;
      					tetris->flag+=8;
     				}    
     				if( tetris->flag>=12 && tetris->flag<=15 )
     				{
      					tetris->flag++;
      					tetris->flag%=4;
      					tetris->flag+=12;
     				}    
     				if( tetris->flag>=16 && tetris->flag<=19 )
     				{
      					tetris->flag++;
      					tetris->flag%=4;
      					tetris->flag+=16;
     				}
    			}
    			if(ch == 32)     					//���ո������ͣ
    			{
     				PrintTetris(tetris);
     				while(1)
     				{
      					if(kbhit())   			//�ٰ��ո����������Ϸ
      					{
       						ch=getch();
       						if(ch == 32)
       						{
        						goto label;
       						}
      					}
     				}
    			}
				if(ch == 27)
				{
					system("cls");
					memset(a,0,6400*sizeof(int));       //��ʼ��BOX����
					welcom();
				}
    			if(ifMove(tetris)==0) 			//������ɶ������������Ч
    			{
    				tetris->x=Temp1;
     				tetris->flag=Temp2;
    			}
    			else      						//����ɶ���ִ�в���
    			{
     				goto label;
    			}
   			}
   			tetris->y++;     					//���û�в���ָ����������ƶ�
   			if(ifMove(tetris)==0)  				//��������ƶ��Ҳ��ɶ���������ڴ˴�
   			{    
    			tetris->y--;
    			PrintTetris(tetris);
    			Del_Fullline(tetris);
    			break;
   			}
  		}
  		for(i=tetris->y-2;i<tetris->y+2;i++)	//��Ϸ�������������鴥����λ��
  		{
  			if(i==FrameY)
   			{
   				system("cls");
                gotoxy(29,7);
                printf("   \n");
				color(12);
				printf("\t\t\t��������   ��     ��   ����     \n");
                printf("\t\t\t��         ����   ��   ��  ��   \n");
                printf("\t\t\t������     ��  �� ��   ��   ��  \n");
				printf("\t\t\t��         ��   ����   ��  ��   \n");
				printf("\t\t\t��������   ��     ��   ����     \n");
				gotoxy(17,18);
				color(14);
				printf("��Ҫ������һ��-------1");
				gotoxy(44,18);
				printf("�����ˣ��˳���-------2\n");
				int n;
				gotoxy(32,20);
				printf("ѡ��1/2����");
				color(11);
				scanf("%d", &n);
    			switch (n)
    			{
    				case 1:
        				system("cls");
        				Replay(tetris);       	//���¿�ʼ��Ϸ
        				break;
    				case 2:
        				exit(0);
        				break;
    			}
   			}
  		}
  		tetris->flag = tetris->next;  			//�����һ������˹�����ͼ��(�ұߴ���)
  		tetris->x=FrameX+2*Frame_width+6;
  		tetris->y=FrameY+10;
  		CleanTetris(tetris);
 	}
}


 /**
 * ������Ϸ
 */
void Replay(struct Tetris *)
{
	system("cls");                  	//����
	memset(a,0,6400*sizeof(int));       //��ʼ��BOX���飬���򲻻�������ʾ���飬������Ϸֱ�ӽ���
	DrwaGameframe();       	//������Ϸ����
	Gameplay(); 			//��ʼ��Ϸ
}

/**
 * ��  ��  ��
 */
int main()
{
	title();            //��ӭ�����ϵı���
	flower();           //��ӡ�ַ���
	welcom();           //��ӭ�����ϵ�ѡ��˵�
}

/**
 * ��ӭ����
 */
void welcom()
{
	int n;
	int i,j = 1;
	color(14);          			//��ɫ�߿�
	for (i = 9; i <= 20; i++)   	//������±߿�===
	{
		for (j = 15; j <= 60; j++)  //������ұ߿�||
		{
			gotoxy(j, i);
			if (i == 9 || i == 20) printf("=");
			else if (j == 15 || j == 59) printf("||");
		}
	}
	color(12);
	gotoxy(25, 12);
	printf("1.��ʼ��Ϸ");
	gotoxy(40, 12);
	printf("2.����˵��");
	gotoxy(25, 17);
	printf("3.��Ϸ����");
	gotoxy(40, 17);
	printf("4.�˳�");
	gotoxy(21,22);
	color(3);
	printf("��ѡ��[1 2 3 4]:[ ]\b\b");
	color(14);
    scanf("%d", &n);    //����ѡ��
    switch (n)
    {
    	case 1:
    		system("cls");
        	DrwaGameframe();       	//������Ϸ����
			Gameplay(); 			//��ʼ��Ϸ
        	break;
    	case 2:
        	explation();      	//����˵������
        	break;
    	case 3:
        	regulation();     	//��Ϸ������
        	break;
    	case 4:
       	 	close();    		//�ر���Ϸ����
        	break;
    }
}

/**
 * �������Ϸ��ı���
 */
void title()
{
	color(15);          
	gotoxy(24,3);
    printf("Ȥ  ζ  ��  ��  ˹  ��  ��\n");
	color(11);
	gotoxy(18,5);
    printf("��");
    gotoxy(18,6);
    printf("����");
    gotoxy(18,7);
    printf("��");
    
    color(14);
	gotoxy(26,6);
    printf("����");
    gotoxy(28,7);
    printf("����");//
    
    color(10);
	gotoxy(36,6);
    printf("����");
    gotoxy(36,7);
    printf("����");
    
    color(13);
	gotoxy(45,5);
    printf("��");
    gotoxy(45,6);
	printf("��");
	gotoxy(45,7);
	printf("��");
	gotoxy(45,8);
	printf("��");
    
	color(12);
	gotoxy(56,6);
    printf("��");//
    gotoxy(52,7);
	printf("������");
}
void flower()
{
	gotoxy(66,11);   	//ȷ����Ļ��Ҫ�����λ��
	color(12);			//������ɫ
	printf("(_)");  	//�컨�ϱ߻���

	gotoxy(64,12);
	printf("(_)");      //�컨��߻���

	gotoxy(68,12);
	printf("(_)");      //�컨�ұ߻���

	gotoxy(66,13);
	printf("(_)");      //�컨�±߻���

	gotoxy(67,12);      //�컨����
	color(6);
	printf("@");
	
	gotoxy(72,10);
	color(13);
	printf("(_)");      //�ۻ���߻���

	gotoxy(76,10);
	printf("(_)");      //�ۻ��ұ߻���

	gotoxy(74,9);
	printf("(_)");      //�ۻ��ϱ߻���
	
	gotoxy(74,11);
	printf("(_)");      //�ۻ��±߻���
	
	gotoxy(75,10);
	color(6);
	printf("@");        //�ۻ�����
	
	gotoxy(71,12);
	printf("|");      	//���仨֮�������

	gotoxy(72,11);
	printf("/");      	//���仨֮�������

	gotoxy(70,13);
	printf("\\|");       //ע�⡢\Ϊת���ַ�����Ҫ����\��������ǰ����Ҫת��

	gotoxy(70,14);
	printf("`|/");

	gotoxy(70,15);
	printf("\\|");

	gotoxy(71,16);
	printf("| /");

	gotoxy(71,17);
	printf("|");
	
	gotoxy(67,17);
	color(10);
	printf("\\\\\\\\");      //�ݵ�

	gotoxy(73,17);
	printf("//");

	gotoxy(67,18);
	color(2);
	printf("^^^^^^^^");
	
	gotoxy(65,19);
	color(5);
	printf("�� ��  �� ��");
	
	gotoxy(68,20);
	printf("��С��");
}

 /**
 * �˳�
 */
void close()
{
    exit(0);
}

 /**
 * ����˵��
 */
void explation()
{
	int i,j = 1;
    system("cls");
    color(13);
    gotoxy(32,3);
    printf("����˵��");
    color(2);
    for (i = 6; i <= 16; i++)   //������±߿�===
	{
		for (j = 15; j <= 60; j++)  //������ұ߿�||
		{
			gotoxy(j, i);
			if (i == 6 || i == 16) printf("=");
			else if (j == 15 || j == 59) printf("||");
		}
	}
    color(3);
    gotoxy(18,7);
    printf("tip1: ��ҿ���ͨ�� �� ����������ƶ�����");
    color(10);
    gotoxy(18,9);
    printf("tip2: ͨ�� ��ʹ������ת");
    color(14);
    gotoxy(18,11);
    printf("tip3: ͨ�� �����ٷ�������");
    color(11);
    gotoxy(18,13);
    printf("tip4: ���ո����ͣ��Ϸ���ٰ��ո������");
    color(4);
    gotoxy(18,15);
    printf("tip5: ��ESC�˳���Ϸ");
    getch();                //�����������������
    system("cls");
    main();
}

 /**
 * ��Ϸ����
 */
void regulation()
{
	int i,j = 1;
    system("cls");
    color(13);
    gotoxy(34,3);
    printf("��Ϸ����");
    color(2);
    for (i = 6; i <= 18; i++)   //������±߿�===
	{
		for (j = 12; j <= 70; j++)  //������ұ߿�||
		{
			gotoxy(j, i);
			if (i == 6 || i == 18) printf("=");
			else if (j == 12 || j == 69) printf("||");
		}
	}
    color(12);
    gotoxy(16,7);
    printf("tip1: ��ͬ��״��С�������Ļ�Ϸ����£����ͨ������");
    gotoxy(22,9);
    printf("�����λ�úͷ���ʹ��������Ļ�ײ�ƴ��������");
    gotoxy(22,11);
    printf("һ������");
    color(14);
    gotoxy(16,13);
    printf("tip2: ÿ����һ�У���������100");
    color(11);
    gotoxy(16,15);
    printf("tip3: ÿ�ۼ�1000�֣�������һ���ȼ�");
    color(10);
    gotoxy(16,17);
    printf("tip4: �����ȼ���ʹ���������ٶȼӿ죬��Ϸ�ѶȼӴ�");
	getch();                //�����������������
	system("cls");
	welcom();
}
