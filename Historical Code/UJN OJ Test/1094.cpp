#include<stdio.h>
int main(){
	long long t,n,a=1;
	scanf("%lld",&t);
	for(int i=1;i<=t;i++){
		a=1;
		scanf("%lld",&n);
		for(int j=1;j<=n;j++)
			a=a*j;
		printf("%lld\n",a);
	}
	return 0;
}
