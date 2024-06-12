#include<stdio.h>
int main(){
	int a,b,e,f;
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		scanf("%d",&b);
		if(b%2!=0)
			printf("0 0\n");
		else{
			e=b/2;
			if(b%4==0)
				f=b/4;
			else
				f=b/4+1;
			
			printf("%d %d\n",f,e);}
		}
		return 0;
	}

