#include<stdio.h>
#include<string.h>
int main(){
	int i,j;
	char a[110],b[110],c;
	while(gets(a)){
		c=getchar();
		getchar();
		j=0;
		for(i=0;a[i]!='\0';i++)
			if(a[i]!=c)
				b[j++]=a[i];
		b[j]='\0';
		puts(b);
	}
	return 0;
}
