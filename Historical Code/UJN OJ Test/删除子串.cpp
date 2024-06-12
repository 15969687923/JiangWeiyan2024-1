#include<iostream>
#include<string>
using namespace std;
int main(){
	string a,b;
	int p;
	while(getline(cin,a)){
		getline(cin,b);
		while((p=a.find(b))!=-1){
			a.erase(p,b.length());
		}
		cout<<a<<endl;
	}
	return 0;
}
