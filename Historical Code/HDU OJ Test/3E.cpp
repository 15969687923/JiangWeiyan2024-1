#include<stdio.h>
int main(){
	int n,m,p,i,j,z;
	char a[15][15],b[30]={0},c[15][15];
	scanf("%d%d%d",&n,&m,&p);
	getchar();
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			a[i][j]=getchar();
			b[a[i][j]-'A']++;
		}
		getchar();
	}
	for(i=1;i<=p;i++)
		for(j=1;j<=m;j++){
			c[i][j]=getchar();
			if(c[i][j]=='\n')
				break;
			b[c[i][j]-'A']--;
		}
	for(i=1;i<=26;i++){
		if(b[i]!=0){
			for(j=1;j<=b[i]/2;j++)
				printf("%c",i+'A');
		}
	}
	printf("\n");
	return 0;
}
