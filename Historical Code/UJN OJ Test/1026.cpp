#include<stdio.h>
int main(){
	int a,t;
	double b;
	scanf("%d%d",&a,&t);
	if(t<=12){
		b=a+a*0.009;
		for(int i=1;i<t;i++){
			b=b+b*0.009;
		}
	}
	else if(t<=24){
		b=a+a*0.01;
		for(int i=1;i<t;i++){
			b=b+b*0.01;
		}
	}
	else if(t<=36){
		b=a+a*0.0111;
		for(int i=1;i<t;i++){
			b=b+b*0.0111;
		}
	}
	else{
		b=a+a*0.012;
		for(int i=1;i<t;i++){
			b=b+b*0.012;
		}
	}
	printf("%.2lf",b);
	return 0;
}
