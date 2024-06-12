#include<stdio.h>
#include<math.h>
int main(){
	int m,i;
	float sum,n;
	while(scanf("%f%d",&n,&m)!=EOF){
		sum=0;
		for(i=1;i<=m;i++){
			sum=sum+n;
			n=sqrt(n);
		} 
		printf("%.2f\n",sum);
	}
	return 0;
}
