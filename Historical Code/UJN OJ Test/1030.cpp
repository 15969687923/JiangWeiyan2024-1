#include<stdio.h>
int main(){
	int max,min;
	int a,b,c;
	scanf("%d%d",&a,&b);
	if(a>b){
		max=a;
		min=b;
	}
	else{
		max=b;
		min=a;
	}
	scanf("%d",&a);
	if(a>max){
		c=max;
		max=a;
	}
	else if(a<min){
	 	c=min;
		min=a;
	}
	else
		c=a;
		
	printf("%d %d %d\n",min,c,max);
	return 0;
}
