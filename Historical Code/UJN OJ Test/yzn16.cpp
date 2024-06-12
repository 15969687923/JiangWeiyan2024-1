#include<stdio.h>
#include<math.h>
int main()
{ 
  int i,m,n,a,b,c,d;
  while(scanf("%d%d",&m,&n)!=EOF)
  {
  d=0;
  i=m;
  while(i<=n)
  {
   a=i/100;
   b=(i-(a*100))/10;
   c=i-a*100-b*10;
  if(i==pow(a,3)+pow(b,3)+pow(c,3)&&d==0)
     {
	  printf("%d",i);
      d++;
  }
  else if(i==pow(a,3)+pow(b,3)+pow(c,3)&&d!=0)
	  {
	  printf(" %d",i);
      d++;
  }
  if(d==0)
  printf("no\n");
  i++;
  }
  printf("\n");
  }
  
     return 0;
}
