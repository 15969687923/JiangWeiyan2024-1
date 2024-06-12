#include<stdio.h>
int main(){
	int max,a;
	scanf("%d",&max);
	while(1){
		scanf("%d",&a);
		if(a==0)
			break;
		if(a>max)
			max=a;
		
	}
	printf("%d",max);
	return 0;
}
