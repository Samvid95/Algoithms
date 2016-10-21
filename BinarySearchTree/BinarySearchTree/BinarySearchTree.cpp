// BinarySearchTree.cpp : Defines the entry point for the console application.
//
/**
* Author: Samvid Jhaveri
* ID: N19039005
* Date: Fall 2016
* Partner: Lone Ranger!!
* Course: Design and Analysis of Algorithm
*
*
* Summary of File:
*	This is the implementation of the Binary Search Tree.
*	STILL THIS PROGRAM IS INCOMPLETE SUCCESSOR AND DELETE METHODS ARE REMAINING!!!!
*/
#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <array>

using namespace std;

template <class T>
struct node {
	T value;
	node<T> *left;
	node<T> *right;

	/**
	* node(T value)
	*
	* Paraeters: T type
	* Retun Value: Constructor!!!
	*
	* Summary of the pogram:
	*	This is the initialising constructor.
	*/
	node(T value) {
		this->value = value;
	}
};

template <class T>
class myTree {
private:
	node<T> *root;

	/**
	* void addValueFunc(node<T> *root, T value)
	*
	* Paraeters: *root (Root node) & T type value
	* Retun Value: Nothing
	*
	* Summary of the pogram:
	*	This value will add value at appropriate place in the Tree.
	*/
	void addValueFunc(node<T> *root, T value) {
		if (value < root->value) {
			if (!root->left) {
				root->left = new node<T>(value);
				root->left->left = NULL;
				root->left->right = NULL;
			}
			else {
				addValueFunc(root->left, value);
			}
		}
		if (value > root->value) {
			if (!root->right) {
				root->right = new node<T>(value);
				root->right->left = NULL;
				root->right->right = NULL;
			}
			else {
				addValueFunc(root->right, value);
			}
		}
	}

	/**
	* void printAllFunc(node<T> *root)
	*
	* Paraeters: *root (Root node)
	* Retun Value: Nothing
	*
	* Summary of the pogram:
	*	This value will print every value in the tree. (Recursive function)
	*/
	void printAllFunc(node<T> *root) {
		if (!root) {
			return;
		}
		printAllFunc(root->left);
		cout << root->value << endl;
		printAllFunc(root->right);
	}

	/**
	* T TreeMinimumFunc(node<T> *x)
	*
	* Paraeters: *x(node)
	* Retun Value: T type value
	*
	* Summary of the pogram:
	*	This value will return the minimum value of the tree.
	*/
	T TreeMinimumFunc(node<T> *x) {
		T mid;
		if (x->left == NULL) {
			return x->value;
		}
		else {
			mid = TreeMinimumFunc(x->left);
		}
	}

	/**
	* T TreeMaximumFunc(node<T> *x)
	*
	* Paraeters: *x(node)
	* Retun Value: T type value
	*
	* Summary of the pogram:
	*	This value will return the maximum value of the tree.
	*/
	T TreeMaximumFunc(node<T> *x) {
		T mid;
		if (x->right == NULL) {
			return x->value;
		}
		else {
			mid = TreeMaximumFunc(x->right);
		}
	}

	/**
	* node<T> * searchTreeNode(T value)
	*
	* Paraeters: T type value
	* Retun Value: node<T> * (pointer to node)
	*
	* Summary of the pogram:
	*	This value will return the node of the passed value.
	*/
	node<T> * searchTreeNode(T value) {

		node<T> *x;
		x = root;
		while (x != NULL)
		{
			if (x->value == value) {
				cout << "We found the value" << endl;
				return x;
			}
			else if (value < x->value) {
				x = x->left;
			}
			else {
				x = x->right;
			}
		}
	}

	/**
	* T SubtreeMinimum(node<T> *x)
	*
	* Paraeters: T type value
	* Retun Value: node<T> * (pointer to node)
	*
	* Summary of the pogram:
	*	This value will return the minimum value of the subtree passed.
	*/
	T SubtreeMinimum(node<T> *x) {
			T mid;
			if (x->left == NULL) {
				return x->value;
			}
			else {
				mid = TreeMinimumFunc(x->left);
			}
	}

public:
	/**
	* void addValue(T value)
	*
	* Paraeters: T type value
	* Retun Value: nothing
	*
	* Summary of the pogram:
	*	This will add value in the tree.
	*/
	void addValue(T value) {
		if (root) {
			addValueFunc(this->root,value);
		}
		else {
			root = new node<T>(value);
			root->left = NULL;
			root->right = NULL;
		}
	}
	
	/**
	* void searchTree(T value)
	*
	* Paraeters: T type value
	* Retun Value: nothing
	*
	* Summary of the pogram:
	*	This will search the value in the tree.
	*/
	void searchTree(T value) {
		
		node<T> *x;
		x = root;
		while (x != NULL)
		{
			if (x->value == value) {
				cout << "We found the value" << endl;
				break;
			}
			else if (value < x->value) {
				x = x->left;
			}
			else {
				x = x->right;
			}
		}	
	}
	
	/**
	* void printAll(void)
	*
	* Paraeters: nothhing
	* Retun Value: nothing
	*
	* Summary of the pogram:
	*	This will print everything from the tree.
	*/
	void printAll(void) {
		printAllFunc(this->root);
	}

	/**
	* void TreeMinimum(void)
	*
	* Paraeters: nothhing
	* Retun Value: nothing
	*
	* Summary of the pogram:
	*	This will find the minimum value of the tree.
	*/
	void TreeMinimum(void) {
		node<T> *x;
		x = root;
		T answer;
		answer = TreeMinimumFunc(x);
		cout << "Minimum value is: " << answer << endl;
	}

	/**
	* void TreeMaximum(void)
	*
	* Paraeters: nothhing
	* Retun Value: nothing
	*
	* Summary of the pogram:
	*	This will find the maximum value of the tree.
	*/
	void TreeMaximum(void) {
		node<T> *x;
		x = root;
		T answer;
		answer = TreeMaximumFunc(x);
		cout << "Maximum value is: " << answer << endl;
	}

	/*
	void Successor(T value) {
		node<T> *x;
		node<T> *y;
		x = searchTreeNode(value);
		y = x;
		if (x->right != NULL) {
			T answer = SubtreeMinimum(x->right);
			cout << "The successor is: " << answer << endl;
		}
		else {
			y = x;
			while (y != NULL && x == y->right) {
				x = y;
				y = y->
			}
			cout << "The succssor is: " << y->value << endl;
		}
	}
	*/
};
int main()
{
	myTree<int> *tree = new myTree<int>();
	tree->addValue(4);
	tree->addValue(7);
	tree->addValue(2);
	tree->addValue(10);
	tree->addValue(3);
	tree->addValue(8);
	tree->addValue(1);
	tree->addValue(9);
	tree->printAll();	
	tree->searchTree(15);
	tree->searchTree(1);
	tree->TreeMinimum();
	tree->TreeMaximum();



	return 0;
	
}

