#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int i,a[10]={0},b=0,j;
	cin>>a[1]>>a[3]>>a[5];
	for(i=2;i<=6;i=i+2){
		if(a[i-1]<168){
			a[i]=1;
			b++;
		}	
	}
	if(b==0)
		cout<<"NO CRASH"<<endl;
	else{
		cout<<"CRASH ";
		for(i=1;i<b;i++)
			for(j=2;j<=6;j++)
				if(a[j]==1){
					cout<<a[j-1]<<" ";
					a[j]=0;
				}
		for(j=2;j<=6;j++)
				if(a[j]==1){
					cout<<a[j-1]<<endl;
					a[j]=0;
				}
	}
	return 0;	
} 
