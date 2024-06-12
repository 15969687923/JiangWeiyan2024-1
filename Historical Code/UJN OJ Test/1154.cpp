#include<stdio.h>
int main(){
	int n,max,max1=0,a;
	while(getchar()!='\n'){
		a=0;
		while(scanf("%d",&max)!=EOF){
			scanf("%d",&n);
			a++;
			if(max<n){
				max1=max;
				max=n;
			}
			if(max1<n && n!=max){
				max1=n;
			}
		}
		printf("%d %d\n",max,max1);
		max=0;
		max1=0;
		if(a==0)
			break;
	}
}
