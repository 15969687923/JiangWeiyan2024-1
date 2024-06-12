#include<iostream>
#include<iomanip>
using namespace std;
int dd(int m,int n){
	int c=1,i;
	if(n>m-n)
		n=m-n;
 	for(i=1;i<=n;i++)
   		c=c*(m+1-i)/i;
   	return c;
}
int main(){
	int n,m,a,b,t;	
	
	while(!cin.eof()){
		a=1;b=1;
		cin>>n>>m;
		t=dd(n,m);
		cout<<t<<endl;											
	}
	return 0;
} 
