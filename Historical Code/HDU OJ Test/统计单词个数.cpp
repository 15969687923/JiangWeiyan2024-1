#include<stdio.h>//标点符号后有空格。!
#include<string.h>
int main(){
	char a[300];
	int i,sum,n,x;
	while(gets(a)){
		sum=0;
		n=strlen(a);
		while(a[0]==' ')
			for(i=0;i<n;i++)
				a[i]=a[i+1];
		n=strlen(a);
		for(i=n-1;a[i]==' ';i--)
			if(a[i]==' ')
				a[i]='\0';
		n=strlen(a);
		for(i=0;i<n;i++)
			if(a[i]==' ' && a[i+1]!=' ')
				sum++;
		printf("%d\n",sum+1);
	}
	return 0;
} 
