#include<stdio.h>
#include<math.h>
int main(){
	int n;
	long long b=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		b=b*2; 
	printf("%lld",b);
	return 0;
}
