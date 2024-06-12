#include<stdio.h>
#include<string.h>
int main()
{
	int i,j=0,n,b;
	char ch[110],a[110];
	while(gets(ch)){
		j=0;
	     n=strlen(ch);
	     for(i=n-1,j=0;i>=0 && j<n;i--,j++){
	     	a[i]=ch[j];
	     }
	     b=strcmp(ch,a);
	     if(b==0)
	     	printf("Yes\n");
	    else
	    printf("No\n");
	}
     return 0;
}
