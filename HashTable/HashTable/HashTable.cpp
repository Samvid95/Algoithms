// HashTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

#define SIZE 13

using namespace std;

int map[SIZE];
class Hash {
private:

public:
	int HashFunc(int inputX) {
		int valueX = inputX % SIZE;
		return valueX;
	}
	
	void HashInsertFunc(int inputX) {
		int insertX = HashFunc(inputX);
		map[insertX] = inputX;
	}
	//Check for library array 
	void HashRemoveFunc(int inputX) {

	}
};

int main()
{
    return 0;
}

