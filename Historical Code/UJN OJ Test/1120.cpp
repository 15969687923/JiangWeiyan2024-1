#include<stdio.h>//³¬Ê±£¿£¿ 
int main(){
	int t,n,i,sum,x;
	int a[110]={0};
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		i=1;
		sum=0;
		while(n--)
			scanf("%d",&a[i++]);
		scanf("%d",&x);
		i=i-1;
		n=(i+1)/2;
		while(sum<i){
			if(a[n]<x){
				n=(n+i)/2.0+0.5;
				sum++;
			}
			else if(a[n]>x){
				n=(n+1)/2.0+0.5;
				sum++;
			}	
			else if(a[n]==x){
				sum++;
				break;
			}
			if(a[n]==a[1]||a[n]==a[i]){
				sum++;
				break;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
