#include<stdio.h>
#include<string.h>
int main(){
	int x,i,j,n;
	char a[15],b[200];
	while(gets(b)){
		for(i=0;b[i]!='\0';i++){
			if(b[i]>='0' && b[i]<='9')
				continue;
			else{
				for(j=i;b[j]!='\0';j++)
					b[j]=b[j+1];
				i--;
			}
		}
		x=0;n=1;
		for(i=strlen(b)-1;i>=0;i--){
			x=x+(b[i]-48)*n;
			n=n*10;
		}
		if(x==0){
			printf("0\n");
			continue;
		}			
		i=0;
		while(x>0){
			a[i++]=(x%2+48);
			x=x/2;
		}
		a[i]='\0';
		printf("%s ",b);
		for(i=strlen(a)-1;i>=0;i--)
			printf("%c",a[i]);
		printf("\n");
	}
	return 0;
}
