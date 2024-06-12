#include<iostream>
using namespace std;
int main(){
	int t[1100];
	t[1]=1;t[2]=2;t[3]=3;t[4]=5;
	int n,i;
	while(cin>>n,!cin.eof()){
		for(i=5;i<=n;i++)
			t[i]=t[i-1]+t[i-3];
		cout<<t[n]<<endl;
	}
	return 0;
}
