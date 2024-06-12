#include<stdio.h>
int main(){
	char c;
	while((c=getchar())!=EOF)
		if(c>='0' && c<='9')
			printf("numeric\n");
		else if((c>='a' && c<='z') || (c<='Z' && c>='A'))
			printf("alpha\n");
		else if(c!=10)
			printf("other\n");
		return 0;
}
