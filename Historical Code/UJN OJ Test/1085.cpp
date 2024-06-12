#include<stdio.h>
int main(){
	double a=0,b=1,c=1,d=1;
	while(b>0.00000001 || b<-0.00000001){
		a=a+b*d;
		d=-d;
		c=c+2;
		b=1.0/c;
		//printf("%lf\n",b);
	}
	a=a*4.0;
	printf("%.6lf\n",a);
	
	return 0;
}
