#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	int p=0,i;
	while(getline(cin,str)){
		while(p<str.length() && p!=-1){
			p=str.find(" ");
			str.erase(p,1);
		}
		for(i=0;i<=str.length()/2;i++)
			if(str.at(i)!=str.at(str.length()-i))
				break;
		if(i>str.length()/2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
