#include<stdio.h>
#include<math.h>

int main(){
	const double PI=4.0*atan(1.0);
	long a;
	double h;
	scanf("%ld",&a);
	h=pow((6.67*pow((double)10,-11)*6*pow((double)10,24)*a*a)/(4*PI*PI),1.0/3.0)-6.371*pow((double)10,6);
	printf("%.0lf",h);
	return 0;
}
