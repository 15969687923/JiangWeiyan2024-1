#include<iostream>
#include<string>
using namespace std;
int main(){
	string a,b,c,t;
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	if(b<a){
		t=a;a=b;b=t;
	}
	if(c<a){
		t=a;a=c;c=t;
	}
	if(c<b){
		t=b;b=c;c=t;
	}
	if(b<a){
		t=a;a=b;b=t;
	}
	cout<<a<<endl<<b<<endl<<c<<endl;
	return 0;		
}
