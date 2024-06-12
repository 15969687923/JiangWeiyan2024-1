#include<stdio.h>
#include<string.h>
int main(){
	int x,i,j,n,r;
	char a[35];
	while(scanf("%d%d",&x,&r)!=EOF){
		if(x==0){
			printf("0\n");
			continue;
		}			
		i=0;
		while(x>0){
			a[i]=x%r;
			if(a[i]<=9)
				a[i]=a[i]+'0';
			else
				a[i]=a[i]+55;
			x=x/r;
			i++;
		}
		a[i]='\0';
		for(i=strlen(a)-1;i>=0;i--)
			printf("%c",a[i]);
		printf("\n");
	}
	return 0;
}
