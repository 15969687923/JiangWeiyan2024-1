#include<stdio.h>
#include<math.h>
int main(){
	int x;
	double a,b,c;
	scanf("%d",&x);
	if(x<-1){
		a=pow(x,3)-1;
	}
	else if(x<=1&&x>=-1)
		a=(-3*x)+1;
	else if(x<=10&&x>1){
		b=2*x-1;
		a=3*exp(b)+5;
	}
	else if(x>10){
		c=2*pow(x,2)-1;
		a=5*x+3*log10(c)-13;
	}
	printf("%.2lf\n",a);
	return 0;
}
