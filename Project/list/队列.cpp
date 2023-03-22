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
 
void YangHuiTriangle(int N){
	int n,x,i,temp;
	SqQueue Q;
	InitQueue(Q); 
	
	EnQueue(Q,1);
	for(n=2;n<=N;n++){		//每一行进行打印 
		EnQueue(Q,1);		 //每行第一个都是数字 1	
		for(i=1;i<=n-2;i++){	//通过上一行求下一行 （第一行已知，所以可以求出第二行，依次类推）
			DeQueue(Q,temp);	//先取出最前面的元素，也就是要求下一行的左上方的元素 
			printf("%d ",temp);	//将其打印 
			GetTop(Q,x);	//得到上述出队后，当前最前方元素，也就是要求下一行的上方的元素 
			temp=temp+x;	//得到当前要求元素 
			EnQueue(Q,temp);	//将其入队 
		}
		DeQueue(Q,x);	//输出上一行最后一个 1	
		printf("%d ",x);
		EnQueue(Q,1);		//存储要求这一行最后一个数字 1 
		printf("\n");	//输出上一行的换行 
	}
	while(!IsEmpty(Q)){	//输出最后一行 
		DeQueue(Q,x);
		printf("%d ",x);
	}
 
}
 
int main(){
    int N;
    printf("请输入要打印的层数：");
    scanf("%d",&N);
    YangHuiTriangle(N);
	return 0;
}