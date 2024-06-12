#include<iostream>
#include<string>
using namespace std;

const int maxSize = 50;
//enum bool{ false,true };

template <class T>
class Stack {
public:
	Stack() {};
	virtual void Push(const T&x) = 0;
	virtual bool Pop(T&x) = 0;
	virtual bool getTop(T&x) = 0;
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
	bool Pop(T&x);
	bool getTop(T&x);
	void get2(double & left, double & right);
	bool IsEmpty()const { return (top == -1) ? true : false; }
	bool IsFull()const { return(top == maxSize - 1) ? true : false; }
	int getSize()const { return top + 1; }
	void MakeEmpty() { top = -1; }
	//friend ostream& operator<<(ostream &os, SeqStack<T>& s) {}
private:
	T * elements;
	int top;
	int maxSize;
	//void overflow
};
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
bool SeqStack<T>::Pop(T&x) {
	x=elements[top--];
	return true;
}
template<class T>
bool SeqStack<T>::getTop(T&x) {
	x = elements[top];
	return true;
}

int main()
{
	SeqStack<int> s;
	int a,b,c;
	cin>>a>>b;
	while(b!=0){
		c=b%a;
		s.Push(c);
		b=b/a;
	}
	while(s.IsEmpty()==false){
		s.Pop(c);
		cout<<c;
	}
	cout<<endl;
    return 0;
}


