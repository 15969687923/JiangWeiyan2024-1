// 在单链表中统计值为x的结点个数.cpp: 定义控制台应用程序的入口点。
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
	LinkNode *first;
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
	int search(int x) {
		int a = 0;
		LinkNode *current = first;
		while (current != NULL) {
			if (current->data == x)
				a++;
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
};

int main()
{
	List b;
	int c=0,j=0,bb,m;
	while (1) {
		cin >> c;
		if (c != -1) {
			b.Insert(j++, c);
		}
		else
			break;
	}
	cin >> bb;
	int sub=b.search(bb);
	for (m = 0; m < j-1; m++) {
		cout << b.gatdata(m) << "-->";
	}
	cout << b.gatdata(m)<<endl;
	cout << sub << endl;
    return 0;
}

