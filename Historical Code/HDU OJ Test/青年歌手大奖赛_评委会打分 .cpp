#include<stdio.h>
int main(){
	int n,i,j,t;
	float sum;
	int a[110];
	while(scanf("%d",&n)!=EOF){
		sum=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n-1;i++)
			for(j=1;j<=n-i;j++){
				if(a[j]<a[j+1]){
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}		
			}
		for(i=2;i<n;i++)
			sum=sum+a[i];
		printf("%.2f\n",sum/(n-2));	
	}
	return 0;
}
