#include<stdio.h>
int main(){
	int a,b,i=0;
	int c[1000];
	while(scanf("%d",&a)!=EOF){
		if(a==0)
			return 0;
		else{
			i=0;
			while(a!=1){
				b=a%2;
				a=a/2;
				c[i++]=b;
			}
			c[i++]=1;
			while(i>0){
				printf("%d",c[--i]);
			}
			printf("\n");
		}
	}
	return 0;
}
