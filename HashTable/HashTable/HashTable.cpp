// HashTable.cpp : Defines the entry point for the console application.
/**
* Author: Samvid Jhaveri
* ID: N19039005
* Date: Fall 2016
* Partner: Vatsal Gopani & Monil Shah
* Vatsal Gopani (N17368916)
* Monil Shah (N)
* Course: Design and Analysis of Algorithm
*
*
*Summary of File:
*	This is the implementation of the Hash Table with Chained Hashing.
*/

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<array>
#include<iterator>
#include<list>


const int SIZE = 13;

using namespace std;
/*
* 2 global variable array and array with linked list: 1. array<int, SIZE> hashArray & 2. array<list<int>, SIZE> hashListArray
* public function: 
* ->int HashFunc(int inputX)
* ->void HashInsertFunc(int inputX)
* ->void HashChainedInsertFunc(int inputX)
* ->void HashSearchFunc(int inputX)
* ->void HashChainedSearchFunc(int inputX)
* ->void HashRemoveFunc(int inputX)
* ->void HashChainedRemoveFunc(int inputX)
* ->void PrintFunc()
* ->void PrintChainedFunc()
*/

array<int, SIZE> hashArray;
array<list<int>, SIZE> hashListArray;
class Hash {
private:

public:
	/**
	* int HashFunc(int inputX)
	*
	* Paraeters: int: inputX
	* Retun Value: int
	*
	* Summary of the pogram:
	*	This will Hash the input value of the given Integer.
	*/
	int HashFunc(int inputX) {
		int valueX = inputX % SIZE;
		return valueX;
	}
	
	/**
	* void HashInsertFunc(int inputX)
	*
	* Paraeters: int: inputX
	* Retun Value: Nothing
	*
	* Summary of the pogram:
	*	It will compute the hash value and insert it into the array functions
	*/
	void HashInsertFunc(int inputX) {
		int insertX = HashFunc(inputX);
		hashArray[insertX] = inputX;
	}
	/**
	* void HashChainedInsertFunc(int inputX)
	*
	* Paraeters: int: inputX
	* Retun Value: Nothing
	*
	* Summary of the pogram:
	*	It will compute the hash value and insert it into the array with the appropriate list that has been computed.
	*/
	void HashChainedInsertFunc(int inputX) {
		int insertX = HashFunc(inputX);
		list<int>::iterator it;
		it = find(hashListArray[insertX].begin(), hashListArray[insertX].end(), inputX);
		if (it != hashListArray[insertX].end()) {
			cout << "We found out match!! So can't add the value" << endl;
		}
		else {
			hashListArray[insertX].push_back(inputX);
		}
	}
	/**
	* void HashSearchFunc(int inputX)
	*
	* Paraeters: int: inputX
	* Retun Value: Nothing
	*
	* Summary of the pogram:
	*	It will search the value from the table that if the it is already stored in the table or not.
	*/
	void HashSearchFunc(int inputX) {
		array<int,13>::iterator it;
		it = find(hashArray.begin(), hashArray.end(), inputX);
		if (it != hashArray.end()) {
			cout << "We found our match of " << inputX << endl;
		}
		else {
			cout << "No results are found" << endl;
		}
	}
	/**
	* void HashChainedSearchFunc(int inputX)
	*
	* Paraeters: int: inputX
	* Retun Value: Nothing
	*
	* Summary of the pogram:
	*	It will search the table if it has the value that user has feeded is already in it or not.
	*/
	void HashChainedSearchFunc(int inputX) {
		int insertX = HashFunc(inputX);
		list<int>::iterator it;
		it = find(hashListArray[insertX].begin(), hashListArray[insertX].end(), inputX);	
		if (it != hashListArray[insertX].end()) {
			cout << "We found our match of " << inputX << endl;
		}
		else {
			cout << "No results are found" << endl;
		}
	}
	/**
	* void HashRemoveFunc(int inputX)
	*
	* Paraeters: int: inputX
	* Retun Value: Nothing
	*
	* Summary of the pogram:
	*	It will Remove the value that is intended to remove from the table.
	*/
	void HashRemoveFunc(int inputX) {
		int deleteX = HashFunc(inputX);
		
		array<int, 13>::iterator it;
		it = find(hashArray.begin(), hashArray.end(), inputX);
		if (it != hashArray.end()) {
			hashArray[deleteX] = NULL;
		}
		else {
			cout << "No results are found" << endl;
		}

	}
	/**
	* void HashChainedRemoveFunc(int inputX) 
	*
	* Paraeters: int: inputX
	* Retun Value: Nothing
	*
	* Summary of the pogram:
	*	It will go through the each chain and if we find the value than delete that value.
	*/
	void HashChainedRemoveFunc(int inputX) {
		int deleteX = HashFunc(inputX);
		list<int>::iterator it;
		it = find(hashListArray[deleteX].begin(), hashListArray[deleteX].end(), inputX);
		if (it != hashListArray[deleteX].end()) {
			hashListArray[deleteX].remove(inputX);
		}
		else {
			cout << "No results are found" << endl;
		}
	}

	/**
	* void PrintFunc()
	*
	* Paraeters: int: Nothing
	* Retun Value: Nothing
	*
	* Summary of the pogram:
	*	It will print each and value from the array.
	*/
	void PrintFunc() {
		for (int element : hashArray) {
			cout << element << "\n";
		}
	}
	/**
	* void PrintChainedFunc()
	*
	* Paraeters: int: Nothing
	* Retun Value: Nothing
	*
	* Summary of the pogram:
	*	It will print each and value from the array.
	*/
	void PrintChainedFunc() {
		for (int i = 0; i < SIZE; i++) {
			for (int element : hashListArray[i]) {
				cout << element << "\n";
			}
		}
	}
};

/**
* int main()
*
* Paraeters: nothing
* Retun Value: int
*
* Summary of the pogram:
*	User will get different options to input different value in the Hash and remove the elements from the hash table or print the values from the array.
*/
int main()
{
	Hash hash2;
	int ch;
	int inputX;
	while (true) {
		cout << "1. Insert Value for the Hashing" << endl;
		cout << "2. Search the Value in the table" << endl;
		cout << "3. Delete Value from the Hash Table" << endl;
		cout << "4. Print all the values in the Hash Table" << endl;
		cout << "Enter your choice: ";
		cin >> ch;
		cout << "\n\n";
		switch (ch)
		{
		case 1:
			cout << "Enter the value that you want to insert: ";
			cin >> inputX;
			hash2.HashChainedInsertFunc(inputX);
			break;

		case 2:
			cout << "Enter the value that you want to find: ";
			cin >> inputX;
			hash2.HashChainedSearchFunc(inputX);
			break;

		case 3:
			cout << "Enter the value that you want to delete: ";
			cin >> inputX;
			hash2.HashChainedRemoveFunc(inputX);
			break;

		case 4:
			hash2.PrintChainedFunc();
			break;

		default:
			break;
		}
		cout << "\n\n";
	}
	
	return 0;
}

