#include<stdio.h>
int main(){
	int max,min;
	int a,b;
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
	if(a>max)
		max=a;
	if(a<min)
		min=a;
	printf("%d %d\n",max,min);
	return 0;
}
