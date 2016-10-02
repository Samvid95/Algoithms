// HashTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<array>
#include<iterator>
#include<list>


const int SIZE = 13;

using namespace std;

array<int, SIZE> hashArray;
array<list<int>, SIZE> hashListArray;
class Hash {
private:

public:
	
	int HashFunc(int inputX) {
		int valueX = inputX % SIZE;
		return valueX;
	}
	
	void HashInsertFunc(int inputX) {
		int insertX = HashFunc(inputX);
		hashArray[insertX] = inputX;
	}

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

	void PrintFunc() {
		for (int element : hashArray) {
			cout << element << "\n";
		}
	}

	void PrintChainedFunc() {
		for (int i = 0; i < SIZE; i++) {
			for (int element : hashListArray[i]) {
				cout << element << "\n";
			}
		}
	}
};

int main()
{
	Hash hash,hash2;
	/*
	hash.HashInsertFunc(15);
	hash.HashInsertFunc(16);
	hash.HashInsertFunc(17);

	hash.HashSearchFunc(20);
	hash.HashSearchFunc(16);

	hash.PrintFunc();

	hash.HashRemoveFunc(20);
	hash.HashRemoveFunc(17);

	hash.PrintFunc();
	*/
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

