#include<stdio.h>
int main(){
	double a,b;
	int c;
	while(scanf("%lf",&a)!=EOF){
		b=a-(int)a;
		c=(int)a;
		printf("%d %.6lf\n",c,b);
	}
	return 0;
} 
