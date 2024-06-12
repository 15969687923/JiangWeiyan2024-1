#include<stdio.h>
int main(){
	int a,b,c=0,d;
		while(1){
			scanf("%d",&a);
			if(a!=0){
				c=0;
				for(int i=1;i<=a;i++){
					scanf("%d",&b);
					c=c+b;
				}
				printf("%d\n",c);
			}
			else
				return 0;
		
	}
	return 0;
		
}
