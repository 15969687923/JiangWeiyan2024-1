#include<stdio.h>
int main(){
	int n,a,b,c;
	double d;
	while(scanf("%d",&n)!=EOF){
		a=0;b=0;c=0;
		if(n==0)
			break;
		else{
			for(int i=1;i<=n;i++){
				scanf("%lf",&d);
				if(d<0)
					a++;
				if(d==0)
					b++;
				if(d>0)
					c++;
			}
			printf("%d %d %d\n",a,b,c);
		}
	}
	return 0;
	
} 
