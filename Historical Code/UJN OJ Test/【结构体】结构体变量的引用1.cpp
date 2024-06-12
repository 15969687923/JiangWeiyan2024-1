#include<stdio.h>
int main(){
	struct stu{
		int a;
		char b[8];
		int c[5];
	}st[4];
	int sum[4]={0},j=1;
	for(int i=1;i<=3;i++)
		scanf("%d%s%d%d%d%d",&st[i].a,&st[i].b,&st[i].c[1],&st[i].c[2],&st[i].c[3],&st[i].c[4]);
	for(int j=1;j<=3;j++)
		for(int i=2;i<=4;i++){
			sum[j]=sum[j]+st[j].c[i];
	}
	for(int i=1;i<=3;i++)
		printf("%d %d\n",st[i].a,sum[i]);
	return 0;
	
} 
