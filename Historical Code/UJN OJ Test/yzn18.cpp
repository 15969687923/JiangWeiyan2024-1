#include<stdio.h>
#include<math.h>
int main()
{
  int x,y,i,j,k,z;
  double s;
  while(1)
  {
  k=0;
   scanf("%d%d",&x,&y);
   if(x==0&&y==0)
    break;
	for(i=x;i<=y;i++)
	 {
	   z=i*i+i+41;
	   s=sqrt(i);
	   for(j=2;j<s;j++)
		 if(z%j==0)
		 {
		   k++;
		  break;
		 }
	}
	if(k==0)
	printf("OK\n");
	else
	printf("Sorry\n");
   }
   return 0;
}

