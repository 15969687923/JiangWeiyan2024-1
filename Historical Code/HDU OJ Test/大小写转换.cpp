#include<stdio.h>
#include<string.h>
int main(){
	int t,n,x,i,j;
	char a[300],xiao[300],da[300];
	scanf("%d",&t);
	getchar();
	while(t--){
		gets(a);
		j=0;
		for(i=0;a[i]!='\0';i++){
			//if(a[i]>='a' && a[i]<='z')
			//	xiao[j++]=a[i];
			if(a[i]>='A' && a[i]<='Z')
				xiao[j++]=(a[i]+32);
			else
				xiao[j++]=a[i];
		}
		xiao[j]='\0';
		j=0;
		for(i=0;a[i]!='\0';i++){
			if(a[i]>='a' && a[i]<='z')
				da[j++]=(a[i]-32);
			else
				da[j++]=a[i];
		}
		da[j]='\0';
		puts(da);
		puts(xiao);
	}
	return 0;
}
