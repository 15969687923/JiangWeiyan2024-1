#include<stdio.h>
int main(){
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF){
		for(int i=10;i<=101;i++){
			  if(i==101)
				printf("No answer\n");
		    	 else if(i%3==a && i%5==b && i%7==c){
				printf("%d\n",i);
				break;
			}
			
		}
	}
}
