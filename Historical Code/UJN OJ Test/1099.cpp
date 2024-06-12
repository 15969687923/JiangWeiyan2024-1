#include<iostream>
using namespace std;
int main(){
	int a[45];
	a[1]=1;a[2]=1;
	for(int i=3;i<=41;i++){
		a[i]=a[i-1]+a[i-2];
	}
	int t,x;
	cin>>t;
	while(t--){
		cin>>x;
		cout<<a[x]<<endl;
	}
	return 0;
} 
