#include<stdio.h>
int zxjs(int a,int b){
	int c;
	while(1){
		c=a-b;
		if(c==b)
			return c;
		else{
			if(c>b)
				a=c;
			else{
				a=b;
				b=c;
			}
		}
	}
}
int main(){
	int n,m,i,j,k,zd,zx,cj;
	int a[100],b[100];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		cj=1;zx=1;
		scanf("%d",&m);
		for(j=1;j<=m;j++){
			scanf("%d",&a[j]);
			//cj=cj*a[j];
		}
		if(a[1]>a[2])
			zd=zxjs(a[1],a[2]);
		else
			zd=zxjs(a[2],a[1]);
		for(j=3;j<=m;j++){
			if(zd>a[j])
				zd=zxjs(zd,a[j]);
			else
				zd=zxjs(a[j],zd);
		}
		for(j=1;j<=m;j++){
			b[j]=a[j]/zd;
			zx=zx*b[j];
		}
		//zx=zx*zd;
		printf("%d %d\n",zx,zd);
	}
	return 0;
} 
