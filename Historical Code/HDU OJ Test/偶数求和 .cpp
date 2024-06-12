#include<stdio.h>
int main(){
	int n,m,sum,ji,i,j,s,p,b;
	int a[110];
	while(scanf("%d%d",&n,&m)!=EOF){
		s=2;ji=1;b=1;sum=0;
		while(1){
			if(ji+m>n)
				break;
			for(i=1;i<=m;i++){
				sum=sum+s;
				s=s+2;
				ji++;
			}
			p=sum/m;
			a[b++]=p;
			sum=0;
		}
		if(ji+m>n){
			for(i=ji;i<=n;i++){
				sum=sum+s;
				s=s+2;
			}
			p=sum/(i-ji);
			a[b]=p;
		}
		for(i=1;i<b;i++){
			printf("%d ",a[i]);
		}
		printf("%d\n",a[b]);
	}
	return 0;
} 
