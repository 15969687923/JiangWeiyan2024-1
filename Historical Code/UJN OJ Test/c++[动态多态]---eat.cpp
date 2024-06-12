#include<iostream>
#include<string>
using namespace std;
class person{
	public:
		person(string p);
		virtual void eat();
	private:
		string name;
};
person::person(string p){
	name=p;
}
class student:public person{
	public:
		student(string p);
		virtual void eat();
	private:
		string name;
}; 
class teacher:public person{
	public:
		teacher(string p);
		virtual void eat();
	private:
		string name;
};
class boss:public person{
	public:
		boss(string p);
		virtual void eat();
	private:
		string name;
};
student::student(string p):person(p)
{}
teacher::teacher(string p):person(p)
{}
boss::boss(string p):person(p)
{}
void student::eat(){
	cout<<"I am a student, my name is "<<this->name<<". I want to have lunch at mess hall!"<<endl;
}
void teacher::eat(){
	cout<<"I am a teacher, my name is "<<name<<", I want to eat potato in CHUANWEI restaurant!"<<endl;
}
void boss::eat(){
	cout<<"I am a boss, my name is "<<name<<", I want to eat fish in GAODIJIE restaurant!"<<endl;
}
int main(){
	int choice;
	person *p = NULL;
	string nameValue;
	 //cout<<"please input a number(1=student, 2=teacher, 3=boss) .";
	cin>>choice;
	// cout<<"please enter the name.";
	cin>>nameValue;
	if(choice==1)
	  	p=new student(nameValue);
	else if(choice==2)
	   	p=new teacher(nameValue);
	else if(choice==3)
	    p=new boss(nameValue);
	p->eat(); 
	if(p!=NULL) delete p;
	return 0;
}
