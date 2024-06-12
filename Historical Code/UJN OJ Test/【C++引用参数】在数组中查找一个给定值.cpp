#include<iostream>
using namespace std;
void chazhao(int a[],int n,int b,int& xb){
	for(int i=0;i<n;i++)
		if(a[i]==b){
			xb=i;
			break;
		}
	return ;
}
int main(){
	int n,a[25],b,xb=-1;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>b;
	chazhao(a,n,b,xb);
	cout<<xb<<endl;
	return 0;
}
