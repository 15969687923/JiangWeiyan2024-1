#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std; 
class complex{
	public:
		complex();
		complex(double a,double b);
		void display();
		void input();
		double magnitude();
	private:
		double real,imag; 
};
complex::complex(){
	real=1.0;imag=1.0;
}
complex::complex(double a,double b){
	real=a;imag=b;
}
void complex::display(){
	cout<<fixed<<setprecision(2)<<real<<"+"<<imag<<"i";
}
void complex::input(){
	cin>>real>>imag;
}
double complex::magnitude(){
	double z;
	z=sqrt(real*real+imag*imag);
	return z;
}
int main(){
	complex val1,val2,val3(1.5,2.8);
    val1.input();
    val1.display();
    cout<<"  "<<fixed<<setprecision(2)<<val1.magnitude()<<endl;
    val2.display();
    cout<<"  "<<val2.magnitude()<<endl;
    val3.display();
    cout<<"  "<<val3.magnitude()<<endl;
    return 0;  
}
