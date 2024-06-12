#include<iostream>
#include<string>
using namespace std;
class student{
	public:
		student();
		student(string n,string na,int s);
		void display();
	private:
		string num,name;
		int score;
}; 
student::student(){
	num="111";
	name="aaa";
	score=01;
}
student::student(string n,string na,int s){
	this->num=n;
	this->name=na;
	this->score=s;
}
void student::display(){
	cout<<num<<" "<<name<<" "<<score<<endl;
}
int main(){
	int t;
	string n,na;
	int s;
	student *a;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>na>>s;
		a=new student(n,na,s);
		a->display();
		delete a;
	}

	return 0;
}
