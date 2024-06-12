#include<stdio.h>
int main(){
	int a,b,c,d;
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		scanf("%d",&b);
		d=0;
		for(int j=1;j<=b;j++){
			scanf("%d",&c);
			d=d+c;
		}
		printf("%d\n\n",d);
	}
	return 0;
}
