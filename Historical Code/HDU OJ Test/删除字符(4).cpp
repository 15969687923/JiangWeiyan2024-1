#include<stdio.h>
#include<string.h>
int main(){
	int k,m,n,i,j;
	char a[110],b[110];
	while(scanf("%d%d",&k,&m)!=EOF){
		getchar();
		gets(a);
		for(i=k;i<=(k+m-1);i++)
			for(j=k;a[j]!='\0';j++)
				a[j]=a[j+1];
		puts(a);
	}
	return 0;
}
