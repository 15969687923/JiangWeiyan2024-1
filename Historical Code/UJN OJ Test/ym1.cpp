#include <stdio.h>
int b[100],m;
int i,t,s[100];
int fun()
{
	int i,n=0;
	float sum=0,ave;
	for(i=0;i<m;i++)
		sum=sum+s[i];
	ave=sum/m;
	for(i=0;i<m;i++)
		if(s[i]<ave)
		{
			b[n]=s[i];
			n++;
		}
	return(n);
}
int main()
{
	
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&s[i]);
	}
	t=fun();//再加一部分排序，则可以用 返回值n，，否则完全用不到写函数。。总觉得这个题是为了用函数而用函数。。。 
	for(i=0;i<n;i++)
	printf("%d ",b[i]);
}

