// Insertion Sort and Exercise 2.1.x.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <algorithm>


#define SIZE 5

int input[SIZE];
using namespace std;

void Ascending_Sort() {
	int j, temp;
	for (int i = 0; i < SIZE; i++) {
		j = i;

		while (j > 0 && input[j] < input[j - 1]) {
			temp = input[j];
			input[j] = input[j - 1];
			input[j - 1] = temp;
			j--;
		}
	}
}

void Descending_Sort() {
	int j, temp;
	for (int i = 0; i < SIZE; i++) {
		j = i;

		while (j > 0 && input[j] > input[j - 1]) {
			temp = input[j];
			input[j] = input[j - 1];
			input[j - 1] = temp;
			j--;
		}
	}
}

void Search(int value) {
	bool found = false;
	for (int i = 0; i < SIZE; i++) {
		if (input[i] == value) {
			found = true;
		}
	}
	if (found == true) {
		cout << "We found the value";
	}
	else {
		cout << "The value is not found!!!";
	}
}

int main()
{
	
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Input the value " << i << " : ";
		cin >> input[i];
	}
	
	Search(7);
	
	for (int i = 0; i < SIZE; i++)
	{
		cout << input[i] << endl;
	}
	return 0;
}

