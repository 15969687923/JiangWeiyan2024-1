#include<iostream>
#include<string>
using namespace std;
int main(){
	string a;
	while(getline(cin,a)){
		a.at(0)=a.at(0)-32;
		for(int i=3;i<a.length();i++){
			if((a.at(i-2)=='.'||a.at(i-2)=='!'||a.at(i-2)=='?') && a.at(i-1)==' ')
				a.at(i)=a.at(i)-32;
		}
		
		cout<<a<<endl;
	}
	return 0;
} 
