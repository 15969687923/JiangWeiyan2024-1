#include<stdio.h>
int gcd(int a,int b){
	int c,d;
	if(a>b)
		c=b;
	else
		c=a;
		a=b;
	for(int i=c;i>=1;i--)
		if(a%i==0){
			d=i;
			break;}
	return d;
}
int main(){
	int a,b,c,d,x;
	int n[10];
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		scanf("%d",&b);
		scanf("%d",&x);
		for(int j=1;j<=b-1;j++){
			scanf("%d",&c);
			x=gcd(x,c);}
		printf("%d\n",x);
		
			
	}
	return 0;	
}

