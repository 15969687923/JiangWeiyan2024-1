#include<stdio.h>
int main(){
	double a,b;
	int c;	
	double d;
	while(scanf("%lf%lf%d",&a,&b,&c)!=EOF){
		if(a==0 && b==0)
			return 0;
		else{
			d=a/b;
			printf("%.*lf\n",c,d);
		}
	}
	
}
