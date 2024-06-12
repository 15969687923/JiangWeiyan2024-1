#include<stdio.h>
#include<string.h>
int main(){
	int n,max,maxa,i;
	char a[1100];
	int b[200];
	scanf("%d",&n);
	getchar();
	while(n--){
		gets(a);
		max=0;
		memset(b,0,sizeof(b));
		for(i=0;a[i]!='\0';i++)
			b[a[i]]++;
		for(i=97;i<=122;i++)
			if(max<b[i]){
				max=b[i];
				maxa=i;
			}
		printf("%c %d\n",maxa,max);
		getchar();
	}
	return 0;
}
