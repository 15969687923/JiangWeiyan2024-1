#include<stdio.h>
int main(){
	int t,n,max,min,min1=1,max1=1,j;
	int b[56];
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		max=0;min=0;
		scanf("%d",&n);
		scanf("%d",&max);
		min=max;
		for(j=2;j<=n;j++)
		{
			scanf("%d",&b[j]);
			if(b[j]<min){
				min=b[j];
				min1=j;
			}
			else if(b[j]>max){
				max=b[j];
				max1=j;
			}
		}
	//	if(min1==1 && max1==n){
	//		for(int m=1;m<=n;m++)
	//		printf("%d ",b[m]);
	//		printf("\n");
	//	}
	//	else{
			b[53]=b[1];
			b[52]=b[n];
			b[min1]=b[53];
			b[max1]=b[52];
			b[1]=min;
			b[n]=max;
			for(int m=1;m<=n;m++)
				printf("%d ",b[m]);
			printf("\n");
	//	}
	}
	return 0;
}
