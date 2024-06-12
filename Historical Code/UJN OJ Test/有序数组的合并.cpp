#include<stdio.h>
int main(){
	int a[25];
	int m,n,t;
	for(int i=1;i<=2;i++){
		scanf("%d%d",&m,&n);
		for(int j=1;j<=m+n;j++)
			scanf("%d",&a[j]);
		for(int o=1;o<=m+n-1;o++)
			for(int p=1;p<=m+n-o;p++){
				if(a[p]>a[p+1]){
					t=a[p];
					a[p]=a[p+1];
					a[p+1]=t;
				}
			}
		for(int j=1;j<=m+n-1;j++)
		printf("%d ",a[j]);
		printf("%d",a[m+n]);
		printf("\n");
	}
	return 0;
} 
