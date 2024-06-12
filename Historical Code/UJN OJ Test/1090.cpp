#include<stdio.h>
int main(){
	for(int a=0;a<=9;a++)
		for(int b=0;b<=12;b++)
			for(int c=0;c<=36;c++)
				if(a+b+c==36 && 4*a+3*b+0.5*c==36)
					printf("%d %d %d\n",a,b,c);
	return 0;
}
