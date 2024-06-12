#include<stdio.h>
int main(){
	int t,n,i,j,k,count;
	int a[15][15];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		i=0;j=0;
		count=n*n;
		while(count>0){
			for(k=1;k<n;k++){//ÉÏ±ß 
				count--;
				printf("%d ",a[i][j]);
				j++;
			}
			for(k=1;k<n;k++){//ÓÒ±ß 
				count--;
				printf("%d ",a[i][j]);
				i++;
			}
			for(k=1;k<n;k++){//ÏÂ±ß
				count--;
				printf("%d ",a[i][j]);
				j--;
			}
			for(k=1;k<n;k++){//×ó±ß 
				count--;
				printf("%d ",a[i][j]);
				i--;
			}
			i++;j++;
			n=n-2;
		}
		printf("\n");
	}
	return 0;
} 
