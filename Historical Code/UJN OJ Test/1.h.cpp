#include<stdio.h>
int main(){
	int a,b,c=0,d,i;
		scanf("%d",&d);
		for(int j=1;j<=d;j++){
			c=0;
			scanf("%d",&a);
				for(int i=1;i<=a;i++){
					scanf("%d",&b);
					c=c+b;
				}
				//if(i<a)
					printf("%d\n\n",c);
				//if(i=a)
				//	printf("%d",c);
	}
	return 0;
		
}
