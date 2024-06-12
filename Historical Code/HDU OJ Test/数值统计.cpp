#include<stdio.h>
int main(){
	int n,i,z,f,zero;
	float a;
	while(1){
		z=0;f=0;zero=0;
		scanf("%d",&n);
		if(n==0)
			break;
		for(i=1;i<=n;i++){
			scanf("%f",&a);
			if(a>0)
				z++;
			else if(a<0)
				f++;
			else
				zero++;
		}
		printf("%d %d %d\n",f,zero,z);
	}
	return 0;
} 
