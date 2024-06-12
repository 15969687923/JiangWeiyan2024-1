#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int gcd(int x,int y){
	if(y==0)
		return x;
	else
		return gcd(y,x%y);
}
int main(){
	int n,nn,k;
	long long lcm,s;
	cin>>n;
	while(n--){
		cin>>nn;
		lcm=1;
		for(k=0;k<nn;k++){
			cin>>s;
			lcm=(lcm*s)/gcd(lcm,s);
		}
		cout<<lcm<<endl;
	}
	return 0;
}
