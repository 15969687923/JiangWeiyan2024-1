#include<stdio.h>
int main(){
	int m,i,j,sum;
	scanf("%d",&m);
	for(i=m;i>=6;i--){
		sum=0;
		for(j=i-1;j>=1;j--){
			if(i%j==0)
				sum=sum+j;
		}
		if(sum==i){
			printf("%d",sum);
			break;
		}
	}
	return 0;
}
