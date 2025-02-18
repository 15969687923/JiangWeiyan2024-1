// 顺序表删除给定元素
//

#include "stdafx.h"




#include<stdlib.h>
#include<iostream>
using namespace std;
const int defaultSize = 10;
template<class T>
class SepList {
protected:
	T * data;
	int maxSize;
	int last;
	//void reSize(int newSize);
public:
	SepList(int sz = defaultSize);
	SepList(SepList<T> & L);
	~SepList() {
		delete[] data;
	}
	int Size()const {
		return last;
	}
	int Length()const {
		return last;
	}
	int Search(T& x)const;
	int Locate(int i)const;
	int getData(int i)const {
		return data[i];
	}
	void setData(int i, T& x) {
		if (i > 0 && i <= last + 1)
			data[i - 1] = x;
	}
	bool Insert(int i, T& x);
	bool Remove(int i);
	bool IsEmpty() {
		return(last == -1) ? true : false;
	}
	bool IsFull() {
		return(last == maxSize - 1) ? true : false;
	}
	void input();
	void output();
	//SepList<T>operator=(SepList<T>&L);
};
template <class T>
SepList<T>::SepList(int sz) {
	if (sz > 0) {
		maxSize = sz;
		last = -1;
		data = new T[maxSize];
		if (data == NULL) {
			cerr << "存储分配错误!" << endl;
			exit(1);
		}
	}
}
template<class T>
SepList<T>::SepList(SepList<T>& L) {
	maxSize = L.Size();
	last = L.Length() - 1;
	T value;
	data = new T[maxSize];
	if (data == NULL) {
		cerr << "存储分配错误！" << endl;
		exit(1);
	}
	for (int i = 1; i <= last + 1; i++) {
		L.getData(i, value);
		data[i - 1] = value;
	}
}
//template<class T>
//void SepList<T>::reSize(int Size) {
//	if (newSize <= 0) {
//		cerr << "无效的数组大小" << endl;
//		return;
//	}
//	if (newSize != maxSize) {
//		T*newarray = new T[newSize];
//		if (newarrsy == NULL) {
//			cerr << "存储分配错误" << endl;
//			exit(1);
//		}
//		int n = last + 1;
//		T*srcptr = data;
//		T*destptr = newarray;
//		while (n--)*destptr++ = *srcprt++;
//		delete[] data;
//		data = newarray;
//		maxSize = newSize;
//	}
//}
template<class T>
int SepList<T>::Search(T&x)const {
	for (int i = 0; i <= last; i++)
		if (data[i] == x)
			return i + 1;
	return 0;
}
template<class T>
int SepList<T>::Locate(int i) const {
	if (i >= 1 && i <= last + 1)return i;
	else return 0;
}
template<class T>
bool SepList<T>::Insert(int i, T&x) {
	if (last == maxSize - 1)
		return false;
	if (i<0 || i>last + 1)
		return false;
	for (int j = last; j >= i; j--)
		data[j + 1] == data[j];
	data[i] = x;
	last++;
	return true;
}
template<class T>
bool SepList<T>::Remove(int i) {//删除
	/*if (last == -1)
		return false;
	if (i<1 || i>last + 1)
		return false;*/
	//x = data[i - 1];
	for (int j = i; j <last; j++)
		data[j] = data[j+1];
	last--;
	return true;
}
template<class T>
void SepList<T>::input() {
	cin >> last;
	for (int i = 0; i < last; i++) {
		cin >> data[i];

	}
}
template<class T>
void SepList<T>::output() {
	cout << "{ ";
	for (int i = 0; i < this->Length(); i++)
		cout << data[i] << " ";
	cout << "}";
}
#include<iostream>
int main() {
	SepList<int>a1;
	a1.input();
	int ll = a1.Length();
	int x;
	cin >> x;
	for (int i = 0; i < ll; i++) {
		if (a1.getData(i) == x) {
			a1.Remove(i);
			i--;
		}
	}
	a1.output();
	
	return 0;
}




