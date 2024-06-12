#include<stdio.h>
int main(){
	int a,sum;
	while(scanf("%d",&a)!=EOF){
		sum=0;
		while(a>0){
			sum=sum+a%10;
			a=a/10;
		}
		printf("%d\n",sum);
	}
	return 0;
} 
