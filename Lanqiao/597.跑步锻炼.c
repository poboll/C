
#include<stdio.h>//依次判断年月日周 
int main(){
    int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int year,month,day;
    int ans=6;//一月一号是周六 
    int cnt=0;//公里数 
    for(year=2000;year<=2020;year++){
        if(year%4==0&&year%100!=0||year%400==0){
            months[2]=29;
        }else{
            months[2]=28;
        }
    for(month=1;month<=12;month++){//几月 
        for(day=1;day<=months[month];day++){//几日 
            cnt++;//每天一千米 
            if(ans==8){
                ans=1;//ans自增到 8 时归回 1 
            } 
            if(ans==1||day==1){//或意味着A对，B对，AB同时对三种情况 
                cnt++;//周一或月初或周一与月初多跑一千米 
            }
            ans++;//进入第二天 
            if(year==2020&&month==10&&day==1){//到2020.10.1结束循环 
                printf("%d",cnt);
            } 
        }
    }
}
    return 0;//一点一点来不要怕错 
}