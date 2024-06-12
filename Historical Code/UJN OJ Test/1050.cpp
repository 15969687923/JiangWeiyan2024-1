#include<stdio.h>
int main(){
	int n;
	double a=1;
	scanf("%d",&n);
	for(int i=2;i<=n;i=i+2)
		a=a+1.0/i;
	printf("%.6lf",a);
	return 0;
}
