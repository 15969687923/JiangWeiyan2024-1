#include<stdio.h>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1500-b;i<=1500-a;i++)
		if(i%3==2 && i%5==4 && i%7==6)
			printf("%d\n",i);
	return 0;		
}
