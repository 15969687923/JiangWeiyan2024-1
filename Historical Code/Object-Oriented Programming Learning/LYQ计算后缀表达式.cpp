#include "iomanip"
#include "stdlib.h"
#include "cstring"
#include "string"
#include "stdio.h"
#include "iostream"
#include "stdlib.h"
#include "math.h"
const int increase = 50;
using namespace std;
template <class T>
class SeqStack
{
private:
	T * elements;
	int top;
	int maxSize;

public:
	SeqStack(int sz = 50);
	~SeqStack()
	{
		delete[]elements;
	}
	void push(T &x);
	bool pop(T &x);
	bool getTop(T& x);
	bool IsEmpty();
	bool IsFull();
	int getSize();
	void MakeEmpty();
	void output();
	void reSize();
};
template <class T>
SeqStack<T>::SeqStack(int sz)
{
	maxSize = sz;
	top = -1;
	elements = new T[maxSize];
	if (elements == NULL)
	{
		cerr << "存储分配错误！" << endl;
		exit(0);
	}

}
template <class T>
void SeqStack<T>::push(T& x)
{
	if (top == maxSize - 1)
		reSize();
	top++;
	elements[top] = x;
}
template <class T>
bool SeqStack<T>::pop(T &x)
{
	if (top == -1)
		return false;
	x = elements[top];
	top--;
	return true;
}
template <class T>
bool SeqStack<T>::getTop(T& x)
{
	if (IsEmpty() == true)
		return false;
	x = elements[top];
	return true;
}
template <class T>
int SeqStack<T>::getSize()
{
	return maxSize;
}
template <class T>
bool SeqStack<T>::IsEmpty()
{

	return top == -1 ? true : false;
}
template <class T>
bool SeqStack<T>::IsFull()
{
	if (top == maxSize - 1)
		return true;
	else
		return false;
}
template <class T>
void SeqStack<T>::MakeEmpty()
{
	top = -1;
}
template <class T>
void SeqStack<T>::reSize()
{
	T* newarray = new T[maxSize + increase];
	if (newarray == NULL)
	{
		cout << "存储分配错误！" << endl;
		exit(0);
	}
	for (int i = 0; i <= top; i++)
		newarray[i] = elements[i];
	delete[] elements;
	elements = newarray;
	maxSize = maxSize + increase;
}
template <class T>
void SeqStack<T>::output()
{
	if (IsEmpty())
	{
		cout << "空栈" << endl;
	}
	else
	{
		for (int i = top; i >= 0; i--)
			cout << elements[i];
		cout << endl;
	}
}
/*
int isp(char ch)
{
int n=-1;
switch(ch)
{
case '#':n=0;break;
case '(':n=1;break;
case '*':
case '/':
case '%':n=5;break;
case '+':
case '-':n=3;break;
case ')':n=6;break;
}
return n;
}
int icp(char ch)
{
int n=-1;
switch(ch)
{
case '#':n=0;break;
case '(':n=6;break;
case '*':
case '/':
case '%':n=4;break;
case '+':
case '-':n=2;break;
case ')':n=1;break;
}
return n;
}
*/


/*string& zhongtohou(string zh)
{

SeqStack<char> zhong;

char ch_z='#',ch1,op;
string late="";
zhong.push(ch_z);
int i=0;
ch_z=zh.at(i++);

while(zhong.IsEmpty()==false||ch_z!='#')
{
if(isdigit(ch_z)||ch_z=='.')
{
late+=ch_z;
ch_z=zh.at(i++);
}
else
{

zhong.getTop(ch1);
if(isp(ch1)<icp(ch_z))
{
if(late.at(late.length()-1)!=' ')
{
late+=' ';
}
zhong.push(ch_z);
ch_z=zh.at(i++);
}
else if(isp(ch1)>icp(ch_z))
{
zhong.pop(op);
late+=' ';
late+=op;
}
else
{
zhong.pop(op);
if(op=='(')
ch_z=zh.at(i++);
}
}
}
zh=late+'#';
return zh;
}


*/
class calculate
{
public:
	calculate(int crease) :s(crease) {};
	void run(string e);
	void clear();
	void addop(double value);           //加的是字符串中的这个字符，要转化为数字
	bool get2op(double& left, double& right);
	void doop(char op);
	double value();
private:
	SeqStack<double> s;    //cun操作结果

};
bool calculate::get2op(double& left, double& right)
{
	if (s.IsEmpty() == true)
	{
		cout << "缺少右操作数！" << endl;
		return false;
	}
	s.pop(right);
	if (s.IsEmpty() == true)
	{
		cout << "缺少左操作数！" << endl;
		return false;
	}
	s.pop(left);
	return true;
}
void calculate::addop(double value)            //进操作数
{
	s.push(value);
}
void calculate::doop(char op)
{
	double left, right, value;
	bool result;
	result = get2op(left, right);
	if (result == true)
	{
		switch (op)
		{
		case '+':value = left + right; s.push(value); break;
		case '-':value = left - right; s.push(value); break;
		case '*':value = left * right; s.push(value); break;
		case '/':if (fabs(right)<0.00001)
		{
			cerr << "除0！" << endl;
			clear();
		}
				 else
				 {
					 value = left / right;
					 s.push(value);
				 }
				 break;
		}
	}
	else
	{
		clear();
	}
}
void calculate::clear()
{
	s.MakeEmpty();
}
void calculate::run(string e)
{
	char ch;
	int i = 0;
	string doub = "";
	double n = 0;
	while ((ch = e.at(i)) != '#')
	{
		if (isdigit(ch) || ch == '.')
		{
			doub += ch;
			i++;
		}
		else if (ch == ' ')
		{
			if (doub == "")
			{
				i++;
				continue;
			}
			n = atof(doub.c_str());
			s.push(n);
			doub = "";
			i++;
		}
		else
		{
			switch (ch)
			{
			case '+':
			case '-':
			case '*':
			case '/': {doop(ch); i++; }; break;
			}
		}
	}
}
double calculate::value()
{
	double v;
	s.pop(v);
	return v;
}
int main()
{

	string zh;

	getline(cin, zh, '#');
	zh = zh + '#';
	calculate c(50);
	c.run(zh);
	cout << fixed << setprecision(0) << c.value() << endl;
}
