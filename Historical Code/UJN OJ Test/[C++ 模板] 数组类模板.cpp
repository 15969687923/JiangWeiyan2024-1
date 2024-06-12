#include<iostream>
using namespace std;
template<typename T>
class Array{
public:
    Array();
    ~Array();
    void Display();
    void Sort();
private:
    T *data;
    int number_of_element;
};
template<typename T>
Array <T>::Array(){
	cin>>this->number_of_element;
	data=new T[number_of_element];
	for(int i=0;i<number_of_element;i++)
		cin>>data[i];
}
template<typename T>
Array <T>::~Array(){
	delete[] data;
}
template<typename T>
void Array <T>::Display(){
	for(int i=0;i<number_of_element-1;i++)
		cout<<data[i]<<" ";
	cout<<data[number_of_element-1]<<endl;
}
template<typename T>
void Array <T>::Sort(){
	T tt;
	for(int i=0;i<number_of_element;i++)
		for(int j=i+1;j<number_of_element;j++)
			if(data[i]>data[j]){
				tt=data[i];
				data[i]=data[j];
				data[j]=tt;
			}
}

int main(){
    Array<int> int_array;
    Array<double> double_array;
    int_array.Sort();
    int_array.Display();
    double_array.Sort();
    double_array.Display();
    return 0;
}
