#include<stdio.h> 
#include<string.h>
int main(){
	int n,i,j,sam,max,msam,t,m;
	char a[110][110];
	scanf("%d",&n);
	getchar();
	sam=0;max=0;
	while(n--){
		gets(a[sam++]);
		for(i=0;a[sam][i]!='\0';i++)
			if(a[sam][i]=='.')
				if(i>max){
					max=i;
					msam=sam-1;
				}
	}
	for(i=0;i<n;i++){
		if(i!=msam)
			while(a[i][max]!='.'){
				m=strlen(a[i]);
				for(j=m;j>0;j--)
					a[i][j]=a[i][j-1];
				a[i][0]=' ';
			}		
	}
	for(i=0;i<n;i++){
		puts(a[i]);
	}
	return 0;
}
