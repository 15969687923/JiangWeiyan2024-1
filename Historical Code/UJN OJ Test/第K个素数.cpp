#include<iostream>
#include<string.h>
using namespace std;
const int n=110000;
bool f[110005];
int main(){
	memset(f,true,sizeof(f)); 
	f[1]=false;
	for(int i=2;i<n;i++){
		if(f[i]==true){
			for(int j=2;j*i<=n;j++)
				f[i*j]=false;
		}
	}
	int t;
	while(cin>>t){
		int i=2;
		while(t>0){
			if(f[i]==true)
				t--;
			i++;
		}
		cout<<i-1<<endl;
	}
	return 0;
}
