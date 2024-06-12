#include<stdio.h>
int main(){
	int a[100];
	int t,min,max,n,minn,maxx,b,bb;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		minn=1;maxx=n;
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j]);
		min=a[1];max=a[n];
		for(int j=1;j<=n;j++){
			if(a[j]>max){
				max=a[j];
				maxx=j;
			}
			if(a[j]<min){
				min=a[j];
				minn=j;
			}
		}
		if(minn!=n && maxx==1){
			b=a[1];a[1]=a[minn];a[minn]=b;
			b=a[n];a[n]=a[minn];a[minn]=b;
		}
		else if(minn==n && maxx!=1){
			b=a[n];a[n]=a[maxx];a[maxx]=b;
			b=a[1];a[1]=a[maxx];a[maxx]=b;	
		}
		else{
			b=a[1];bb=a[n];
			a[minn]=b;a[maxx]=bb;
			a[1]=min;a[n]=max;
		}
		for(int j=1;j<n;j++)
			printf("%d ",a[j]);
		printf("%d\n",a[n]);
	}
	return 0;
}
