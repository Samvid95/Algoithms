// Strassen's Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>
#include <vector>

using namespace std;

const int SIZE = 3;

class Matrix {
private:

public:
	vector<vector<int>> matrix;
	vector<int> tempVector;

	
	Matrix(int SIZE) {
		matrix.resize(SIZE);
		for (int i = 0; i < SIZE; i++) {
			matrix[i].resize(SIZE);
		}
	}

	void PopulateNatrix() {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				int temp;
				cout << "Enter value for element [" << i << "][" << j << "] : ";
				cin >> temp;
				tempVector.push_back(temp);
			}
			matrix.push_back(tempVector);
		}

		
	}

	void PrintMatrix() {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}
};

int main()
{
	Matrix matrixA(3);
	matrixA.PopulateNatrix();
	matrixA.PrintMatrix();
	return 0;
}

