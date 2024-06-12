#include<stdio.h>
#include<math.h>
int main(){
	int n,m,i;
	double sum=1;
	scanf("%d",&n);
	while(n--){
		sum=1;
		scanf("%d",&m);
		for(i=1;i<=m;i++)
			sum=sum+log10(i);
		printf("%d\n",(int)sum);
	}
	return 0;
}
