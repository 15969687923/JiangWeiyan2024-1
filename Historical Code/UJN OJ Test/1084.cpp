#include<stdio.h>
int main(){
	int n;
	float a,b=0;
	while(scanf("%d",&n)!=EOF){
		b=0;
		if(n==0)
			return 0;
		else
		for(int i=1;i<=n;i++){
			b=b+1.0/i;
		}
		printf("%.3f\n",b);
			
	}
		
}
