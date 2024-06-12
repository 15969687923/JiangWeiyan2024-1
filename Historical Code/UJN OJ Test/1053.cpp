#include<stdio.h>
int main(){
	int m,n;
	int a=0;
	scanf("%d%d",&m,&n);
	for(int i=m;i<=n;i++)
		if(i%3==0)
			a=a+i;
	printf("%d",a);
	return 0;
} 
