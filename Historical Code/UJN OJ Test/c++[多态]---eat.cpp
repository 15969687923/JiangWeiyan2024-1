#include<iostream>
#include<string>
using namespace std;
class student{
	public:
		student(string p);
		void eat();
	private:
		string name;
}; 
class teacher{
	public:
		teacher(string p);
		void eat();
	private:
		string name;
};
class boss{
	public:
		boss(string p);
		void eat();
	private:
		string name;
};
student::student(string p){
	name=p;
}
teacher::teacher(string p){
	name=p;
}
boss::boss(string p){
	name=p;
}
void student::eat(){
	cout<<"I am a student, my name is "<<this->name<<". I want to have lunch at mess hall!"<<endl;
}
void teacher::eat(){
	cout<<"I am a teacher, my name is "<<name<<", I want to eat potato in CHUANWEI restaurant!"<<endl;
}
void boss::eat(){
	cout<<"I am a boss, my name is "<<name<<", I want to eat fish in GAODIJIE restaurant!"<<endl;
}
int main()
{
 student s("xiao li");
 teacher t("zhang");
 boss b("wang");
 s.eat();
 t.eat();
 b.eat();  
 return 0;
}

/*
I am a student, my name is xiao li. I want to have lunch at mess hall!
I am a teacher, my name is zhang, I want to eat potato in CHUANWEI restaurant!
I am a boss, my name is wang, I want to eat fish in GAODIJIE restaurant!

I am a student, my name is xiao li. I want to have lunch at mess hall!
I am a teacher, my name is zhang, I want to eat potato in CHUANWEI restaurant!
I am a boss, my name is wang, I want to eat fish in GAODIJIE restaurant!
*/
