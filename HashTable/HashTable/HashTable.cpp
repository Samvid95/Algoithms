// HashTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<array>
#include<iterator>

#define SIZE 13

using namespace std;

array<int, 13> hashArray;
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
	//Check for library array 
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
	void PrintFunc() {
		for (int element : hashArray) {
			cout << element << "\n";
		}
	}
};

int main()
{
	Hash hash;
	hash.HashInsertFunc(15);
	hash.HashInsertFunc(16);
	hash.HashInsertFunc(17);

	hash.HashSearchFunc(20);
	hash.HashSearchFunc(16);

	hash.PrintFunc();

	hash.HashRemoveFunc(20);
	hash.HashRemoveFunc(17);

	hash.PrintFunc();
	return 0;
}

