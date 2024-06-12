#include<stdio.h>
int main(){
	int n,a=0,b=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		a=0;
		for(int j=2;j<=i-1;j++){
			if(i%j==0)
				a=a+1;
		}
		if(a==0)
			b=b+1;
	}
	printf("%d",b);
	return 0;
}

