#include<iostream>
#include<iomanip>
using namespace std;
class lei{
    public:
        lei();
        lei(double s,double x);
        void display();
        lei operator+(lei b);
        lei operator-(lei b);
    private:
        double shi,xu;
};
lei::lei(){
    shi=1.0;
    xu=1.0;
}
lei::lei(double s,double x){
    shi=s;
    xu=x;
}
void lei::display(){
    if(xu>=0)
        cout<<fixed<<setprecision(2)<<shi<<"+"<<xu<<"i"<<endl;
    else
        cout<<fixed<<setprecision(2)<<shi<<xu<<"i"<<endl;   
}
lei lei::operator+(lei b){
    lei a;
    a.shi=this->shi+b.shi;
    a.xu=this->xu+b.xu;
    return a;
}
lei lei::operator-(lei b){
    lei a;
    a.shi=this->shi-b.shi;
    a.xu=this->xu-b.xu;
    return a;
}
 
int main(){
    lei l3,l4;
    double m,n;
    cin>>m>>n;
    lei l1(m,n);
    cin>>m>>n;
    lei l2(m,n);
    l3=l1+l2;
    l4=l1-l2;
    l3.display();
    l4.display();
    return 0;
}
/**************************************************************
    Problem: 1401
    User: 20171222050
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1472 kb
