#include<stdio.h>
#include<string.h>
int main(){
	char a[110];
	int b[1100],i;
	while(gets(a)){
		memset(b,0,sizeof(b));
		for(i=0;a[i]!='\0';i++){
			if(b[a[i]]==0){
				printf("%c",a[i]);
				b[a[i]]=1;
			}
		}
		printf("\n");
	}
	return 0;
}
