#include<iostream>
#include<cmath>
using namespace std;
class hexagons{
public:	
	void hexagon(){
		sideValue=10;
	}
 	double circumference();//�ܳ�����
 	double area();//������� 
 	void setSide(double side);//���ñ߳� 
 	double getSide();//���߳�
private:
	double sideValue;//�߳�����ΪĬ��ֵ10
};
double hexagons::circumference(){ 
	return sideValue*6;
}
double hexagons::area(){
	return 1.5*sqrt(3)*sideValue*sideValue;
}
void hexagons::setSide(double side){
	 sideValue=side; 
}
double hexagons::getSide(){
	hexagons::hexagon();
	return sideValue;
}
int main(){
	double side;
 	cin>>side;
 	class hexagons hex1;
 	cout<<"The side of the hxagons is "<<hex1.getSide()<<endl;
 	hex1.setSide(side);
 	cout<<"The circumference of the hex1 is "<<hex1.circumference()<<" and area is "<<hex1.area()<<endl;
    return 0; 
} 
