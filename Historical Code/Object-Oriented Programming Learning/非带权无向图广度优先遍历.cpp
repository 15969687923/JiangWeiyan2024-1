// 非带权无向图广度优先遍历.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<iostream>
#include<cstdlib>
#include<string>
#include<queue>

using namespace std;
const int MAXSIZE = 30;

template<class T, class E>
struct Edge {
	int dest;
	E cost;
	Edge<T, E> *link;
	Edge() {}
	Edge(int num, E weight) :dest(num), cost(weight), link(NULL) {}
	bool operator !=(Edge<T, E> &temp)const {
		return (dest != temp.dest) ? true : false;
	}
};

template <class T, class E>
struct Vertex {
	T data;
	Edge<T, E>* adj;
};

template <class T, class E>
class Graph {
protected:
	int maxVertices;
	int numEdges;
	int numVertices;
	Vertex<T, E>* NodeTable;
public:
	Graph(int sz = MAXSIZE);
	~Graph();

	//istream& operator>><>(istream& in, Graph<T, E>& G);
	int NumberOfVertices() { return this->numVertices; }
	int NumberOfEdges() { return this->numEdges; }
	T getValue(int i);
	E getWeight(int v1, int v2);
	bool insertVertex(T& vertex);
	bool insertEdge(int v1, int v2, E cost);
	bool removeVertex(int v);
	bool removeEdge(int v1, int v2);
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	void inputGraph(int num_dots);
	void output();
	int getVertexPos(T vertex);
};

template<class T, class E>
Graph<T, E>::Graph(int sz) {
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	NodeTable = new Vertex<T, E>[maxVertices];
	if (NodeTable == NULL) {
		cout << "存储分配错误" << endl;
		exit(1);
	}
	for (int i = 0; i < maxVertices; i++)
		NodeTable[i].adj = NULL;
}
template<class T, class E>
Graph<T, E>::~Graph() {
	for (int i = 0; i < numVertices; i++) {
		Edge<T, E> *p = NodeTable[i].adj;
		while (p != NULL) {
			NodeTable[i].adj = p->link;
			delete p;
			p = NodeTable[i].adj;
		}
	}
	delete NodeTable;
}
template<class T, class E>
T Graph<T, E>::getValue(int i) {
	return (i >= 0 && i < numVertices) ? NodeTable[i].data : 0;
}
template<class T, class E>
E Graph<T, E>::getWeight(int v1, int v2) {
	if (v1 != -1 && v2 != -1) {
		Edge<T, E> *p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2) {
			p = p->link;
		}
		if (p != NULL)return p->cost;
	}
	return 0;
}
template<class T, class E>
bool Graph<T, E>::insertVertex(T &vertex) {
	if (numVertices == maxVertices) return false;
	NodeTable[numVertices].data = vertex;
	numVertices++;
	return true;
}
//template<class T, class E>
//bool Graph<T, E>::putoutVertex(T &vertex) {
//	for (int i = 0; i < numVertices-1; i++) {
//		cout << NodeTable[numVertices].data;
//	}
//	return true;
//}
template<class T, class E>
bool Graph<T, E>::insertEdge(int v1, int v2, E weight) {
	if (v1 >= 0 && v1<numVertices&&v2 >= 0 && v2<numVertices) {
		Edge<T, E> *q, *p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2)
			p = p->link;
		if (p != NULL)return false;
		p = new Edge<T, E>;
		q = new Edge<T, E>;
		p->dest = v2; p->cost = weight;
		p->link = NodeTable[v1].adj;
		NodeTable[v1].adj = p;
		q->dest = v1; q->cost = weight;
		q->link = NodeTable[v2].adj;
		NodeTable[v2].adj = q;
		numEdges++;
		return true;
	}
	return 0;
}
template<class T, class E>
bool Graph<T, E>::removeVertex(int v) {
	if (numVertices == 1 || v < 0 || v >= numVertices)return false;
	Edge<T, E> *p, *s, *t;
	int i, k;
	while (NodeTable[v].adj != NULL) {
		p = NodeTable[v].adj;
		k = p->dest;
		s = NodeTable[k].adj;
		t = NULL;
		while (s != NULL && s->dest != v) {
			t = s;
			s = s->link;
		}
		if (s != NULL) {
			if (t == NULL)NodeTable[k].adj = s->link;
			else t->link = s->link;
			delete s;
		}
		NodeTable[v].adj = p->link;
		delete p;
		numEdges--;
	}
	numVertices--;
	NodeTable[v].data = NodeTable[numVertices].data;
	p = NodeTable[v].adj = NodeTable[numVertices].adj;
	while (p != NULL) {
		s = NodeTable[p->dest].adj;
		while (s != NULL) {
			if (s->dest == numVertices) {
				s->dest = v;
				break;
			}
			else s = s->link;
		}
	}
	return true;
}
template<class T, class E>
bool Graph<T, E>::removeEdge(int v1, int v2) {
	if (v1 != -1 && v2 != -1) {
		Edge<T, E> *p = NodeTable[v1].adj, *q = NULL, *s = p;
		while (p != NULL && p->dest != v2) {
			q = p;
			p = p->link;
		}
		if (p != NULL) {
			if (p == s)NodeTable[v1].adj = p->link;
			else q->link = p->link;
			delete p;
		}
		else return false;
		p = NodeTable[v2].adj;
		q = NULL;
		s = p;
		while (p->dest != v1) {
			q = p;
			p = p->link;
		}
		if (p == s)NodeTable[v2].adj = p->link;
		else q->link = p->link;
		delete p;
		return true;
	}
	return false;
}
template<class T, class E>
int Graph<T, E>::getFirstNeighbor(int v) {
	if (v != -1) {
		Edge<T, E> *p = NodeTable[v].adj;
		if (p != NULL)
			return p->dest;
	}
	return -1;
}
template<class T, class E>
int Graph<T, E>::getNextNeighbor(int v, int w) {
	if (v != -1) {
		Edge<T, E> *p = NodeTable[v].adj;
		while (p != NULL && p->dest != w)
			p = p->link;
		if (p != NULL && p->link != NULL)
			return p->link->dest;
	}
	return -1;
}
template<class T, class E>
int Graph<T, E>::getVertexPos(T vertex) {
	for (int i = 0; i < numVertices; i++)
		if (NodeTable[i].data == vertex)return i;
	return -1;
}
template<class T, class E>
void Graph<T, E>::inputGraph(int num_dots) {
	char ch = ' ';
	//int num_dots = 0;
	///cin >> num_dots;//点个数
	int num_edges = 0;
	cin >> num_edges;//边个数
	

	for(int i=0;i<num_dots;i++){
		cin >> ch;
		this->insertVertex(ch);
	}

	char v1, v2;
	int value = 0;
	while (num_edges--) {
		cin >> v1 >> v2;
		int a, b;
		a = v1 - 'A';
		b = v2 - 'A';
		this->insertEdge(a, b, 0);
	}

}

template<class T, class E>
void Graph<T, E>::output() {
	Edge<T, E> *p = NULL;
	for (int i = 0; i < numVertices; i++) {
		
		p = NodeTable[i].adj;
		cout << (int)NodeTable[i].data - 'A' << " "<< NodeTable[i].data;
		while (p != NULL) {
			cout <<"-->"<< (int)NodeTable[p->dest].data-'A';
			p = p->link;
		}
		cout << endl;
	}
}

template<class T, class E>
void DFS(Graph<T, E> &G, const T&v) {
	int loc, n = G.NumberOfVertices();
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)visited[i] = false;
	loc = G.getVertexPos(v);
	DFS(G, loc, visited);
	delete[] visited;
}

template<class T, class E>
void DFS(Graph<T, E> &G, int v, bool *visited) {
	cout << G.getValue(v) << " ";
	visited[v] = true;
	int w = G.getFirstNeighbor(v);
	while (w != -1) {
		if (visited[w] == false)DFS(G, w, visited);
		w = G.getNextNeighbor(v, w);
	}
}
template<class T, class E>
void BFS(Graph<T, E> &G, const T&v) {
	int w, n = G.NumberOfVertices();
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)visited[i] = false;
	int loc = G.getVertexPos(v);
	cout << G.getValue(loc) << " ";
	visited[loc] = true;
	queue<int> Q;
	Q.push(loc);
	while (!Q.empty()) {
		loc = Q.front();
		Q.pop();
		w = G.getFirstNeighbor(loc);
		while (w != -1) {
			if (visited[w] == false) {
				cout << G.getValue(w) << " ";
				visited[w] = true;
				Q.push(w);
			}
			w = G.getNextNeighbor(loc, w);
		}
	}
	delete[] visited;
}


int main() {
	int num_dots;
	cin >> num_dots;
	Graph<char, int> G(num_dots);
	G.inputGraph(num_dots);

	//cin >> G;
	char ch = ' ';
	cin >> ch;
	//DFS(G, ch);
	G.output();
	BFS(G, ch);

	cout << endl;
	return 0;
}
/*输入：
A
B
C
D
E
F
G
H
I
#
10
0 1
0 2
0 3
1 4
1 2
2 5
3 5
4 6
5 7
7 8
A
*/
/*输出：
DFS:A D F H I C B E G
BFS:A D C B F E H G I
A:D C B
B:C E A
C:F B A
D:F A
E:G B
F:H D C
G:E
H:I F
I:H
*/