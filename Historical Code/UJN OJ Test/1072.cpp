
#include<stdio.h>
int main(){
	float a,b;
	while(scanf("%f",&a)!=EOF)
		if(a==0)
			return 0;
		else
			{
			b=(a-32)*5.0/9;
			printf("%.2f\n",b);
			}
	return 0;
}
