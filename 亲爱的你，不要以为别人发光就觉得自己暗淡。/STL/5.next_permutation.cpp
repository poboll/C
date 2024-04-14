#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)&&n){
		int a[1000];
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		do{
			for(int i=0;i<n;i++)
				printf("%d ",a[i]);
			printf("\n");
		}while(next_permutation(a,a+n));
	}
	return 0;
}
