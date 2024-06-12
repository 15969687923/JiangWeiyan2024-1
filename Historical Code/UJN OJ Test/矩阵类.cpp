#include<iostream>
#include<string>
using namespace std;
class matrix{
	public:
		matrix(int m,int n);
		int at(int i);
		int at(int i,int j);
		int sum();
	private:
		int row,col;
};
matrix::matrix(int m,int n){
	row=m;col=n;
}
int matrix::at(int i){
	return i;
}
int matrix::at(int i,int j){
	return (i-1)*col+j;
}
int matrix::sum(){
	int sum=0;
	for(int i=1;i<=row;i++)
		for(int j=1;j<=col;j++)
			sum=sum+(i-1)*col+j;
	return sum;
}
int main(){
	 int rowNum,colNum;
	 cin>>rowNum>>colNum;
	 matrix mat(rowNum,colNum);
	 cout<<mat.at(4)<<' '<<mat.at(3,4)<<' '<<mat.sum();
	 return 0;
}
