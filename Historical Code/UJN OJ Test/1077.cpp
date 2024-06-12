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
	int a,b,x;
	int n[10];
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		scanf("%d",&b);
		for(int j=1;j<=b;j++)
			scanf("%d",&n[j]);
		x=n[1];
		for(int m=2;m<=b;m++)
			x=gcd(x,n[m]);
		printf("%d\n",x);
		
			
	}
	return 0;	
}

