#include<iostream>
#include<iomanip>
using namespace std;
class settype {
	public:
		settype();      //构造函数，默认空集，n=0, set=NULL;
		settype( const settype& B);  //拷贝构造函数
		~settype();                                   //析构函数
    
		void getdata(int *a, int& num) const;     //读值函数
		void setdata(int *a, int num);       //设值函数
		int get_n() const; // 获取集合当前元素数目

		settype operator+(const settype& B)const;    //重载运算符+，实现集合并运算
		settype operator*(const settype& B)const;    //重载运算符*，实现集合交运算
		settype operator-(const settype& B)const;    //重载运算符-，实现集合差运算
		settype& operator=(const settype& B);    //重载运算符= 
 
	private:
		int *set;               //数组指针
		int n;                    //元素的个数
};
settype::settype(){
	n=0;
	set=NULL;
}
settype::settype(const settype& B){
	n=B.n;
	set=new int[n];
	for(int i=0;i<n;i++)
		set[i]=B.set[i];
}
settype::~settype(){
	delete[] set;
}
void settype::getdata(int *a,int& num)const{
	num=n;
	for(int i=0;i<n;i++)
		a[i]=this->set[i];
}
void settype::setdata(int *a,int num){
	this->n=num;
	if(n!=0){
		this->set=new int[n];
		for(int i=0;i<n;i++)
			this->set[i]=a[i];
	}
}
int settype::get_n()const{
	return this->n;
}
settype settype::operator+(const settype& B)const{
	settype c;
	int *p=new int[B,n];
	for(int i=0;i<B.n;i++)
		p[i]=-1;
	for(int i=0;i<B.n;i++){
		int flag=1;
		for(int j=0;j<n;j++){
			if(B.set[i]==set[j]){
				flag=0;
				break;
			}
		}
		if(flag!=0)
			p[i]=i;
	}
	int num=0;
	for(int i=0;i<B.n;i++)
		if(p[i]!=-1)num++;
	num=n+num;
	int *temp=new int[num];
	for(int i=0;i<n;i++)
		temp[i]=set[i];
	for(int i=n,j=0;i<num;i++,j++)
	{
		while(j<B.n && p[j]==-1)
			j++;
		if(j>=B.n)
			break;
		temp[i]=B.set[p[j]];
	}
	c.setdata(temp,num);
	delete []p;
	delete []temp;
	return c;
}
settype settype::operator*(const settype& B)const{
	settype c;
		int *p=new int[B.n];
	for(int i=0;i<B.n;i++)
		p[i]=-1;
	for(int i=0;i<B.n;i++){
		int flag=1;
		for(int j=0;j<n;j++)
			if(B.set[i]==set[j]){
				flag=0;
				break;
			}
		if(flag==0)
			p[i]=i;
	}
	int num=0;
	for(int i=0;i<B.n;i++){
		if(p[i]!=-1)num++;
	}
	int *temp=new int[num];
	for(int i=0,j=0;i<B.n;i++,j++){
		while(j<B.n&&p[j]==-1)
			j++;
		if(j>=B.n)
			break;
		temp[i]=B.set[p[j]];
	}
	c.setdata(temp,num);
	delete[]temp;
	delete[]p;
	return c;
}
settype settype::operator-(const settype& B)const{
	settype c;
		int *p=new int[B.n];
	for(int i=0;i<B.n;i++)
		p[i]=-1;
	for(int i=0;i<B.n;i++){
		int flag=1;
		for(int j=0;j<n;j++)
			if(B.set[i]==set[j]){
				flag=0;
				break;
			}
		if(flag==0)
			p[i]=i;
	}
	int num=0;
	for(int i=0;i<B.n;i++)
		if(p[i]!=-1)num++;
	for(int i=0;i<B.n;i++){
		if(p[i]!=-1){
			for(int j=0;j<n;j++){
				if(B.set[p[i]]==set[j]){
					p[i]=j;
					break;
				}
			}
		}
	}
	num=n-num;
	int *temp=new int[num];
	for(int i=0,k=0;i<n;i++){
		int flag=0;
		for(int j=0;j<B.n;j++)
			if(p[j]==i){
				flag=1;
				break;
			}
		if(flag==0)temp[k++]=set[i];
	}
	c.setdata(temp,num);
	delete []p;
	delete []temp;
	return c;
}
settype& settype::operator=(const settype& B){
	if(this!=&B){ 
		n=B.n;
		delete[]set;
		this->set=new int[n];
		for(int i=0;i<n;i++)
			set[i]=B.set[i];
	}
	return *this;
}
ostream& operator<<(ostream& os,const settype& t){
	int m;
	m=t.get_n();
	if(m!=0){
		int *mm=new int[m];
		t.getdata(mm,m);
		os<<"{";
		for(int i=0;i<m-1;i++)
			os<<mm[i]<<",";
		os<<mm[m-1]<<"}"<<endl;
	}
	else
		os<<"{}"<<endl;
	return os;
}
istream& operator>>(istream& is,settype& t){
	int m;
	cin>>m;
	int *mm=new int[m];
	for(int i=0;i<m;i++)
		is>>mm[i];
	t.setdata(mm,m);
	return is;
}
int main(int argc, char* argv[]){
	settype A, B, C;    
	cin>>A>>B;
	cout<<"A="<<A;
	cout<<"B="<<B;
	C=A+B;
	cout<<"A+B="<<C;
	C=A*B;
	cout<<"A*B="<<C;
	C=A-B;
	cout<<"A-B="<<C;
	return 0;
}

