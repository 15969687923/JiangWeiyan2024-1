#include<stdio.h>
#include<string.h>
int main(){
	int t,n,i;
	char a[200],m[200];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		getchar(); 
		gets(a);
		for(i=2;i<=n;i++){
			gets(m);
			if(strcmp(a,m)<0)
				strcpy(a,m);
		} 
		puts(a);
	} 
	return 0;
}
