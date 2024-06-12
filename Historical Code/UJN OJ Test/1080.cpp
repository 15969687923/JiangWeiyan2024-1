#include<stdio.h>
#include<math.h>
int main(){
	int m,n,a,b,c,sum=0,j,i,d;
	while(1){
		scanf("%d%d",&m,&n);
		sum=0;
		if(m==0&&n==0)
			break;
		for(j=m;j<=n;j++){
			i=j;
			a=i%10;
			i=i/10;
			b=i%10;
			c=i/10;
			d=pow(a,3)+pow(b,3)+pow(c,3);
			if(d==j)
				sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
