#include<stdio.h>
int main(){
	char a,b,c,max,min,med;
	while(scanf("%c",&a)!=EOF){
		max=a;
		min=a;
		med=a;
		for(int i=1;i<=2;i++){
			scanf("%c",&a);
			if(a>max){
				med=max;
				max=a;
			}
			else if(a<min){
				med=min;
				min=a;	
			}
			else
				med=a;
			}
			getchar();
		printf("%c %c %c\n",min,med,max);
		}
		return 0;
	}
 
