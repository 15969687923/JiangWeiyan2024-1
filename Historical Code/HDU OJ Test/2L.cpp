#include<stdio.h>
int main(){
	int m,n,d;
	double sum;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		sum=0;d=1;
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			sum=sum+1.0/(d*i);
			d=d*(-1);
		}
		printf("%.2lf",sum);
	}
	return 0;
} 
