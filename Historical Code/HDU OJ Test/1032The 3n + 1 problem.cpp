#include<iostream>//�����ʱ��һ����С����ǰ�����������ʱ��Ҫ�������˳��һ�� 
using namespace std;
int main(){
	int n,m,i,j,sum=0,ii,sam,a,b;
	while(cin>>n>>m,!cin.eof()){
		sum=0;
		a=n;b=m;
		if(n>m){
			a=m;b=n;
		} 
		for(i=a;i<=b;i++){
			sam=0;
			ii=i;
			while(ii>1){
				sam++;
				if(ii%2==1)
					ii=3*ii+1;
				else
					ii=ii/2;
			}
			sam++;
			if(sam>sum)
				sum=sam;		
		}
		cout<<n<<" "<<m<<" "<<sum<<endl;
	}
	return 0;
}
