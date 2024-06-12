#include<stdio.h>
#include<math.h>
void fun(int n)
{
  int a,b,i,c[100],k,j,d;
  d=0;
  for(i=1;i<n;i++)
  {		k=0; 
       for(j=2;j<=sqrt(i);j++)
		   if(i%j==0) 
		    k++;
       if(k==0)
       c[d++]=i;
  }
  for(i=0;i<d;i++)
	for(j=0;j<d;j++)
	  if(c[i]+c[j]==n)
	  {
	     a=c[i];
	     b=c[j];
		 printf("%d %d\n",a,b);
		}         
		
}
	  
int main()
{
  int n;
  scanf("%d",&n);
  fun(n);
  return 0;
}
