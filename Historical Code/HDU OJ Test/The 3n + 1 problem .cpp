#include<stdio.h>
int main(){
	long long m,n,small,big,t,i,max,sum;//可直接用int，那么下面的输入输出改为%d即可。
	while(scanf("%lld%lld",&m,&n)!=EOF && m>0 && n>0){
		small=m;
		big=n;
		if(small>big){//将m和n的值保持在m小于n
			t=small;
			small=big;
			big=t;
		}
		max=0;//最大的长度归零
		for(i=small;i<=big;i++){//从m到n一次尝试所有数字
			small=i;sum=1;//sum记录变化长度
			while(small-1){//等于1时就结束
				if(small%2)
					small=3*small+1;
				else
					small=small/2;
				sum++;
			}//循环一次，sum自增1
			if(sum>max)
				max=sum;
		}
		printf("%lld %lld %lld\n",m,n,max);
	}
	return 0;
}
