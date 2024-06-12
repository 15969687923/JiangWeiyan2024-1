#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int N;
	int n,m,a,b,i,j,k,s=0,nn;
	cin>>N;
	for(i=1;i<=N;i++){
		nn=1;
		while(1){
			cin>>n>>m;
			s=0;
			if(n==0 && m==0)
				break;
			for(j=1;j<n;j++)
				for(k=j+1;k<n;k++){
					if((j*j+k*k+m)%(k*j)==0)
					s++;
				}
			cout<<"Case "<<nn++<<": "<<s<<endl;
		}
		if(i!=N)
			cout<<endl;
	}
	return 0;
}
