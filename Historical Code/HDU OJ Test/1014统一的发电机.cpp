#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std; 
int main(){
	int n,m,i;
	int s[110000]={0};
	while(cin>>n>>m){
		for(i=0;i<m;i++){
			s[i+1]=(s[i]+n)%m;
		}
		sort(s,s+m);
		for(i=0;i<m;i++)
			if(s[i]!=i)
				break;
		printf("%10d%10d",n,m);
		if(i==m)
			cout<<"    Good Choice"<<endl<<endl;
		else
			cout<<"    Bad Choice"<<endl<<endl;
	}
	return 0;
} 
