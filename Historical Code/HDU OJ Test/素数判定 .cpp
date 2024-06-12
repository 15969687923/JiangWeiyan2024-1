#include<stdio.h>
#include<math.h>
int main(){
	int x,y,i,j,n,q,sum;
	while(1){
		scanf("%d%d",&x,&y);
		sum=0;
		if(x==0 && y==0)
			break;
		else{
			for(i=x;i<=y;i++){
				n=i*i+i+41;
				q=sqrt(n);
				for(j=2;j<=q;j++){
					if(n%j==0)
						sum++;
				}
			}
			if(sum==0)
				printf("OK\n");
			else
				printf("Sorry\n");
		}
	}
	return 0;
}
