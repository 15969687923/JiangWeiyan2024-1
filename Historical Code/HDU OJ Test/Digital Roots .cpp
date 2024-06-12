#include<stdio.h>
#include<string.h>
int main(){
	int a,i,sum=0,n;
	char b[100000];
	while(scanf("%s",b)!=EOF && b[0]!='0'){
		sum=0;
		for(i=0;i<strlen(b);i++)
			sum=sum+b[i]-'0';
	while(sum>=10)
		{
			n=sum;
			sum=0;
			while(n)
			{
				sum+=n%10;
				n/=10;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
