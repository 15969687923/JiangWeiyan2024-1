#include<stdio.h>
int main(){
	int a,b,c,d;
	
	while(scanf("%d",&a)!=EOF){
		if(a!=0){
			do{
				scanf("%d",&b);
				a=a+b;
			}
			while((getchar())!='\n');
			printf("%d",a);
		}
			
	}
	return 0;
		
}
