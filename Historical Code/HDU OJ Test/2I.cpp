#include<stdio.h>
int main(){
	int n,a,b,c,d;
	scanf("%d",&n);
	while(n!=0){
		a=0;b=0;c=0;
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
