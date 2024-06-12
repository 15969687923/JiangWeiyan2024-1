#include<stdio.h>
#include<math.h>
int main(){
	int n,m;
	double a,b;
	while(scanf("%d%d",&n,&m)!=EOF){
		a=n;b=n;
		for(int i=2;i<=m;i++){
			a=sqrt(a);
			b=a+b;
		}
		printf("%.2lf\n",b);
	}
	return 0;
} 
