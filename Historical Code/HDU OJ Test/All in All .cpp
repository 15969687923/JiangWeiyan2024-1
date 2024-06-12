#include<stdio.h>
#include<string.h>
int main(){
	char s[110000],t[110000];
	int i,j;
	while(scanf("%s%s",s,t)!=EOF){
		for(i=0,j=0;j<strlen(t) && i<strlen(s);){
			if(s[i]==t[j]){
				j++;
				i++;
			}
			else
				j++;
		}
		if(i==strlen(s))
			printf("Yes\n");
		else
			printf("No\n");
	} 
	return 0;
}
