#include<stdio.h>
int main(){
	int l,m,a,b,sum=0;
	int d[10010]={0};
	scanf("%d%d",&l,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		if(a<b)
			for(int j=a;j<=b;j++)
				d[j]=1;
		else
			for(int j=a;j<=b;j++)
				d[j]=1;
	}
	for(int j=0;j<=l;j++)
		if(d[j]==0)
			sum++;
	printf("%d\n",sum);
	return 0;
	
	
} 
