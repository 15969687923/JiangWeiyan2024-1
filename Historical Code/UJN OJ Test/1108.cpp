#include<string.h>
#include<stdio.h>
int main(){
	int a[11]={0};
	int i,j,n;
	while(scanf("%d",&n)!=EOF){
		memset(a,0,sizeof(a));
		a[0]=1;
		for(i=0;i<n;i++){
			for(j=i;j>0;j--)
				a[j]+=a[j-1];
		  	for(j=0;j<i;j++)
			  	printf("%d ",a[j]);
			printf("%d",a[j]);
		  	printf("\n");
		}
	}
	return 0;
}
