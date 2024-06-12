#include<stdio.h>
int f(int x,int y){
	int c,t,h;
	c=0;
	if(y>0){
		c+=1;
		t=x%y;
		x=y;
		y=t;
	}
	h=c*x*x;
	return h;
}
int main(){
	int m,i,j,k,sum,a;
	int b;
	long long n,p;
	scanf("%d",&a);
	for(k=1;k<=a;k++){
		sum=0;
		scanf("%lld%d%lld",&n,&m,&p);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++){
				b=(i*j)/f(i,j);
				sum=sum+b;
			}
		sum=sum%p;
		printf("%d\n",sum);	
	}
	return 0;
} 
