#include<iostream>
using namespace std;
template <typename t>
t largest_element(const t a[],int n){
	t m;
	m=a[1];
	for(int i=2;i<=n;i++)
		if(a[i]>m){
			m=a[i];
		}
	return m;
} 
int main(){
	int na,nb,nc;
	int a[1100];
	double b[1100];
	char c[1100];
	cin>>na;
	for(int i=1;i<=na;i++)
		cin>>a[i];
		cin>>nb;
	for(int i=1;i<=nb;i++)
		cin>>b[i];
		cin>>nc;
	for(int i=1;i<=nc;i++)
		cin>>c[i];
	cout<<largest_element(a,na)<<endl;	
	cout<<largest_element(b,nb)<<endl;
	cout<<largest_element(c,nc)<<endl;
	return 0;
}














