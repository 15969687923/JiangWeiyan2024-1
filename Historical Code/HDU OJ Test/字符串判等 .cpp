#include<stdio.h>
#include<string.h>
void chuli(char a[1100]){
	int i,j;
	while(a[0]==' ')
		for(i=0;a[i]!='\0';i++)
			a[i]=a[i+1];
	for(i=0;a[i]!='\0';i++){
		if(a[i]==' '){
			for(j=i;j<strlen(a);j++)
				a[j]=a[j+1];
			i--;
		}
		if(a[i]>='a' && a[i]<='z')
			a[i]=a[i]-32;
	}
}
int main(){
	char a[1100],b[1100];
	gets(a);gets(b);
	chuli(a);
	chuli(b);
	if(strcmp(a,b)==0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
