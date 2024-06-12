#include<iostream>
#include<iomanip>
using namespace std;
class rectangle{
	public:
		rectangle();
		rectangle(double a,double b);
		void assign(double a,double b);
		double circumference();
		double area();
		void display();
	private:
		double length,width;
};
rectangle::rectangle(){
	length=0;width=0;
}
rectangle::rectangle(double a,double b){
	length=a;width=b;
}
void rectangle::assign(double a,double b){
	if(a>b){
		length=a;width=b;
	}
	else{
		length=b;width=a;
	}
}
double rectangle::circumference(){
	return 2*length+2*width;
}
double rectangle::area(){
	return length*width;
}
void rectangle::display(){
	cout<<fixed<<setprecision(2)<<length<<","<<width<<",";
}
int main(){
	rectangle c1,c2(2.0,1.0),c3;
    double x,y;
    c1.display();
    cout<<fixed<<setprecision(2)<<c1.circumference()<<","<<c1.area()<<endl;
    c2.display();
    cout<<fixed<<setprecision(2)<<c2.circumference()<<","<<c2.area()<<endl;
    cin>>x>>y;
    c3.assign(x,y);
    c3.display();
    cout<<fixed<<setprecision(2)<<c3.circumference()<<","<<c3.area()<<endl;
    return 0;
}
