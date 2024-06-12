#include<iostream>
using namespace std;
template <typename T>
class arra{
public:
	arra(int m);
	~arra();
	int sizeOfArray();
	T operator[](int index);
	void setElement(int a, T b);
private:
	int n;
	T *data;
};
template <typename T>
arra <T>::arra(int m){
	n = m;
	data = new T[n];
}
template <typename T>
T arra<T>::operator[](int index) {
	return data[index];
}
template <typename T>
arra <T>::~arra() {
	delete[] data;
}
template <typename T>
int arra <T>::sizeOfArray(){
	return this->n;
}
template <typename T>
void arra <T>::setElement(int a, T b) {
	data[a] = b;
}
int main() {
	int s,d;
	cin >> s>>d;
	if (s == 1) {
		arra <int> aa(d);
		int bb;
		for (int i = 0; i < d; i++) {
			cin >> bb;
			aa.setElement(i, bb);
		}
		for (int i = 0; i < d - 1; i++) {
			cout << aa[i] << " ";
		}
		cout << aa[d - 1];
	}
	else if (s == 2) {
		arra <double> aa(d);
		double bb;
		for (int i = 0; i < d; i++) {
			cin >> bb;
			aa.setElement(i, bb);
		}
		for (int i = 0; i < d - 1; i++) {
			cout << aa[i] << " ";
		}
		cout << aa[d - 1];
	}
	else if (s == 3) {
		arra <char> aa(d);
		char bb;
		for (int i = 0; i < d; i++) {
			cin >> bb;
			aa.setElement(i, bb);
		}
		for (int i = 0; i < d - 1; i++) {
			cout << aa[i] << " ";
		}
		cout << aa[d - 1];
	}
	return 0;
}

