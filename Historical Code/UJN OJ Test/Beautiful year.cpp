#include<iostream>
using namespace std;
int main(){
	int n,m;
	int a,b,c,d;
	while(cin>>n){
		while(1){
			n++;
			m=n;
			a=m%10;
			m=m/10;
			b=m%10;
			m=m/10;
			c=m%10;
			d=m/10;
			if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
			{
				cout<<n<<endl;
				break;
			}
		}
	}
	return 0;
} 
