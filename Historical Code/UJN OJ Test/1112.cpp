#include<stdio.h>
int main(){
	int m,n,i,j;
	int a[15][15];
	while(scanf("%d%d",&m,&n)!=EOF){
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		for(i=1;i<=m;i++){
			printf("%d ",a[i][n]);
			for(j=1;j<n-1;j++)
				printf("%d ",a[i][j]);
			printf("%d\n",a[i][n-1]);
		}
	}
	return 0;
}
