#include<iostream>
#include<string>
using namespace std;
void cc(string &a,string &b){
		while(a.find(b)!=-1){
			a.erase(a.find(b),b.length());
		}
}
int main(){
	int n;
	string a,b;
	cin>>n;
	while(n--){
		cin>>a>>b;
		cc(a,b);
		cout<<a<<endl;
	}
	return 0;
} 
