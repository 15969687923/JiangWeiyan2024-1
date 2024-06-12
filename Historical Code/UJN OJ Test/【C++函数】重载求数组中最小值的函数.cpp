#include<iostream>
using namespace std;
int miniElement(int array[],int n){
	int min;
	min=array[1];
	for(int i=2;i<=n;i++)
		if(array[i]<min)
			min=array[i];
	return min;
}
double miniElement(double array[],int n){
	double min;
	min=array[1];
	for(int i=2;i<=n;i++)
		if(array[i]<min)
			min=array[i];
	return min;
}
int main(){
	int n,m;
	int a[25];
	double b[25]; 
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	cout<<miniElement(a,n)<<endl;
	cout<<miniElement(b,m)<<endl;
	return 0;
}
