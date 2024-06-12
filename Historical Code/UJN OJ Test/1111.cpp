#include<stdio.h>
#include<string.h>
int main(){
	int m,n,s,z,i,j,h,k;
	int a[15][15],b[15][15],c[15][15]={0};
	while(scanf("%d%d%d",&m,&n,&s)!=EOF){
		memset(c,0,sizeof(c));
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		for(i=1;i<=n;i++)
			for(j=1;j<=s;j++)
				scanf("%d",&b[i][j]);
		for(i=1;i<=m;i++)
			for(j=1;j<=s;j++){
				for(k=1;k<=n;k++)
					c[i][j]+=a[i][k]*b[k][j];
				}
		for(i=1;i<=m;i++){
			for(j=1;j<s;j++)
				printf("%d ",c[i][j]);
			printf("%d\n",c[i][j]);
		}
	}
	return 0;
} 
