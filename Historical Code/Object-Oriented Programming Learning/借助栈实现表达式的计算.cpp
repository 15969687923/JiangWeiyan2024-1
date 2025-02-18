// 借助栈实现表达式的计算.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

const int maxSize = 50;
//enum bool{ false,true };

template <class T>
class Stack {
public:
	Stack() {};
	virtual void Push(const T&x) = 0;
	virtual void Pop(T&x) = 0;
	virtual bool IsEmpty()const = 0;
	virtual bool IsFull()const = 0;
	virtual int getSize()const = 0;
};

template <class T>
class SeqStack :public Stack<T> {
public:
	SeqStack(int sz = 50);
	~SeqStack() { delete[]elements; }
	void Push(const T&x);
	void Pop(T&x);
	void getPop(T&x);
	void get2(int& left, int& right);
	bool IsEmpty()const { return (top == -1) ? true : false; }
	bool IsFull()const { return(top == maxSize - 1) ? true : false; }
	int getSize()const { return top + 1; }
	void MakeEmpty() { top = -1; }
	int gettop() {
		return top;
	}
	//friend ostream& operator<<(ostream &os, SeqStack<T>& s) {}
private:
	T * elements;
	int top;
	int maxSize;
	//void overflow
};
int atod(string s) {
	int x,y=1,j=1;
	if (s[0] == '-') {
		y = -1;
		j = 2;
		x = (s[1] - 48)*(-1);
	}
	else {
		x = s[0]-48;
		j = 1;
	}
	for (int i = j; i < s.length(); i++) {
		x = x * 10 + s[i]-48;
	}
	return x;
}
template<class T>
SeqStack<T>::SeqStack(int sz) :top(-1), maxSize(sz) {
	elements = new T[maxSize];
	//assert(elements != NULL);
}
template<class T>
void SeqStack<T>::Push(const T&x) {
	elements[++top] = x;
}
template<class T>
void SeqStack<T>::Pop(T&x) {
	x=elements[top--];
}
template<class T>
void SeqStack<T>::getPop(T&x) {
	x = elements[top];
}
template<class T>
void SeqStack<T>::get2(int& left, int& right) {
	string a, b;
	Pop(a);
	Pop(b);
	right = atod(a);
	left = atod(b);
}
void jisuan(SeqStack<string> &s) {
	int left = 0, right = 0, value;
	string a = "0";
	while (cin>>a,a!="#") {
		s.Push(a);
		s.getPop(a);
		
		if (a == "+") {
			s.Pop(a);
			s.get2(left, right);
			value = left + right;
			s.Push(to_string(value));
		}
		if (a == "-") {
			s.Pop(a);
			s.get2(left, right);
			value = left - right;
			s.Push(to_string(value));
		}
		if (a == "*") {
			s.Pop(a);
			s.get2(left, right);
			value = left * right;
			s.Push(to_string(value));
		}
		if (a == "/") {
			s.Pop(a);
			s.get2(left, right);
			value = left / right;
			s.Push(to_string(value));
		}
	}
	s.Pop(a);
	int x;
	x = atod(a);
	printf("%d\n", x);
}
int main()
{
	SeqStack<string> s;
	jisuan(s);
    return 0;
}

