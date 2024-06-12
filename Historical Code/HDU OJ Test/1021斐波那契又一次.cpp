#include<iostream>
#include<iomanip>
using namespace std;
/*int main(){
	long long f[1100],i,n;
	f[0]=7;f[1]=11;
	cin>>n;
	for(i=2;i<=n;i++)
		f[i]=f[i-1]+f[i-2];
	for(i=0;i<=n;i++)
		f[i]=f[i]%3;
	for(i=0;i<=n;i++)
		cout<<f[i]<<endl;
	return 0;
}*/ //ÕÒ¹æÂÉ
int main(){
	int n;
	while(cin>>n,!cin.eof()){
	if(n%4==2)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	}
	return 0;
}
 
