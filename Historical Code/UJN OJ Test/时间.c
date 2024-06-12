#include <stdio.h>
#include <stdlib.h>
#include<math.h> 
int main(int argc, char *argv[])
{
	long a;
	int b,c,d,e;
	scanf("%l",&a);
	b=a/86400;
	c=(a%86400)/3600;
	d=((a%86400)%3600)/60;
	e=(((a%86400)%3600)%60);
	printf("%02d %02d:%02d:%02d",b,c,d,e);
	
  system("PAUSE");	
  return 0;
}
