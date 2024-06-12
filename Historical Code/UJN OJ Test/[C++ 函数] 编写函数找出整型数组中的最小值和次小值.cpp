#include<iostream>
#include<stdlib.h>
using namespace std;
int comp(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}
void mm(int n,int(&aa)[110]){
	qsort(aa,n,sizeof(aa[0]),comp);
}
int main(){
	int n,a[110];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	mm(n,a);
	cout<<a[0]<<" "<<a[1]<<endl;
	return 0;
}
