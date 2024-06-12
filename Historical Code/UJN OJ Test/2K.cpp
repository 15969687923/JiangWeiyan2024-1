#include<stdio.h>
int main(){
	int m,n,a,b,c,num;
	while(scanf("%d%d",&m,&n)!=EOF){
		num=0;
		for(int i=m;i<=n;i++){
			a=i%10;
			b=(i/10)%10;
			c=i/100;
			if(a*a*a+b*b*b+c*c*c==i){
				printf("%d ",i);
				num++;}
		}
		if(num==0)
			printf("no");
		printf("\n");
	}
	return 0;
}
