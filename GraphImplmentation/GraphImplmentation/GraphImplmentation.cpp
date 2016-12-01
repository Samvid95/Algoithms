/*
// GraphImplmentation.cpp : Defines the entry point for the console application.
// Made By: Samvid Jhaveri
//			Monil Shah
//			Vatsal Gopani
// This is the simple Graph Implementation; I think so many points are left to implemented!!
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

#define ROWS 20
#define COLS 20

using namespace std;

/*
Structure Name: Vertex
Params: Parent, Child, ParentList and ChildList; Value, Color, Weight
 
2 constructors that initalized by Value of the node and another with a default constructor.
*/
struct Vertex {

	Vertex *parent;
	Vertex *child;
	vector<Vertex *> parentList;
	vector<Vertex *> childList;
	int value;
	int color;
	int weight;
	int dist;
	Vertex *top;
	/*
	Function name: Default constructor
	*/
	Vertex() {
		parent = NULL;
		child = NULL;
		value = NULL;
		color = 0;
		weight = NULL;
		parentList.clear();
		childList.clear();
	}
	/*
	Function name: Constructor which initialize the value as defined in the parameter.
	Params: int value
	*/
	Vertex(int value) {
		this->value = value;
		this->parent = NULL;
		this->child = NULL;
		this->color = 0;
		this->weight = NULL;
	}
	
};
/*
Class Graph
Private Memebers:	vertexList
					FindNodeInternal
Public Memebrs:		Graph constructor with a single node
					PrintAll
					CreateNode
					FindNode
					FindColor
					CreateNode
					CreateEdge

*/

class Graph {
private:
	vector<Vertex *> vertexList;
	
	int matrix[ROWS][COLS];
	/*
	Name: FindNodeInternal
	Parameters: int value 
	Return type: Vertex object
	This function returns the object of the vertex by finding it in the list and given the parameter value of the vertex.
	*/
	Vertex* FindNodeInternal(int value) {
		for (int i = 0; i < vertexList.size(); i++) {
			if (vertexList[i]->value == value) {
				return vertexList[i];
			}
		}
		return false;
	}

	int FindNodeIndexInternal(int value) {
		for (int i = 0; i < vertexList.size(); i++) {
			if (vertexList[i]->value == value) {
				return i;
			}
		}
		return 0;
	}

	void AllChilds() {
		for (int i = 0; i < vertexList.size(); i++) {
			cout << "The vertex is: " << vertexList[i]->value << endl;
			cout << "and it's child are: " << endl;
			for (int j = 0; j < vertexList[i]->childList.size(); j++) {
				cout << vertexList[i]->childList[j]->value << endl;
			}
			cout << "and it's parents are: " << endl;
			for (int j = 0; j < vertexList[i]->parentList.size(); j++) {
				cout << vertexList[i]->parentList[j]->value << endl;
			}
			cout << "\n\n";
		}
	}
public:
	/*
	Name: Graph(Constructor)
	Parameters: int value
	Return Type: Nothing
	This function creates an empty root node and push back that vertex in the VertexList
	*/
	Graph(int value) {
		Vertex *node = new Vertex(value);
		vertexList.push_back(node);
	}

	/*
	Name: CreateNode
	Parameters: int value
	Return Type: Nothing
	It will create a newNode and push it back in the vertexList
	*/
	void CreateNode(int value) {
		Vertex *node = new Vertex(value);
		vertexList.push_back(node);
	}

	/*
	Name: CreateNode (Overloaded Method)
	Parameters: int value, int parent
	Retrurn Type: Nothing
	It will generate a new node and add the parent and child object to the appropriate list.
	*/
	void CreateNode(int value, int parent) {
		Vertex *parentNode = FindNodeInternal(parent);
		Vertex *node = new Vertex(value);
		node->parentList.push_back(parentNode);
		node->parent = parentNode;
		parentNode->child = node;
		parentNode->childList.push_back(node);
		vertexList.push_back(node);
	}

	/*
	Name: PrintAll
	Parameters: Nothing
	Return Type: Nothing
	This function gives the output value of the whole graph vertices' values
	*/
	void PrintAll() {
		cout << "\n\n";
		for (int i = 0; i < vertexList.size(); i++) {
			cout << "The value of the vertex is: " << vertexList[i]->value << " and color is: " << vertexList[i]->color << " and dist: " << vertexList[i]->dist<< endl;
		}
	}

	void InitilizeBFS(int value) {
		for (int i = 0; i < vertexList.size(); i++) {
			if (vertexList[i]->value != value) {
				vertexList[i]->color = 0;
				vertexList[i]->dist = -10;
				vertexList[i]->top = NULL;
			}
		}
	}
	/*
	Name: FindNode
	Parameters: int value
	Return Type: Nothing
	It will just find that whether this node exists or not.
	*/
	bool FindNode(int value) {
		for (int i = 0; i < vertexList.size(); i++) {
			if (vertexList[i]->value == value) {
				return true;
			}
		}
		return false;
	}

	Vertex* FindNodeBFS(int value) {
		for (int i = 0; i < vertexList.size(); i++) {
			if (vertexList[i]->value == value) {
				return vertexList[i];
			}
		}
		return false;
	}

	/*
	Name: FindColor
	Parameters: int value
	Return Type: Nothing
	It will findColor of the vertex that is passed by the value
	*/
	void FindColor(int value) {
		Vertex *node = FindNodeInternal(value);
		node->color = 40;
		cout << node->color << endl;
	}

	/*
	Name: CreateEdge
	Parameters: int value, int parent
	Return Type:
	This program should create an edge between the passed two vertices. DID NOT CHECKED THIS SECCTION YET. PLEASE CHECK THIS PART
	*/
	void CreateEdge(int value, int parent) {
		Vertex *node = FindNodeInternal(value);
		Vertex *parentNode = FindNodeInternal(parent);
		node->parentList.push_back(parentNode);
		parentNode->childList.push_back(node);
		
	}
	
	/*
	Name: CreateAdjecency Matrix
	Parameters: NOne
	Return Type: None
	This program will scavange every node of the graph and according to it will create a adjecency matrix.
	*/
	void CreateAdjencyMatrix() {
		for (int i = 0; i < vertexList.size(); i++) {
			for (int j = 0; j < vertexList.size(); j++) {
				matrix[i][j] = 0;
			}
		}
		
		for (int i = 0; i < vertexList.size(); i++) {
			int m = FindNodeIndexInternal(vertexList[i]->value);
			for (int j = 0; j < vertexList[i]->childList.size(); j++) {
				int n;
				n = FindNodeIndexInternal(vertexList[i]->childList[j]->value);
				matrix[m][n] = 1;
			}
		}
		
	}
	/*
	Name: CreateAdjencyMatrix
	Parameter: int arr[][] (2-D Array), int size
	Return Type: None
	This is an overloaded method which create the adjency matrix of this graph. 
	*/
	void CreateAdjencyMatrix(int arr[ROWS][COLS], int size) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				matrix[i][j] = arr[i][j];
			}
		}
	}
	/*
	Name: SearchEdge
	Parameters: int value and int parent
	Return Type: int value
	This program will return an edge's weight if it exists.
	*/
	int SearchEdge(int value, int parent) {
		int m = FindNodeIndexInternal(value);
		Vertex *mm = FindNodeInternal(value);
		//cout << "THe size of the child list is: " << mm->childList.size();
		//cout << "The value is: " << m << endl;
		int n = FindNodeIndexInternal(parent);
		//cout << "The parent's value is: " << n << endl;
		return matrix[m][n];
	}

	/*
	Name: PrintAdjecencyMatrix
	Parameters: None
	Return Type: None
	This functin will print the adjecency matrix of the graph.
	*/
	void PrintAdjencyMatrix() {
		cout << "\n\n";
		for (int i = 0; i < vertexList.size(); i++) {
			cout << vertexList[i]->value << "\t";
		}
		cout << "\n";
		for (int i = 0; i < vertexList.size(); i++) {
			for (int j = 0; j < vertexList.size(); j++) {
				cout << matrix[i][j] << "\t";
			}
			cout << "\n";
		}
	}
};
/*
Name: CreateGraphbyMatrix
Parameters: None
ReturnType: Graph*
This is an alternative and faster method to create graph by supplying the adjecency matrix values.
*/
Graph* CreateGrpahbyMatrix() {
	vector<int> values;
	int n;
	cout << "Enter the number of vertices:";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cout << "Enter the value of Vertex " << i << " : ";
		cin >> temp;
		values.push_back(temp);
	}
	cout << "\n\n";
	int tempMatrix[ROWS][COLS];
	cout << "Now enter the matrix value row wise: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Enter value for element[" << i << "][" << j <<"]: ";
			cin >> tempMatrix[i][j];
		}
		cout << "\n";
	}

	Graph *gAd = new Graph(values[0]);
	for (int i = 1; i < n; i++) {
		gAd->CreateNode(values[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tempMatrix[i][j] != 0) {
				gAd->CreateEdge(values[j], values[i]);
			}
		}
	}

	gAd->CreateAdjencyMatrix(tempMatrix, n);

	return gAd;
}

void BFS(Graph *gh, int value) {
	gh->InitilizeBFS(value);
	Vertex *s = gh->FindNodeBFS(value);
	s->color = 1;
	s->dist = 0;
	s->top = NULL;
	queue<Vertex *> Queue;
	Queue.push(s);
	while (!Queue.empty())
	{
		Vertex *temp = Queue.front();
		for (int i = 0; i < temp->childList.size(); i++) {
			Vertex *v = temp->childList[i];
			if (v->color == 0) {
				v->color = 1;
				v->dist = temp->dist + 1;
				v->top = temp;
				Queue.push(v);
			}
		}
		temp->color = 2;
		Queue.pop();
	}
}


int main()
{
	/*
	Graph *gh = new Graph(13); //Generate a graph

	gh->CreateNode(8);
	gh->CreateNode(9);
	
	gh->CreateEdge(8, 13);
	gh->CreateEdge(8,9);
	gh->CreateEdge(13, 9);
	gh->CreateEdge(13, 8);
	gh->CreateEdge(9, 8);
	gh->CreateEdge(9, 13);

	gh->CreateNode(15);
	gh->CreateNode(20);
	gh->CreateEdge(15, 20);

	gh->CreateAdjencyMatrix();
	gh->PrintAdjencyMatrix();
	*/
	
	Graph *gh;
	gh = CreateGrpahbyMatrix();
	BFS(gh, 3);
	gh->PrintAll();

	/*
	BFS(gh, 3);
	gh->PrintAll();
	*/
	return 0;
}

