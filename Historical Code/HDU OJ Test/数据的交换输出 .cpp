#include<stdio.h>
int main(){
	int n,t,min,i,sam;
	int a[110];
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		scanf("%d",&a[1]);
		min=a[1];
		sam=1;    //�����һ����С������ ���������Ҳ���� ������Ҳ���a��sam������Ϊt 
		for(i=2;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]<=min){
				min=a[i];
				sam=i;
			}
		}
		t=a[1];
		a[1]=min;
		a[sam]=t;
		for(i=1;i<n;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
	return 0;
}
