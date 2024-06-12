#include<stdio.h>
int main(){  
	int i,m,n,a,b;
	i=1;
	scanf("%d%d",&m,&n);
	if(m>=n){ 
  		while(i<=n){
			if(n%i==0&&m%i==0)
	  			a=i;
	  		i++;
		}
	}
  	else if(m<n){
		while(i<=m){
			if(n%i==0&&m%i==0)
      			a=i;
	  		i++;
	  	}
	}
  	b=(m/a)*(n/a)*a;
  	printf("%d %d",a,b);
  	return 0;
}
