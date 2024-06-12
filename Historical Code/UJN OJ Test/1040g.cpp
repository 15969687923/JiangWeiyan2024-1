#include<stdio.h>
#include<math.h>
int main()
{
  int m,n,i,j,a[100],k=0;
  scanf("%d%d",&m,&n);
  for(i=m;i<=n;i++)
  {
	  	for(j=2;j<=sqrt(i);j++)
	      	if(i%j==0)
		  		break;
		if(j>sqrt(i))
		  	a[k++]=i;
  }
  for(i=0;i<k-1;i++)
  	printf("%d ",a[i]);
  printf("%d",a[k-1]);
  return 0;
}


