// 第3章编程作业4---十进制到八进制的转换.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<assert.h>
#include<iostream>
using namespace std;
const int maxSize = 50;
template <class T>
class Stack {
public:
	//Stack() {};
	virtual void Push(const T& x) = 0;
	virtual bool Pop(T&x) = 0;
	virtual bool getTop(T&x)const = 0;
	virtual bool IsEmpty()const = 0;
	virtual bool IsFull()const = 0;
	virtual int getSize()const = 0;
};

const int stackIncreament = 100;
template<class T>
class SeqStack :public Stack<T> {
public:
	SeqStack(int sz = 50);
	~SeqStack() { delete[] elements; }
	void Push(const T&x);
	bool Pop(T&x);
	bool getTop(T&x)const;
	bool IsEmpty()const {
		return(top == -1) ? true : false;
	}
	bool IsFull()const {
		return(top == maxSize - 1) ? true : false;
	}
	int getSize()const {
		return top + 1;
	}
	void MakeEmpty() {
		top = -1;
	}
	void output();
private:
	T * elements;
	int top;
	int maxSize;
	void overflowProcess();
};
template <class T>
void SeqStack<T> ::overflowProcess() {
	//私有函数:扩充栈的存储空间
	T * newArray = new T[maxSize + stackIncreament];
	if (newArray = NULL) {
		cerr << "存储分配失败!" << endl;
		exit(1);
	}
	for (int i = 0 ; i <= top ; i++)
		newArray[i] = elements[i];
	maxSize = maxSize + stackIncreament;
	delete[]elements;
	elements = newArray;
}


template<class T>
SeqStack<T>::SeqStack(int sz) :top(-1), maxSize(sz) {
	elements = new T[maxSize];
	assert(elements != NULL);
}
template<class T>
void SeqStack<T>::Push(const T&x) {
	if (IsFull() == true)overflowProcess();
	elements[++top] = x;
}
template <class T>
bool SeqStack<T> ::Pop(T& x) {
	// 公共函数 : 若栈不空则函数返回该栈栈顶元素的值, 然后栈顶指针退1
	if (IsEmpty() == true) return false;//判栈空否,若栈空则函数返回
	x = elements[top--];//栈顶指针退1
	return true;//退栈成功
}

template <class T>
bool SeqStack<T> ::getTop(T& x)const {
	//公共函数:若栈不空则函数返回该栈栈顶元素的地址
	if (IsEmpty() == true) return false;// 判栈空否, 若栈空则函数返回
	x = elements[top];//返回栈顶元素的值
	return true;
}
template <class T>
void SeqStack<T>::output() {
	for (int i = top; i >= 0; i--)
		cout << elements[i];
	cout << endl;
}
int main()
{
	int x = 0, a=-1;
	while (cin >> a) {
		if (a >= 0)
			break;
	}
	if (a == 0) {
		cout << 0 << endl;
		return 0;
	}
	SeqStack<int> s;
	int jishu = 7;
	while (a) {
		x = a & jishu;
		s.Push(x);
		a = a >> 3;
	}
	s.output();

    return 0;
}

