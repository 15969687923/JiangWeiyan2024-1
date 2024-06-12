#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++){
		c=0;
		for(int j=2;j<a;j++)
		{
			if(i%j==0 )
			c++;
		}
		if(c==0)
			printf("%d ",i);
		}
		return 0;
}
