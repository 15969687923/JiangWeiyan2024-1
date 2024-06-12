#include<stdio.h>
#include<string.h>
int main(){
	char a[10010];
	int cn,i,j;
	while(gets(a)){
		for(i=0;a[i]!='\0';){
			cn=1;
			for(j=i+1;a[j]!='\0' && a[i]==a[j];j++)
				cn=cn+1;
			if(cn>1)
				printf("%d",cn);
			printf("%c",a[i]);
			i=j;
		}
		printf("\n");
	}
	return 0;
}
