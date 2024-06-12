#include<stdio.h>
int main()
{
  int n,i,a,b,c;
  double m; 
  a=0;b=0;c=0;
  while(scanf("%d",&n)!=0)
  { 
	a=0;b=0;c=0;
  	for(i=1;i<=n;i++)
   {
    	scanf("%lf",&m);
     	if(m>0)
	  		c++;
	 	else if(m==0)
	  		b++;
	 	else if(m<0)
	  		a++;
   }
    printf("%d %d ",a,b);
	printf("%d\n",c);
   }
	return 0;
}
