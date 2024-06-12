#include<stdio.h>
int gcd(int a,int b){
	int c;
	c=a%b;
	while(c>0){
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
int main(){
	int a,b,c,d,x;
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		scanf("%d",&b);
		scanf("%d",&x);
		for(int j=1;j<=b-1;j++){
			scanf("%d",&c);
			x=gcd(x,c);
		}
		printf("%d\n",x);
		
			
	}
	return 0;	
}

