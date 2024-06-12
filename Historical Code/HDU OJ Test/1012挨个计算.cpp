#include<stdio.h>
int jiec(int i){
	int jc=1;
	for(int j=1;j<=i;j++){
		jc=jc*j;
	}
	return jc;
}
int main(){
	double e[15];
	int n,i,jc;
	e[0]=1;
	for(i=1;i<=9;i++){
		jc=jiec(i);
		e[i]=e[i-1]+1.0/jc;
	}
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n1 2\n2 2.5\n");
	for(i=3;i<=9;i++){
		printf("%d %.9lf\n",i,e[i]);
	}
	return 0;
} 
