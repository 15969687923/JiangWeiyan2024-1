#include<stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	if(a==1)
		printf("Good morning");
	else if(a==2)
		printf("Good afternoon");
	else if(a==3)
		printf("Good evening");
	else if(a==4)
		printf("Good night");
	else
		printf("Bye bye");
	return 0;
}
