#include<stdio.h>
int main(){
	int a;
	char b;
	scanf("%d",&a);
	if(a>=90&&a<=100)
		b='A';
	else if(a<=89&&a>=80)
		b='B';
	else if(a<=79&&a>=70)
		b='C';
	else if(a<=69&&a>=60)
		b='D';
	else
		b='E';
	printf("%c\n",b);
	return 0;
}
