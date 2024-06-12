#include<stdio.h>
int main(){
	int a,b,f,i;
	long long n;
	int fun[60];
	fun[1]=1;fun[2]=1;
	while(1){
		scanf("%d%d%lld",&a,&b,&n);
		if(a==0 && b==0 && n==0)
			break;
		else
			for(i=3;i<=48;i++)       //每49个数循环 
				fun[i]=(a*fun[i-1]+b*fun[i-2])%7;
		printf("%d\n",fun[n%49]);
	}
	return 0;
} 

