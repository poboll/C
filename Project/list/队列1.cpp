#include<stdio.h>
#define Maxsize 50
typedef struct{
    int data[Maxsize];
    int front,rear;
}SqQueue;
 
void InitQueue(SqQueue &Q){
    Q.rear=Q.front=0;
}
 
bool IsEmpty(SqQueue Q){
    if(Q.rear==Q.front)
        return true;
    return false;
}
 
bool EnQueue(SqQueue &Q,int x){
    if((Q.rear+1)%Maxsize==Q.front)    //判断队列是否满了
        return false;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%Maxsize;
    return true;
}
 
bool DeQueue(SqQueue &Q,int &x){
    if(IsEmpty(Q))    //判断队列是否为空
        return false;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%Maxsize;
    return true;
}
 
bool GetTop(SqQueue Q,int &x){
	if(IsEmpty(Q))
		return false;
	x=Q.data[Q.front];
	return true;
} 
 
int Triangle(int N){
	int n,x,i,temp;
	SqQueue Q;
	InitQueue(Q); 
	
    if (N < 2){
        printf("输入无效！请重新输入");
        scanf("%d",&N);
    }
	EnQueue(Q,1);
	for(n=2;n<=N;n++){		//行
		EnQueue(Q,1);		 //1	
		for(i=1;i<=n-2;i++){
			DeQueue(Q,temp);	//左上 
			printf("%d ",temp);	//打印 
			GetTop(Q,x);	//数字出队后，求下一行的上方的元素 
			temp=temp+x;	//当前数字 
			EnQueue(Q,temp);	//入队 
		}
		DeQueue(Q,x);	//上一行最后 1	
		printf("%d ",x);
		EnQueue(Q,1);		//最后 1 
		printf("\n");	//上一行的换行 
	}
	while(!IsEmpty(Q)){	//最后一行 
		DeQueue(Q,x);
		printf("%d ",x);
	}
 
}
 
int main(){
    int N;
    while(1) {
        printf("请输入要打印的层数：");
        scanf("%d",&N);
        Triangle(N);
        printf("\n打印完成！");
    }
	return 0;
}
