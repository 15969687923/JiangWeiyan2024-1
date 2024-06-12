#include<stdio.h>
int main()
{ 	double i,x,a;
	int m,j;
	scanf("%d",&m);
	x=0;
	for(i=1;i<=m;i++)
		{
			for(j=2;j<=(i/2);j++)
				{
					if(m%j==0)
						{
					//	a=m/j;
						x=x+j;	
						}
				}
			//	x=x+1;
				if(x==i)
					printf("%d\n",i);
				x=0;
		}
		return 0;
}
