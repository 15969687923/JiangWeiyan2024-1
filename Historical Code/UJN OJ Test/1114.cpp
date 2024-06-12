#include<stdio.h>
int main(){
	int t,a[15],n,sum;
	scanf("%d",&t);
	while(t--){
		sum=0;
		for(int i=1;i<=10;i++)
			scanf("%d",&a[i]);
		scanf("%d",&n);
		for(int i=1;i<=10;i++)
			if(a[i]<=n+30)
				sum++;
		printf("%d\n",sum);
	}
	return 0;
}
