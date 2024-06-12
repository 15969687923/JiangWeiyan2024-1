#include<iostream>
using namespace std;
class point{
	private:
		int x,y;
	public:
		point(int xx=0,int yy=0);
		point operator+(point& a);
		point operator-(point& a);
		bool operator==(point& a);
		bool operator!=(point& a);
		int getx();
		int gety();
		void putx(int a);
		void puty(int a);
};
void point::putx(int a){
	x=a;
}
void point::puty(int a){
	y=a;
}
int point::getx(){
	return x;
}
int point::gety(){
	return y;
}
point::point(int xx,int yy){
	x=xx;y=yy;
}
point point::operator+(point& a){
	point b;
	b.x=a.x+this->x;
	b.y=a.y+y;
	return b;
}
point point::operator-(point& a){
	point b;
	b.x=x-a.x;
	b.y=y-a.y;
	return b;
}
bool point::operator==(point& a){
	if(x==a.x&&y==a.y)
		return true;
	else
		return false;
}
bool point::operator!=(point& a){
	if(x==a.x&&y==a.y)
		return false;
	else
		return true;
}
ostream& operator<<(ostream& os,point& a){
	os<<"("<<a.getx()<<","<<a.gety()<<")"<<endl;
	return os;
}
istream& operator>>(istream& is,point& a){
	int b,c;
	is>>b>>c;
	a.putx(b);
	a.puty(c);
	return is;
}
int main()
{
    point  x, y, z1, z2;
    cin>>x>>y;
    z1=x+y;
    z2=x-y;
	cout<<z1<<z2;

    if(x==y)   
		cout<<"x==y"<<endl;
    else   
		cout<<"x!=y"<<endl;

    if(z1!=z2)   
		cout<<"z1!=z2"<<endl;
    else   
		cout<<"z1==z2"<<endl;
 
    return 0;
}
