#include<iostream>
using namespace std;
int main(){
	char x;
	int a,b;
	cin>>a>>b>>x;
	if(x=='+')
		a=a+b;
	else if(x=='-')
		a=a-b;
	else if(x=='*')
		a=a*b;
	else if(x=='/')
		a=a/b;
	cout<<a<<endl;
	return 0;
}
