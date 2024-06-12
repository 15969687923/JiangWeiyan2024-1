#include<stdio.h>
#include<math.h>
int main(){
	float a,b,c,d,e;
	while(scanf("%f%f%f",&a,&b,&c)!=EOF)
		if(a==0 && b==0 && c==0)
			return 0;
		else if(a+b>c && a+c>b && b+c>a){
			d=(a+b+c)/2.0;
			e=sqrt(d*(d-a)*(d-b)*(d-c));
			printf("%.2f\n",e);
		}
		else
			printf("NO\n");
	return 0;
			
}
