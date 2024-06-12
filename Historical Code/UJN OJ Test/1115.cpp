#include<stdio.h>
int main(){
	int t,n,x;
	int a[300];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&x);
		for(int i=1;i<=n;i++){
			if(a[i]%x==0 || a[i]%10==x || a[i]/10==x)
				printf("%d\n",a[i]);
		}
	}
	return 0;
}
