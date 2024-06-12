#include<iostream>
using namespace std;
class point{
	public:
		point();
		point(int xx,int yy);
		void output();
		void input(int xx,int yy);
		point operator+(point a);
		point operator-(point a);
	private:
		int x;
		int y;
}; 
point::point(){
	x=0;
	y=0;
}
void point::input(int xx,int yy){
	x=xx;
	y=yy;
}
void point::output(){
	cout<<"("<<x<<","<<y<<")"<<endl;
}
point point::operator+(point a){
	point t;
	t.x=this->x+a.x;
	t.y=this->y+a.y;
	return t;
}
point point::operator-(point a){
	point t;
	t.x=this->x-a.x;
	t.y=this->y-a.y;
	return t;
}
int main(){
	int x,y;
	point c1,c2,c3,c4;
	cin>>x>>y;
	c1.input(x,y);
	cin>>x>>y;
	c2.input(x,y);
	c3=c1+c2;
	c4=c1-c2;
	c3.output();
	c4.output();
	return 0;
} 
