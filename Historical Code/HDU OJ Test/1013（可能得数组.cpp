#include<stdio.h>
int main(){
	int n,r,i,m,a;
	while(scanf("%d",&n)!=EOF && n!=0){
		while(n>=10){
			m=n;
			n=0;
			while(m>0){
				a=m%10;
				n=n+a;
				m=m/10;
			}
		}
		printf("%d\n",n);
	}
	return 0;
}
