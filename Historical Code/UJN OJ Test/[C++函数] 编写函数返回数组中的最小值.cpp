#include<iostream>
using namespace std;
void min(int n,int a[120]){
	int minn=a[1];
	for(int i=2;i<=n;i++)
		if(a[i]<minn)
			minn=a[i];
	cout<<minn<<" ";
}
void min(int n,float a[120]){
	float minn=a[1];
	for(int i=2;i<=n;i++)
		if(a[i]<minn)
			minn=a[i];
	cout<<minn<<endl;
}
int main(){
	int n1,n2;
	int a[120];
	float b[120];
	cin>>n1;
	for(int i=1;i<=n1;i++)
		cin>>a[i];
	cin>>n2;
	for(int i=1;i<=n2;i++)
		cin>>b[i];
	min(n1,a);
	min(n2,b);	
	return 0;
} 
