#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string a;
	int i,j;
	while(getline(cin,a)){
		for(i=0,j=a.length()-2;i<=j;){
			//cout<<a.substr(i,2)<<" "<<a.substr(j,2)<<endl;
			if(a.substr(i,2)==a.substr(j,2)){
				i=i+2;j=j-2;
				if(i==j)
					break;
			}
			else
				break;		
		}
		//cout<<a.length()<<endl; 
		if(i==j||i-2==j)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
