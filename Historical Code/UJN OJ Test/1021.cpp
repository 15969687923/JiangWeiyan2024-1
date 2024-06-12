#include<stdio.h>
int main(){
	char a;
	a=getchar();
	if((a>='a'&&a<='z')||(a>='A'&&a<='Z')){
		printf("alpha\n");
	}
	else if(a>='0'&&a<='9')
		printf("numeric\n");
	else
		printf("other\n");
	return 0;
}
