#include<stdio.h>
int main(){
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF){
		if(a==0 && b==0 && c==0)
			return 0;
		else if(a+b<=c || a+c<=b || b+c<=a)
			printf("not a triangle\n");
		else if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
			printf("yes\n");
		else
			printf("no\n");
		
	}
	return 0;
}
