#include<stdio.h>
int main(){
	int m,n,i,j;
	double a,b,c,d;
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		b=1;c=1;a=0;d=1;
		scanf("%d",&n);
		for(j=1;j<=n;j++){
			a=a+d*c;
			b++;
			d=1/b;
			c=c*(-1);
		}
		printf("%.2lf\n",a);
	}
	return 0;
}
