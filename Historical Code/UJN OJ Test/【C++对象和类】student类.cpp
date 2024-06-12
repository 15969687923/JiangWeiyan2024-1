#include<iostream>
#include<string> 
using namespace std;
class student{
	private:
		string stuNum,stuName;
		int gs,yy,cs,zc; 
	public:
		student(string num,string name);
		student(string num,string name,int gss,int yyy,int css);
		void sumfun();
		void display();
		void inputscore();
}; 
student::student(string num,string name){
	stuNum=num;
	stuName=name;
	gs=0;
	yy=0;
	cs=0;
	zc=0;
}
student::student(string num,string name,int gss,int yyy,int css){
	stuNum=num;
	stuName=name;
	gs=gss;
	yy=yyy;
	cs=css;
	zc=0; 
} 
void student::sumfun(){
	zc=gs+yy+cs;
}
void student::display(){
	cout<<stuNum<<" "<<stuName<<" "<<gs<<" "<<yy<<" "<<cs<<" "<<zc<<endl;
}
void student::inputscore(){
	int a,b,c;
	cin>>a>>b>>c;
	gs=a;
	yy=b;
	cs=c;
}
int main(){
	student st1("111","John"),st2("222","Mike",67,89,92);
	st1.inputscore();
	st1.sumfun();
	st2.sumfun();
	st1.display();
	st2.display();
	return 0;
}

	
