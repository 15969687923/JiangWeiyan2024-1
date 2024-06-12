#include<stdio.h>
#include<stdlib.h>
int main()
{
 int characers[26];
 int n,m,p;
int i,j;
for(i=0;i<26;i++) characers[i]=0;
 scanf("%d%d%d",&n,&m,&p);
for(i=0;i<n;i++)
 {
 char str[11];
scanf("%s",str);
 for(j=0;str[j]!='\0';j++)
 characers[str[j]-'A']++;
 }
 for(i=0;i<p;i++)
{
char str[11];
 scanf("%s",str);
 for(j=0;str[j]!='\0';j++)
{
 characers[str[j]-'A']--;
}
 }
 for(i=0;i<26;i++)
{
if(characers[i]!=0)
{
 for(j=0;j<characers[i];j++)
 printf("%c",i+'A');
}
 }
 printf("\n");

 return 0;
}
