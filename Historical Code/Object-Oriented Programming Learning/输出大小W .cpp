#include<stdio.h>
int main(){
	int n,a=0,b,c=0;
	scanf("%d",&n);
	b=(n-2)*2+1;
	for(int i=1;i<=n;i++){
		if(i==1){
			for(int j=1;j<=a;j++)
				printf(" ");
			printf("*");
			for(int j=1;j<=b;j++)
				printf(" ");
			printf("*");
			for(int j=1;j<=b;j++)
				printf(" ");
			printf("*");
			for(int j=1;j<=a;j++)
				printf(" ");
			printf("\n");
			a=a+1;
			b=b-2;
			c=1;
		}
		if(i>1&&i<n){
			for(int j=1;j<=a;j++)
				printf(" ");
			printf("*");
			for(int j=1;j<=b;j++)
				printf(" ");
			printf("*");
			for(int j=1;j<=c;j++)
				printf(" ");
			printf("*");
			for(int j=1;j<=b;j++)
				printf(" ");
			printf("*");
			for(int j=1;j<=a;j++)
				printf(" ");
			printf("\n");
			a=a+1;
			b=b-2;
			c=c+2;
		}
		if(i==n){
			for(int j=1;j<=n-1;j++)
				printf(" ");
			printf("*");
			for(int j=1;j<=2*n-3;j++)
				printf(" ");
			printf("*");
			for(int j=1;j<=n-1;j++)
				printf(" ");
			printf("\n");
		}
	}
	return 0;
}
