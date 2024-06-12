#include<stdio.h>
int main(){
	long long a,n,s=0,c=0,b;
	scanf("%lld%lld",&a,&n);
	for(int i=1;i<=n;i++){
		c=c*10+a;
		s=s+c;
	}
	printf("%lld",s);
	return 0;
}
