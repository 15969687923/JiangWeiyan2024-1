#include<iostream>
#include<iomanip>
using namespace std;
class date{
	public:
		date();
		date(int a,int b,int c);
		void assign(int a,int b,int c);
		void display();
		bool Leap_year();
		void increment();
		void increment(int n);
	private:
		int year,month,day;
};
date::date(){
	year=2008;month=1;day=1;
}
date::date(int a,int b,int c){
	year=a;month=b;day=c;
}
void date::assign(int a,int b,int c){
	day=c;month=b;year=a;
}
void date::display(){
	cout<<year<<"-"<<month<<"-"<<day<<endl;
}
bool date::Leap_year(){
	if((year%4==0 && year%100!=0)||(year%400==0))
		return true;
	return false;
}
void date::increment(){
	if(month==12&&day==31){
		year=year+1;
		month=1;
		day=1;
	}
	else if(month==2&&day==28){
		if(Leap_year()){
			day=29;
		}
		else{
			month=3;
			day=1;
		}
	}
	else if((month==2&&day==29)||(month==1&&day==31)||(month==3&&day==31)||(month==5&&day==31)||(month==7&&day==31)||(month==8&&day==31)||(month==10&&day==31)||(month==4&&day==30)||(month==6&&day==30)||(month==9&&day==30)||(month==11&&day==30)){
		month=month+1;
		day=1;	
	}
	else{
		day=day+1;
	}	
}
void date::increment(int n){
	for(int i=1;i<=n;i++)
		increment();
}
int main(){
	date date1,date2(2016,5,1),date3;
	int n,day,month,year;
	date1.display();
	date2.display();
	cin>>year>>month>>day;
	date3.assign(year,month,day);
	date3.display();
	cin>>n;
	date3.increment(n);
	date3.display();
	return 0;
}
