#include<stdio.h>
int main(){
	int n=0,r,i,m,a;
	char s[10000];
	while(scanf("%s",s)!=EOF && s[0]!='0'){
		n=0;
		for(i=0;s[i]!='\0';i++)
			n=n+(s[i]-'0');
		while(n>=10){
			m=n;
			n=0;
			while(m>0){
				a=m%10;
				n=n+a;
				m=m/10;
			}
		}
		printf("%d\n",n);
	}
	return 0;
}
