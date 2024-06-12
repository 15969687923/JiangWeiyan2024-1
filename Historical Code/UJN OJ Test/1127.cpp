#include<iostream>
#include<string>
using namespace std;
int main(){
	int t,n,aa;
	string a,b;
	cin>>t;
	while(t--){
		cin>>n;
		cin.get();
		getline(cin,b);
		aa=b.length();
		for(int i=2;i<=n;i++){
			getline(cin,a);
			if(a.length()>aa){
				aa=a.length();
				b=a;
			}
		}
		cout<<b<<endl;
	}
	return 0;
} 
