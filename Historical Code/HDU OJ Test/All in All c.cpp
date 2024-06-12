
#include<stdio.h>
#include<string.h>
#define MAXN 110000
char s[MAXN],t[MAXN];
int delstrcmp(char *s,char *t)
{
	int i,j,slen,tlen;
	slen=strlen(s);
	tlen=strlen(t);
	for(i=0,j=0;i<slen&&j<tlen;){
		if(s[i]==t[j]){
			i++;
			j++;
		}else
			j++;
	}
	return i==slen;
}
int main(void)
{
	while(scanf("%s%s",s,t)!=EOF)
		printf("%s\n",delstrcmp(s,t)?"Yes":"No");
	return 0;
}
