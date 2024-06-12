#include<stdio.h>
int main(){
	int n,h,k,m;
	while(scanf("%d%d",&n,&k)!=EOF){
		h=0;
		for(int i=1;i<=n;i++){
			m=1;
			for(int j=1;j<=k;j++){
				m=m*i;	
			}
			h=h+m;
		}
		printf("%d\n",h);
	}
	return 0;
	
} 
