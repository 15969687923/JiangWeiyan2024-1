#include<stdio.h>
int main()
{
  int T,i,j;
  char a[100],b[100];
  scanf("%d",&T);
  getchar();
  while(T--)
   {
    gets(a);
    j=0;
    for(i=0;a[i]!='\0';i++)
		if((a[i]>=65&&a[i]<=90)||(a[i]>=97&&a[i]<=122))
		{ 
		  b[j]=a[i];
          j++;
		}
	b[j]='\0';
        puts(b);
   }
    return 0;
}

