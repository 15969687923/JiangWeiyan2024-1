#include<stdio.h>
int zxjs(int a,int b)
{
    if(b==0)return a;
    return zxjs(b,a%b);
}    
int main(){
	int n,m,i,j,k;
	int cj,zd,zx;
	int a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		b=1;
		cj=1;zx=1;
		scanf("%d",&m);
		for(j=1;j<=m;j++){
			scanf("%d",&a);
			if(b<a)
				zd=zxjs(a,b);
			else
				zd=zxjs(b,a);
			zx=a/zd*b;
			b=zx;
		}
		printf("%d\n",zx);
	}
	return 0;
} 
