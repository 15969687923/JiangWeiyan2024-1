#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
#include<stdlib.h>


using namespace std;

template <class T>
struct LinkNode					//链表节点的定义
{
	T data;
	LinkNode<T> *link;           //指针域
	LinkNode(LinkNode<T> *ptr =NULL)//空的构造函数
	{
		link=ptr;
	}
	LinkNode(const T&item,LinkNode<T> *ptr=NULL)//带值的的构造函数
	{
		data=item;
		link=ptr;
	}
};

template<class T>
class LinkedStack
{
public :
	LinkedStack():top(NULL){};
	/*~LinkedtStack()
	{
		makeEmpty();
	}*/
	void push(const T &x);
	bool pop(T &x);
	bool getTop(T &x);
	bool isEmpty()
	{
		return (top==NULL)?true:false;
	};
	int getSize();
	void makeEmpty();
	void output();
private:
	LinkNode<T> *top;
};

template<class T>
void LinkedStack<T>::makeEmpty()
{
	LinkNode<T> *p;
	while(top!=NULL)
	{
		p=top;
		top=top->link;
		delete p;
	}
}

template<class T>
void LinkedStack<T>::push(const T &x)
{
	top=new LinkNode<T>(x,top);
}

template<class T>
bool LinkedStack<T>::pop(T &x)
{
	if(isEmpty()==true)
		return false;
	LinkNode<T> *p=top;
	top=top->link;
	x=p->data;
	delete p;
	return true;
}

template<class T>
bool LinkedStack<T>::getTop(T &x)
{
	if(isEmpty())
		return false;
	x=top->data;
	return true;
}

template<class T>
int LinkedStack<T>::getSize()
{
	LinkNode<T> *p=top;
	int k=0;
	while(p!=NULL)
	{
		p=p->link;;
		k++;
	}
	return k;
}

template<class T>
void LinkedStack<T>::output()
{
	LinkNode<T> *p=top;
	while(p!=NULL)
	{
		cout<<p->data;
		p=p->link;
	}
}


void transform(int n){
	int x = 0;
	LinkedStack<int> s;
	int jiShu = 7;
	while(n){
		x = n & jiShu;
		s.push(x);
		n = n >> 3;
	}
	s.output();
	cout<<endl;
}

template<class T>
void kuohao(LinkedStack<T> L,T *a,int l)
{
	T b,c='c';
	int t=0;
	for(int i=0;i<l;i++)
	{
		if(a[i]=='('||a[i]=='{'||a[i]=='[')
		{
			L.push(a[i]);
		}
		else if(a[i]==')')
		{
			if(L.getTop(c))
				cout<<"";
			else
			{
				break;
			}
			if(c=='(')
				L.pop(b);
			else
			{
				break;
			}
		}
		else if(a[i]=='}')
		{
			if(L.getTop(c))
				cout<<"";
			else
			{
				break;
			}
			if(c=='{')
				L.pop(b);
			else
			{
				break;
			}
		}
		else if(a[i]==']')
		{
			if(L.getTop(c))
				cout<<"";
			else
			{
				break;
			}
			if(c=='[')
				L.pop(b);
			else
			{
				break;
			}
		}
		t++;
	}
	if(t==l&&L.isEmpty())
		cout<<"1"<<endl;
	else
		cout<<"0"<<endl;

}

int str[11]={0,1,2,3,4,5,6,7,8,9};
template<class T>
void jinzhi_convers(int t,int s,LinkedStack<T> &a)
{
	int i=0;
	int ans[10000];
	while(s>0)
	{
		ans[i]=str[s%t];
		a.push(ans[i]);
		s=s/t;
		i++;
	}
	a.output();
	cout<<endl;
}


int isp(char ch)
{
	int a,b;
	if(ch=='#')
		a=0;
	else if(ch=='(')
		a=1;
	else if(ch==')')
		a=6;
	else if(ch=='*'||ch=='%'||ch=='/')
		a=5;
	else if(ch=='+'||ch=='-')
		a=3;
	return a;
}
	
int icp(char ch)
{
	int a,b;
	if(ch=='#')
		a=0;
	else if(ch=='(')
		a=6;
	else if(ch==')')
		a=1;
	else if(ch=='*'||ch=='%'||ch=='/')
		a=4;
	else if(ch=='+'||ch=='-')
		a=2;
	return a;
}

double calculator(string st)
{
	double x, y, result;
	char ch[100];
	LinkedStack<double> a;
	for (int i = 0; i < st.length(); i++)
	{
		if (st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/')
		{
			if (st[i] == '+')
			{
				a.pop(y);
				a.pop(x);
				a.push(x + y);
			}
			if (st[i] == '-')
			{
				a.pop(y);
				a.pop(x);
				a.push(x - y);
			}
			if (st[i] == '*')
			{
				a.pop(y);
				a.pop(x);
				a.push(x * y);
			}
			if (st[i] == '/')
			{
				a.pop(y);
				a.pop(x);
				a.push(x / y);
			}
			if (st[i] == '%')
			{
				a.pop(y);
				a.pop(x);
				a.push((int)x % (int)y);
			}
		}
		else if (st[i] == ' ');
		else
		{
			int j = 0;
			while (st[i] != ' '&&st[i] != '+' && st[i] != '-' && st[i] != '*' && st[i] != '/'&&st[i]!='%')
				ch[j++] = st[i++];
			i--;
			ch[j] = ' ';
			result = atof(ch);
			a.push(result);
		}
	}
	a.pop(result);
	return result;
}



string postfix(string &e){
	LinkedStack<char> s;
	string result = "";
	char ch ='#',ch1,op;
	s.push(ch);
	int i = 0;
	ch = e.at(i++);
	while(s.isEmpty() == false || ch != '#'){
		if(isdigit(ch)||ch=='.')
		{
			result += ch;
			ch = e.at(i++); 
		}
		else{
			s.getTop(ch1);
			if(isp(ch1)<icp(ch))
			{
				if(result.at(result.length()-1)!=' ')
					result += ' ';
				s.push(ch);
				ch = e.at(i++);
			}
			else if(isp(ch1)>icp(ch))
			{
				s.pop(op);
				result += ' ';
				result += op;
			}
			else
			{
				s.pop(op);
				if(op == '(')ch = e.at(i++);
			}
		}
	}
	e.swap(result);
	return e;
}


int main()
{
	string a,b;
	cin>>a;
	b=postfix(a);
	cout<<calculator(b);
	return 0;
}





















