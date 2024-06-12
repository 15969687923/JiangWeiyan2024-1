#include<stdio.h>
int main(){
	int t,n,x,b;
	int a[100];
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		b=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[j]);
		}
		scanf("%d",&x);
		for(int j=1;j<=n;j++){
			if(a[j]==x)
				b=b+1;
				
		}
		if(b!=0)
		printf("find!\n");
		else
		printf("no find!\n");
	}
	return 0;
}
