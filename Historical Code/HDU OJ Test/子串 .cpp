#include<stdio.h>
#include<string.h>
int main(){
	int t,n,i,j,x,min,mina;
	char a[110][110],b[110],c[110];
	scanf("%d",&t);
	while(t--){
		min=200;mina=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			gets(a[i]);
			x=strlen(a[i]);
			if(x<min){
				min=x;
				mina=i;
			}
			for(i=0;i<min;i++)
				for(j=0;j<i;j++)
			}
		}
	}
} 
