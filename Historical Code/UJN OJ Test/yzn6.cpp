#include<stdio.h>
int main()
{
  int i,j,a[10000],T,n,k,t;
  scanf("%d",&T);
  while(T--)
  {
   k=0;
   scanf("%d",&n);
   for(i=0;i<n;i++)
    scanf("%d",a[i]);
	for(i=0;i<n-1;i++)
	 for(j=0;j<n-1-i;j++)
	if(a[j]>a[j+1])
	 { t=a[j];
	   a[j]=a[j+1];
	   a[j+1]=t;
	   k=k+1;
	 }
	  printf("%d\n",k);
   }
   return 0;
}

