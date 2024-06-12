#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string s,t;
	int maxx,c;
	char max;
	while(getline(cin,s)){
		getline(cin,t);
		max=s.at(0);
		maxx=0;
		for(int i=1;i<s.length();i++)
			if(s.at(i)>max){
				maxx=i;
				max=s.at(i);
			}
		s.insert(maxx+1,t); 
		cout<<s<<endl;	
	}
	return 0;
} 
