#include<stdio.h>
int main(){
	long a,b=0,c;
	while(scanf("%ld",&a)!=EOF){
		b=0;
		while(a>0){
			a=a/10;
			b=b+1;
		}
		printf("%ld\n",b);
	}
}
