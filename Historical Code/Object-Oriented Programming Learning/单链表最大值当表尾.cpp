// 单链表最大值当表尾.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
struct LinkNode {
	int data;
	LinkNode *link;
	LinkNode() {
		link = NULL;
	}
	LinkNode(int x) {
		data = x;
	}
};
class List {
private:
	LinkNode * first;
public:
	List() {
		first = new LinkNode;
	}
	bool Insert(int i, int &x) {
		if (first == NULL || i == 0) {
			LinkNode *newNode = new LinkNode(x);
			newNode->link = first;
			first = newNode;
		}
		else {
			LinkNode  *current = first;
			for (int k = 1; k < i; k++) {
				if (current == NULL)
					break;
				else current = current->link;
			}
			//if(current==NULL)
			LinkNode *newNode = new LinkNode(x);
			newNode->link = current->link;
			current->link = newNode;
		}
		return true;
	}
	int search(int x) {//得到最大数位置
		int a = 0;
		LinkNode *current = first;
		while (current != NULL) {
			if (current->data != x) {
				a++;
				current = current->link;
			}
			else if(current->data==x){
				break;
			}
		}
		return a;
	}
	int searchmax() {//得到最大数
		int a = 0;
		LinkNode *current = first;
		while (current != NULL) {
			if (current->data > a)
				a = current->data;
			current = current->link;
		}
		return a;
	}
	int gatdata(int i) {
		LinkNode *current = first;
		int k = 0;
		while (current != NULL && k < i) {
			current = current->link;
			k++;
		}
		return current->data;
	}
	void setdata(int i,int x) {
		LinkNode *current = first;
		int k = 0;
		while (current != NULL && k < i) {
			current = current->link;
			k++;
		}
		current->data = x;
	}
//	int getdata1(int i) {
	//	LinkNode *current = first;
	//	int k = 0;
	//	while (current != NULL&&k<i) {
	//		current = current->link;
	//		k++;
	//	}
	//	return current->data;
	//}
	void del(int i) {
		LinkNode *current = first;
		LinkNode *current1=first;
		int k = 0;
		while (current != NULL && k < i) {
			current = current->link;
			k++;
		}
		k = 0;
		while (current1 != NULL && k < i-1) {
			current1 = current1->link;
			k++;
		}
		if (current == first) {
			LinkNode *del = current->link;
			first = del;
		}
		else {
			LinkNode *del = current->link;
			current1->link = del;
		}
		
		//delete del;
		//delete current;
	}
};

int main()
{
	List b;
	int c = 0, j = 0, bb, m;
	while (1) {
		cin >> c;
		if (c != -1) {
			b.Insert(j++, c);
		}
		else
			break;
	}
	for (m = 0; m < j - 1; m++) {
		cout << b.gatdata(m) << "-->";
	}
	cout << b.gatdata(m) << endl;

	int max=b.searchmax();//shuzhi
	int maxx = b.search(max);//weizhi
	b.del(maxx);
	b.Insert(j-1, max);
	for (m = 0; m < j - 1; m++) {
		cout << b.gatdata(m) << "-->";
	}
	cout << b.gatdata(m) << endl;
	return 0;
}

