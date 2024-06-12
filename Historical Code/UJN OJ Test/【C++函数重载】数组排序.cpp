#include<iostream>
#include<string>
using namespace std;
void px(int n,string(&aa)[100]){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++){
			if(aa[i]>aa[j]){
				aa[80]=aa[i];
				aa[i]=aa[j];
				aa[j]=aa[80];
			}
		}
	for(int i=0;i<n-1;i++)
		cout<<aa[i]<<" ";
	cout<<aa[n-1]<<endl;
}
void px(int n,int(&aa)[100]){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++){
			if(aa[i]>aa[j]){
				aa[80]=aa[i];
				aa[i]=aa[j];
				aa[j]=aa[80];
			}
		}
	for(int i=0;i<n-1;i++)
		cout<<aa[i]<<" ";
	cout<<aa[n-1]<<endl;
}
int main(){
	int n1,n2;
	int a[100];
	string b[100];
	cin>>n1;
	for(int i=0;i<n1;i++){
		cin>>a[i];
	}
	cin>>n2;
	for(int i=0;i<n2;i++){
		cin>>b[i];
	}
	px(n1,a);
	px(n2,b);
	return 0;
}
