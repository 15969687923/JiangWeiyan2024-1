#include<stdio.h>
int main(){
	long long m,n,small,big,t,i,max,sum;//��ֱ����int����ô��������������Ϊ%d���ɡ�
	while(scanf("%lld%lld",&m,&n)!=EOF && m>0 && n>0){
		small=m;
		big=n;
		if(small>big){//��m��n��ֵ������mС��n
			t=small;
			small=big;
			big=t;
		}
		max=0;//���ĳ��ȹ���
		for(i=small;i<=big;i++){//��m��nһ�γ�����������
			small=i;sum=1;//sum��¼�仯����
			while(small-1){//����1ʱ�ͽ���
				if(small%2)
					small=3*small+1;
				else
					small=small/2;
				sum++;
			}//ѭ��һ�Σ�sum����1
			if(sum>max)
				max=sum;
		}
		printf("%lld %lld %lld\n",m,n,max);
	}
	return 0;
}
