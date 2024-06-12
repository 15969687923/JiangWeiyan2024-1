#include<iostream>
#include<cstring>
using namespace std;
void mm(int n,string & aa){
	
	for(int i=n-1;i>=0;i--)
			cout<<aa.at(i);
		cout<<endl;
}
int main(){
	string a;
	int n;
	while(getline(cin,a)){
		n=a.length();
		mm(n,a);
	}
	return 0;
} 
