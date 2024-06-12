#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class teacher{
	public:
		teacher(string jobnoo,string namee);
		teacher(string jobnoo,string namee,double basepayy,double allowancee,double insurancee);
		void salary();
		void display();
		void input();
	private:
		string jobno,name;
		double basepay,allowance,insurance,zh,sf;
};
teacher::teacher(string jobnoo,string namee):jobno(jobnoo),name(namee){
	basepay=0;
	allowance=0;
	insurance=0;
	zh=0;
	sf=0;
}
teacher::teacher(string jobnoo,string namee,double basepayy,double allowancee,double insurancee)
	:jobno(jobnoo),name(namee),basepay(basepayy),allowance(allowancee),
	insurance(insurancee){
		zh=0;sf=0;
}
void teacher::input(){
	cin>>basepay>>allowance>>insurance;
}
void teacher::display(){
	cout<<fixed<<setprecision(2);
	cout<<jobno<<" "<<name<<" "<<basepay<<" "<<allowance
	<<" "<<insurance<<" "<<zh<<" "<<sf<<endl;
}
void teacher::salary(){
	zh=basepay+allowance;
	sf=zh-insurance;
}
int main(){
	teacher t1("111","Mary"),t2("222","Alex",4256.78,1234.56,895.17);
	t1.input();
	t1.salary();
	t2.salary();
	t1.display();
	t2.display();
	return 0;
}
