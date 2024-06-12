#include<stdio.h>
int main(){
	int n,a,b,i,max,min;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		if(a%2!=0 || a<=0){
			printf("0 0\n");
		}
		else{
			if(a%4==0){
				min=a/4;max=a/2;
			}
			else{
				min=a/4+1;max=a/2;
			}
			printf("%d %d\n",min,max);
		}
	}
	return 0;
} 
