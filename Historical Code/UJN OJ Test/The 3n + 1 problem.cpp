#include<stdio.h>
#include<math.h>
int main(){
	long long a,b,c,d;
	long long max=0,sum,m;
	while(scanf("%lld%lld",&a,&b)!=EOF){
		max=0;
		c=a;d=b;
		if(a>b){
			d=a;c=b;
		}
		for(int i=c;i<=d;i++){
			sum=1;
			m=i;
			while(m>1){
				sum++;
				if(m%2==1)
					m=3*m+1;
				else
					m=m/2;
			}
			if(sum>max)
				max=sum;
		}
		printf("%lld %lld %lld\n",a,b,max);
	}
	return 0;
}
