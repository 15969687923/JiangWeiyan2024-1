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
	printf("�㰮��Ժô��(yes/no)\n");
	scanf("%s",k);
	if(strcmp(k,"yes")==0){
		for(y=1.5;y>-1.5;y-=0.13){
			for(x=-1.5;x<1.5;x+=0.06){
				a=x*x+y*y-1;
				putchar(a*a*a-x*x*y*y*y<=0.0?'$':' ');
			}
		putchar('\n');
		}
		printf("               �Ұ���Ժ����Ժ���Ҽ�\n");  
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
			printf("               �������ţ�������ǰ�\n");
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

			printf("               �Ұ���Ժ����Ժ���Ҽ�\n");
			h=h-10000000;  
		}
	}
	else{
		printf("�� ʧȥ��Ժ�󱦱��� ��رհɣ�\n");
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
