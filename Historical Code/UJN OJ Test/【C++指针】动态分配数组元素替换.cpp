#include<iostream>
using namespace std;
int main(){
	int *f;
	int i,n;
	cin>>n;
	f=new int[n];
	cout<<"a["<<n<<"]={";
	for(i=1;i<n;i++){
		cin>>*(f+i-1);
		cout<<*(f+i-1)<<",";
	}
	cin>>*(f+i-1);
	cout<<*(f+i-1)<<"}"<<endl;
	for(i=0;i<n;i++){
		if(*(f+i)<0)
			*(f+i)=0;
	}
	cout<<"a["<<n<<"]={";
	for(i=1;i<n;i++){
		cout<<*(f+i-1)<<",";
	}
	cout<<*(f+i-1)<<"}"<<endl;
	return 0;
}
