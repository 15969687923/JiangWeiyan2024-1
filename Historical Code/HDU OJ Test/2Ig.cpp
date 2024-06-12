#include<stdio.h>
int main(){
	int n,a,b,c,d;
	scanf("%d",&n);
		a=0;b=0;c=0;
		if(n==0)
			return 0;
		else{
		for(int i=1;i<=n;i++){
			scanf("%d",&d);
			if(d<0)
				a++;
			else if(d==0)
				b++;
			else
				c++;
		}
		printf("%d %d %d",a,b,c);
	}
	return 0;
	
} 
