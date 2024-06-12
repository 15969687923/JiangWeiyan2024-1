#include<stdio.h>
int fun(int a,int b,int n){
	int f,f1,f2;
	if(n==1 || n==2)
		return 1;
	f1=fun(a,b,n-1);
	f2=fun(a,b,n-2);
	f=(a*f1+b*f2)%7;
	return f;
}
int main(){
	int a,b,n,f;
	while(1){
		scanf("%d%d%d",&a,&b,&n);
		if(a==0 && b==0 && n==0)
			break;
		if(n==1 || n==2)
			f=1;
		else{
			f=fun(a,b,n);
		}
		printf("%d\n",f);
	}
	return 0;
} 

