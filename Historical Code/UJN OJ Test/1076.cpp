#include<stdio.h>
#include<math.h>
int main(){
	long long a;
	long long b,c,d=1;
	scanf("%lld",&a);
	for(int i=1;i<=a;i++){
		d=1;
		scanf("%lld",&b);
		while(b!=0){
			c=b%10;
			d=d*c;
			b=b/10;
		}
		printf("%lld\n",d);
	}
	return 0;
}
