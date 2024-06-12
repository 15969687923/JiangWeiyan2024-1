#include<stdio.h>
int main()
{ 
  int i,j,a[10],t;
  while(scanf("%d",&a[0])!=EOF)
  {
   for(i=1;i<10;i++)
    scanf("%d",&a[i]);
	for(i=0;i<10;i++)
	  for(j=i+1;j<10;j++)
	    if(a[i]>a[j])
		{
		  t=a[i];
		  a[i]=a[j];
		  a[j]=t;
		}
		for(i=0;i<9;i++)
		printf("%d ",a[i]);
		printf("%d",a[9]);
		printf("\n");
  }
  return 0;
}
