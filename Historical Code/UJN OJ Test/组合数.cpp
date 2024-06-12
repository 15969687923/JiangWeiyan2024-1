#include<iostream>
using namespace std;
int main(){
	long long t,a,b,c;
	int m,n;
	cin>>t;
	while(t--){
		cin>>n>>m;
		a=1;b=1;c=1;
		for(int i=m+1;i<=n;i++)
			a=a*i;
		for(int i=1;i<=n-m;i++)
			c=c*i;
		cout<<a/c<<endl;
	}
	return 0;
}
