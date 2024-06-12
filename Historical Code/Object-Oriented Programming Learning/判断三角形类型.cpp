#include<math.h>
#include<stdio.h>
int fff(double a,double b){
	if(fabs(a-b)<0.000001)
		return 1;
	else
	return 0; 
}
int main()
{
    float a,b,c,d;
    scanf("%f%f%f",&a,&b,&c);
    if(a>b){
    	d=a;
    	a=b;
    	b=d;
    	if(b>c){
    		d=b;
    		b=c;
    		c=d;
		}
		if(a>b){
			d=a;
	    	a=b;
	    	b=d;
		}
	}
    if(a>=c+b||b>=a+c||c>=a+b)
    {
        printf("It isn't triangle.\n");
    }
    else if(a==b&&b==c)
    {
        printf("equilateral triangle\n");
    }
    else if(a==b||b==c||c==a)
    {
        printf("isoceles triangle\n");
    }
    else if(fff(a*a,(b*b+c*c))||fff(b*b,(a*a+c*c))||fff(c*c,(b*b+a*a)))
    {
        printf("right-angled triangle\n");
    }
    else
    {
        printf("arbitrary triangle\n");
    }
    return 0;
}

