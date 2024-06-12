#include<stdio.h>
#include<string.h>
int main(){
	char a[1000][1000];
	long long n,t,i,j,x,sam,y,b,c[1000];
	while(scanf("%s",a[0])!=EOF){
		n=strlen(a[0]);
		sam=0;
		for(i=0;i<n;i++){
			t=a[i][n-1];
			for(j=n-2;j>=0;j--)
				a[i+1][j+1]=a[i][j];
			a[i+1][0]=t;
		}
		for(j=0;j<n;j++){
			x=0;b=1;
			for(i=n-1;i>=0;i--){
				x=x+b*(a[j][i]-48);
				b=b*10;
			}
			c[j]=x;
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				if(c[0]*(i+1)==c[j]){
					sam++;
					break;
				}
		}
		if(sam==n)
			printf("%s is cyclic\n",a);
		else
			printf("%s is not cyclic\n",a);
	}
	return 0;
}
