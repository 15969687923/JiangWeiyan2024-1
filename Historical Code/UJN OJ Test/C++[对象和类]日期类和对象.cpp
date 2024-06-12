#include<iostream>
using namespace std;
class current_date{
	public:
		current_date(int dayVal, int monthVal,int yearVal);
		void assign_data(int dayVal, int monthVal,int yearVal);
		void display_data();
		void increment_date();
	private:
		int day,month,year;
};	
current_date::current_date(int dayVal, int monthVal,int yearVal){
	day=dayVal;
	month=monthVal;
	year=yearVal;
}
void current_date::assign_data(int dayVal, int monthVal,int yearVal){
	this->day=dayVal;
	month=monthVal;
	year=yearVal;
}
void current_date::display_data(){
	cout<<month<<"/"<<day<<"/"<<year<<endl;
}
void current_date::increment_date(){
	
	if(this->month==2){
		if(year%4==0&&year%100!=0){
			if(day==29){
				month=3;
				day=1;
			}
			else
				day++;
		}
		else{
			if(day==28){
				month=3;
				day=1;
			}
			else
				day++;
		}
			
	}
	if(month==1||month==3||month==5||month==7||month==8||month==10){
		if(day==31){
			month=month+1;
			day=1;
		}
		else
			day++;
	}
	if(month==4||month==6||month==9||month==11){
		if(day==30){
			month=month+1;
			day++;
		}
		else
			day++;
	}
	if(month==12){
		if(day==31){
			year++;
			month=1;
			day=1;
		}
		else
			day++;
	}	
}
int main(){
	int i,day,month,year;
 	current_date mydate(10,1,2013);
 	mydate.display_data();
 	cin>>day>>month>>year;
 	mydate.assign_data(day,month,year);
 	for(i=1;i<=10;i++){
   		mydate.increment_date();
 	}
 	mydate.display_data();

 	return 0;
}
