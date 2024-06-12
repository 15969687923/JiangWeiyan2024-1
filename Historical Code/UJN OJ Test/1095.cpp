#include<stdio.h>
long run(int n){
	if(n==1 || n==2)
		return 1;
	else
	return run(n-1)+run(n-2);
}
int main(){
	int a,n;
	while(scanf("%d",&n)!=EOF){
		a=run(n);
		printf("%d\n",a);
	}
}
