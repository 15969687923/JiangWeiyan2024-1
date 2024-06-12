#include<stdio.h>
#include<math.h>
int main(){
	double a,b,c;
	double x1=0,x2=0,d;
	scanf("%lf%lf%lf",&a,&b,&c);
		d=b*b-4*a*c;
	if(a==0){
		printf("No");
		return 0;
	}
	

	else if(d>=0){
		x1=(-b+sqrt(d))/(2*a);
		x2=(-b-sqrt(d))/(2*a);
		printf("%.2lf %.2lf\n",x2,x1);
	}
	else if(d<0){
		x1=-b/(2*a);
		x2=sqrt(-d)/(2*a);
		printf("%.2lf-%.2lfi %.2lf+%.2lfi\n",x1,x2,x1,x2);
	}
		return 0;
}
