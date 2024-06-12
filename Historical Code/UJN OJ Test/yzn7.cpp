#include<stdio.h>
int main()
{ 
  int i,j,a[5]={1,3,6,9,12},b[5]={2,5,7,10,15},c[10000],t;
  for(i=5;i<10;i++)
  a[i]=b[i-5];
  for(i=0;i<10;i++)
  c[i]=a[i];
  for(i=0;i<9;i++)
   for(j=i+1;j<10;j++)
     if(a[i]>a[j])
	  { 
	    t=a[i];
	    a[i]=a[j];
        a[j]=t;
	  }
	  for(i=0;i<10;i++)
	  printf("%d",c[i]);
	  return 0;
}

