#include<stdio.h>
#include<math.h>
int main(){
	#define PI 3.1415927
	double r,v;
	while(scanf("%lf",&r)!=EOF){
		printf("%.3lf\n",(4.0/3.0)*PI*r*r*r);
	}
}
