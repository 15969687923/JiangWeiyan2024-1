#include<stdio.h>
//#include<math.h>
int main(){
	int m,n,sum,i,j,k;
	while(scanf("%d%d",&m,&n)!=EOF){
		sum=0;
		if(m>n)
			for(i=n;i<=m;i++){
				//k=(int)sqrt(i);
				for(j=2;j<=i/2;j++)
					if(i%j==0){
						break;
					}
				if(j==k+1)
					sum++;			
			}
		else
			for(i=m;i<=n;i++){
				j=2;
				//k=(int)sqrt(i);
				for(j=2;j<=i/2;j++)
					if(i%j==0){
						break;
					}
				if(j==k+1)
					sum++;			
			}
		printf("%d\n",sum);
	}
	return 0; 
}

