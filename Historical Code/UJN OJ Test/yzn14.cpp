#include<stdio.h>
#include<string.h>
int main()
{
  int i,j,n;
  char ch[100],a[100];
  while(gets(ch))
  {
     j=0;
	 
	 n=strlen(ch);
	 for(i=0;i<n;i++)
	   if(ch[i]!=' ')
       {
	     a[j]=ch[i];
		 j++;
	   }
	if(stricmp(a,ch)==0)
		printf("Yes\n");
	else
		printf("No\n");
   }
     return 0;
}
