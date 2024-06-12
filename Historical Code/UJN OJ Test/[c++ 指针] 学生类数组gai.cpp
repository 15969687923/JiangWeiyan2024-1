#include<iostream>
using namespace std;
class student
{
public:
	student();
	void input();
	void display();
	string na();
	int ag();
private:
	string name;
	int age;
};
student::student()
{
	name="";
	age=0;
}
void student::input()
{
	cin>>name;
	cin>>age;
}
void student::display()
{
	cout<<name;
	cout<<' ';
	cout<<age<<endl;
}
string student::na()
{
	return name;
}
int student::ag()
{
	return age;
}
void sort(student* m,int x)
{
	student t;
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=i+1;j<x;j++)
		{
			if(((m+i)->ag())>((m+j)->ag()))
			{
				t=*(m+i);
				*(m+i)=*(m+j);
				*(m+j)=t;
			}

		}
	}
	
}
int main()
{
	int n,i;
	cin>>n;
	student* p;
	p=new student[n];
	for(i=0;i<n;i++)
		(p+i)->input();
	sort(p,n);
	for(i=0;i<n;i++)
		(p+i)->display();

}
