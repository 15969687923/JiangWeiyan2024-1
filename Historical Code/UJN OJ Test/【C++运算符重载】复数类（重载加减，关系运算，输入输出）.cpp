#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class complex{
public:
	void setreal(double realval);
	void setimag(double imagval);
	void getreal(double& aa);
	void getimag(double& aa);
	complex operator+(const complex &aa);
	complex operator-(const complex &aa);
	bool operator==(const complex &aa);
	bool operator!=(const complex &aa);
	bool operator<(const complex &aa);
	bool operator>(const complex &aa);
private:
   	double real ;             
   	double imaginary ;
};
void complex::setreal(double realval){
	real=realval;
}
void complex::setimag(double imagval){
	imaginary=imagval;
}
void complex::getimag(double& aa){
	aa=imaginary;
}
void complex::getreal(double& aa){
	aa=real;
}
complex complex::operator+(const complex &aa){
	complex t;
	t.real=this->real+aa.real;
	t.imaginary=this->imaginary+aa.imaginary;
	return t;
}
complex complex::operator-(const complex &aa){
	complex t;
	t.real=this->real-aa.real;
	t.imaginary=this->imaginary-aa.imaginary;
	return t;
}
bool complex::operator==(const complex &aa){
	double da,db;
	if(this->imaginary==0)
		da=this->real;
	else
		da=sqrt(this->real*this->real+this->imaginary*this->imaginary);
	if(aa.imaginary==0)
		db=aa.real;
	else
		db=sqrt(aa.real*aa.real+aa.imaginary*aa.imaginary);
	if(da==db)
		return true;
	else
		return false;	
}
bool complex::operator!=(const complex &aa){
	if(*this==aa)
		return false;
	else
		return true;
}
bool complex::operator<(const complex &aa){
	double da,db;
	if(this->imaginary==0)
		da=this->real;
	else
		da=sqrt(this->real*this->real+this->imaginary*this->imaginary);
	if(aa.imaginary==0)
		db=aa.real;
	else
		db=sqrt(aa.real*aa.real+aa.imaginary*aa.imaginary);
	if(da<db)
		return true;
	else
		return false;	
}
bool complex::operator>(const complex &aa){
	double da,db;
	if(this->imaginary==0)
		da=this->real;
	else
		da=sqrt(this->real*this->real+this->imaginary*this->imaginary);
	if(aa.imaginary==0)
		db=aa.real;
	else
		db=sqrt(aa.real*aa.real+aa.imaginary*aa.imaginary);
	if(da>db)
		return true;
	else
		return false;	
}
ostream& operator<<(ostream& os,complex &aa){
	double a,b;
	aa.getreal(a);
	aa.getimag(b);
	if(b>0)
		os<<fixed<<setprecision(2)
		  <<a<<"+"<<b<<"i"<<endl;
	else if(b==0)
		os<<fixed<<setprecision(2)
		  <<a<<endl;
	else if(b<0)
		os<<fixed<<setprecision(2)
		  <<a<<b<<"i"<<endl;
	return os;
}
istream& operator>>(istream& is,complex& aa){
	double a,b;
	is>>a;
	is>>b;
	aa.setreal(a);
	aa.setimag(b);
	is.ignore(1);
	return is;
}
int main(){
	complex c1, c2, c3, c4, c5 ;
	cin >> c1 >> c2 ;
	c3 = c1 + c2 ;
	c4 = c1 - c2 ;
	if ( c3 != c4 ){
		if (c3 < c4){
			cout << "c3 is less than c4" ;
			c5 = c4 - c3 ;
		}
		if ( c3 > c4 ){
			cout << "c3 is greater than c4" ;
			c5 = c3 - c4 ;
		}
	}
	if ( c3 == c4 ){
		cout << "c3 and c4 are equal";
		c5 = c4 ;
	}
	cout<<endl;
	cout << c5 ;
	return 0;
}
