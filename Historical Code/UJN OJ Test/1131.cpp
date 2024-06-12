#include<iostream>
#include<string>
using namespace std;
int main(){
	int t,m,n;
	string a;
	cin>>t;
	while(t--){
		cin>>m>>n;
		cin.get();
		getline(cin,a);
		cout<<a.substr(m,n-m+1)<<endl;
	}
	return 0;
}
