#include<stdio.h>
#include<string.h>
int main(){
	int t,i,j;
	char a[110],b[110];
	scanf("%d",&t);
	getchar();
	while(t--){
		gets(a);
		j=0;
		for(i=0;a[i]!='\0';i++)
			if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
				b[j++]=a[i];
		b[j]='\0';
		puts(b);
	}
	return 0;
}
