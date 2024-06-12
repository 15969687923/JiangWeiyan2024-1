#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
struct BinTreeNode {
	T data;
	BinTreeNode<T> *leftChild, *rightChild;
	BinTreeNode() :leftChild(NULL), rightChild(NULL) {}
	BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL)
		:data(x), leftChild(l), rightChild(r) {}
};
template<class T>
class BinaryTree {
public:
	BinaryTree() :root(NULL) {}
	BinaryTree(T value) :RefValue(value), root(NULL) {}
	//BinaryTree(BinaryTree<T>& s);
	//~BinaryTree() { destroy(root); }
	bool IsEmpty() { return (root == NULL) ? true : false; }
	/*BinTreeNode<T> *Parent(BinTreeNode<T> *current)
	{
		return (root == NULL || root == current) ?
			NULL : Parent(root, current);
	}
	BinTreeNode<T> *LeftChild(BinTreeNode<T> *current)
	{
		return (current != NULL) ? current->leftChild : NULL;
	}
	BinTreeNode<T> *RightChild(BinTreeNode<T> *current)
	{
		return (current != NULL) ? current->rightChild : NULL;
	}*/
	//int Height(BinTreeNode<T> *p);
	//int Size(BinTreeNode<T> *p);
	BinTreeNode<T>* getRoot()const { return root; }
	void preOrder(BinTreeNode<T> *p);
	void inOrder(BinTreeNode<T> *p);
	void postOrder(BinTreeNode<T> *p);
	//void levelOrder(void(*visit)(BinTreeNode<T> *p));
	//int Insert(const T& item);
	//BinTreeNode<T> *Find(T& item)const;
	void CreatBinTree(BinTreeNode<T> * & subTree);//从文件读入建树
protected:
	BinTreeNode<T> *root;
	T RefValue;
};
	/*template<class T>
	void BinaryTree<T>::destroy(BinTreeNode<T> *& subTree) {
		if (subTree != NULL) {
			destroy(subTree->leftChild);
			destroy(subTree->rightChild);
			delete subTree;
		}
	}*/
	template<class T>
	void BinaryTree<T>::inOrder(BinTreeNode<T> *p) {
		if (p != NULL) {
			inOrder(p->leftChild);
			cout << p->data << " ";
			inOrder(p->rightChild);
		}
	}
	template<class T>
	void BinaryTree<T>::preOrder(BinTreeNode<T> *p) {
		if (p != NULL) {
			cout << p->data << " ";
			preOrder(p->leftChild);
			preOrder(p->rightChild);
		}
	}
	template<class T>
	void BinaryTree<T>::postOrder(BinTreeNode<T> *p) {
		if (p != NULL) {
			postOrder(p->leftChild);
			postOrder(p->rightChild);
			cout << p->data << " ";
		}
	}
	template<class T>
	void BinaryTree<T>::CreatBinTree(BinTreeNode<T> *& subTree) {
		T item;
		cin >> item;
		if (item != '#') {
			subTree = new BinTreeNode<T>(item);
			//if (subTree == NULL) {
			// cerr<<
			// }		
			CreatBinTree(subTree->leftChild);
			CreatBinTree(subTree->rightChild);
		}
		else
			subTree = NULL;
	}
	int main() {
		BinaryTree<char> a;
		BinTreeNode<char> *b;
		b = a.getRoot();
		a.CreatBinTree(b);
		a.preOrder(b);
		cout << endl;
		a.inOrder(b);
		cout << endl;
		a.postOrder(b);
		cout << endl;
		return 0;
	}

