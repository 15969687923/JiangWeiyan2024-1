#include<iostream>
using namespace std;
int main(){
	int n,m,i,j;
	int *a,*b;
	cin>>n>>m;
	a=new int[n*m];
	b=new int[n*m];
	for(i=1;i<=n*m;i++)
		cin>>a[i];
	for(i=1;i<=n*m;i++){
			cin>>b[i];
			a[i]=a[i]+b[i];
		}
	for(int j=0;j<n;j++){
		for(i=1;i<m;i++)
			cout<<a[i+j*m]<<" ";
		cout<<a[i+j*m]<<endl;
	}
	return 0;
}
