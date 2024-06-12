#include<stdio.h>
int main(){
	int a,b=0,c;
	while(scanf("%d",&a)!=EOF){
		b=0;c=2*a-1;
		for(int i=1;i<=a;i++){
			
			for(int j=0;j<b;j++)
				printf(" ");
			for(int m=1;m<=c;m++)
				printf("#");
			printf("\n");
			b=b+1;
			c=c-2;
		}
			
			
	}
	
}
