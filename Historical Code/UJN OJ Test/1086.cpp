#include<stdio.h>
int main(){
	int t;
	long n,m;
	double a=0;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%ld%ld",&n,&m);
		for(int j=n;j<=m;j++)
			a=a+1.0/(j*j);
		printf("%.5lf\n",a);
		a=0;
	}
}
