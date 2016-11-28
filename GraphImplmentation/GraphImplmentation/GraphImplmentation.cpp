/*
// GraphImplmentation.cpp : Defines the entry point for the console application.
// Made By: Samvid Jhaveri
// This is the simple Graph Implementation; I think so many points are left to implemented!!
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>

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
	
	int matrix[20][20];
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
		for (int i = 0; i < vertexList.size(); i++) {
			cout << "The value of the vertex is: " << vertexList[i]->value << endl;
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

	int SearchEdge(int value, int parent) {
		int m = FindNodeIndexInternal(value);
		cout << "The value is: " << m << endl;
		int n = FindNodeIndexInternal(parent);
		cout << "The parent's value is: " << n << endl;
		return matrix[m][n];
	}

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


int main()
{
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
	

	return 0;
}

