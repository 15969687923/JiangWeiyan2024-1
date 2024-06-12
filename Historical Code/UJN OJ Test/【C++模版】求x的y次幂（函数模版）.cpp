#include<iostream>
using namespace std;
template <typename t>
t power(const t n,int nn){
	t m=1;
	for(int i=1;i<=nn;i++)
		m=m*n;
	return m;
}
int main(){
	int na,nb;
	int a;
	double b;
	cin>>a>>na;
	cin>>b>>nb;
	cout<<power(a,na)<<endl;
	cout<<power(b,nb)<<endl;
	return 0;
}
