#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define I 20
#define R 340
int main(){
	int i,n=65,h=9999999;
	long time;
	float y,x,a;
	char k[10];
	printf("你爱信院么？(yes/no)\n");
	scanf("%s",k);
	if(strcmp(k,"yes")==0){
		for(y=1.5;y>-1.5;y-=0.13){
			for(x=-1.5;x<1.5;x+=0.06){
				a=x*x+y*y-1;
				putchar(a*a*a-x*x*y*y*y<=0.0?'$':' ');
			}
		putchar('\n');
		}
		printf("               我爱信院，信院是我家\n");  
		//system("start d:\\");		

		for(; ; ){

			system("color a");
			for(time=0;time<h;time++); system("color b");
			for(time=0;time<h;time++); system("color c");
			for(time=0;time<h;time++); system("color d");
			for(time=0;time<h;time++); system("color e");
			for(time=0;time<h;time++); system("color f");
			for(time=0;time<h;time++); system("color 0"); 
			for(time=0;time<h;time++); system("color 1"); 
			for(time=0;time<h;time++); system("color 2"); 
			for(time=0;time<h;time++); system("color 3"); 
			for(time=0;time<h;time++); system("color 4");
			for(time=0;time<h;time++); system("color 5");
			for(time=0;time<h;time++); system("color 6");
			for(time=0;time<h;time++); system("color 7");
			for(time=0;time<h;time++); system("color 8");
			for(time=0;time<h;time++); system("color 9");
			for(time=0;time<h;time++); 		
			system("cls");
			printf("               换个符号，不变的是爱\n");
			n++;
			for(y=1.5;y>-1.5;y-=0.13){
				for(x=-1.5;x<1.5;x+=0.06){
					a=x*x+y*y-1;
					if(a*a*a-x*x*y*y*y<=0.0)
						printf("%c",n);
					else
						printf(" ");//'n' :' ');
						
				}
				putchar('\n');n++;
			}

			printf("               我爱信院，信院是我家\n");
			h=h-10000000;  
		}
	}
	else{
		printf("你 失去信院大宝贝了 快关闭吧！\n");
		for(y=1.5;y>-1.5;y-=0.13){
			for(x=-1.5;x<1.5;x+=0.08){
				a=x*x+y*y-1;
				putchar(a*a*a-x*x*y*y*y<=0.0? 3 :' ');
			}
		putchar('\n');
		}
	}
	return 0;
}
