#include<stdio.h>
int main(){
	int n,a,b=1;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			if(a%2!=0)
				b=b*a;
		}
		printf("%d\n",b);
		b=1;
	}
}
