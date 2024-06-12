#include <stdio.h>
#include <math.h>
int main()
{
	double PI=0.0;
	double n=1.0;
	int i=1;
	while((1/n)>0.00000001)
    {
        if(i%2!=0)
            PI=PI+(1/n);
        if(i%2==0)
            PI=PI-(1/n);
        i++;
        n+=2;
    }
    PI=PI*4;
    printf("%.6lf",PI);
	return 0;
}

