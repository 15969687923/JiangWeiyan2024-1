#include<iostream>
using namespace std;
int zuidagongyue(int a,int b){
	int t;
	if (a < b) {
		t = a; a = b; b = t;
	}
	while (a%b != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	return b;
}
class fraction {
public:
	void print();
	fraction operator/(fraction b);
	fraction operator*(fraction b);
	fraction operator-(fraction b);
	fraction operator+(fraction b);
	void common_denominator(fraction& b);
	void reduction();                     //约分
	fraction();                          //分数初始化为0/1。
	fraction(int a);                    //分数初始化为a/1。
	fraction(int a, int b);            //分数初始化为a/b。
private:
	int fz, fm;
};
fraction::fraction() {
	fz = 0; fm = 1;
}
fraction::fraction(int a) {
	fz = a; fm = 1;
}
fraction::fraction(int a,int b) {
	fz = a; fm = b;
}
void fraction::reduction() {
	int t;
	t = zuidagongyue(fz, fm);
	fz = fz / t;
	fm = fm / t;
}
void fraction::common_denominator(fraction& b) {
	int t,tt;
	t = zuidagongyue(b.fm, fm);
	tt =( b.fm*fm )/ t;
	fz = fz * (tt / fm);
	b.fz = b.fz*(tt / b.fm);
	fm = tt; b.fm = tt;
}
fraction fraction::operator*(fraction b) {
	fraction t;
	t.fm = b.fm*fm;
	t.fz = b.fz*fz;
	t.reduction();
	return t;
}
fraction fraction::operator/(fraction b) {
	fraction t;
	t.fz = b.fm*fz;
	t.fm = b.fz*fm;
	t.reduction();
	return t;
}
fraction fraction::operator+(fraction b) {
	fraction t;
	this->common_denominator(b);
	t.fm = this->fm;
	t.fz = fz + b.fz;
	t.reduction();
	b.reduction();
	this->reduction();
	return t;
}
fraction fraction::operator-(fraction b) {
	fraction t;
	this->common_denominator(b);
	t.fm = this->fm;
	t.fz = fz - b.fz;
	t.reduction();
	b.reduction();
	this->reduction();
	return t;
}
void fraction::print() {
	if (fz == 0)
		cout << "0" ;
	else if (fm == 1)
		cout << fz ;
	else {
		cout << fz << "/" << fm;
	}
}
int main(){
	fraction x1, x2(2), x3(1, 5), y1(2, 3), y2(3, 8), z1, z2, z3, z4;

	x1.print();
	cout << endl;
	x2.print();
	cout << endl;
	x3.print();
	cout << endl;
	y2.print();
	cout << endl;

	z1 = x3.operator +(y1);
	z1.print();
	cout << endl;
	z2 = x3.operator -(y1);
	z2.print();
	cout << endl;

	z3 = x3.operator *(y2);
	z3.print();
	cout << endl;
	z4 = x3.operator /(y2);
	z4.print();
	return 0;
}
