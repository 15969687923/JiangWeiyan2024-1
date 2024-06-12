#include<iostream>
#include <algorithm>
using namespace std;
class student{
	public:
		student();
		student(string name,int age=0);
		void input(int n);
		void display(int n);
		int age;
	private:
		string name;
		
};
student::student(){
	name;
	age=0;
}
void student::input(int n){
	cin>>name>>age;
}
void student::display(int n){
		cout<<name<<" "<<age<<endl;
}
void sort(student *s,int n){
	student t;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++){
			if(s[i].age>s[j].age){
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
		}
}
int main(){
	int n;
	cin>>n;
	student *s;
	s=new student[n];
	for(int i=0;i<n;i++)
		s[i].input(n);
	sort(s,n);
	for(int i=0;i<n;i++)
		s[i].display(n);
	return 0;
}
