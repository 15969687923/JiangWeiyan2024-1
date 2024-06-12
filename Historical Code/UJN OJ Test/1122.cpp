#include<iostream>
using namespace std;
int main(){
	int t,n,sum,b,k,i,j;
	int a[110];
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++){
			k=i;
			for(j=i+1;j<n;j++)
				if(a[k]>a[j])
					k=j;
				if(k!=i){
					b=a[i];
					a[i]=a[k];
					a[k]=b;
					sum++;
				}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
