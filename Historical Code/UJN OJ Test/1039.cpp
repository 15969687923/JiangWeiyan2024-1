#include<stdio.h>
int main(){
	int m,n,b=0;
	int a[1000];
	scanf("%d%d",&m,&n);
	for(int i=m;i<=n;i++){
		if(i%3==0&&i%5!=0)
			a[b++]=i;
	}
	for(int i=0;i<b-1;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[b-1]);
	return 0;
}
