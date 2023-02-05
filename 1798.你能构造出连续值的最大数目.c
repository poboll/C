int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
int getMaximumConsecutive(int* coins, int coinsSize){
    qsort(coins,coinsSize,sizeof(coins[0]),cmp);//排序
    int sum = 1;
    for(int i = 0;i<coinsSize;++i)
    {
        if(coins[i]>sum){//已排序，后面没有比res更小的数了
            return sum;
	}
        sum+=coins[i];
    }
    return sum;
}