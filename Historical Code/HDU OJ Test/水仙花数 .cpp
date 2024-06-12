#include<stdio.h>
int main(){
	int m,n,sum,i,b,c,d;
	int a[5];
	while(scanf("%d%d",&m,&n)!=EOF){
		sum=0;
		if(m<=n){
			for(i=m;i<=n;i++){
				b=i/100;
				c=i%10;
				d=i/10%10;
				if(i==b*b*b+c*c*c+d*d*d){
					a[sum]=i;
					sum++;
				}
			}
		}
		else{
			for(i=m;i<=n;i++){
			b=i/100;
			c=i%10;
			d=i/10%10;
			if(i==b*b*b+c*c*c+d*d*d){
				a[sum]=i;
				sum++;
				}
			}
		}
		if(sum==0)
			printf("no\n");
		else{
			for(i=0;i<sum-1;i++){
				printf("%d ",a[i]);	
			}
			printf("%d\n",a[sum-1]);
		}
	}
	return 0;
}
