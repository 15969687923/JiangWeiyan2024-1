#include<stdio.h>
int main(){
	int a,b,j=0,o=0;
	while(scanf("%d%d",&a,&b)!=EOF){
		j=0;o=0;
		for(int i=a;i<=b;i++){
			if(i%2==0)
				o=o+i*i;
			else
				j=j+i*i*i;
		}
		printf("%d %d\n",o,j);
	}
	return 0;
	
}
