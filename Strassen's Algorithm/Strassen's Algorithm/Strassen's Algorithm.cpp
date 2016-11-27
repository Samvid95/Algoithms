// Strassen's Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>
#include <vector>

using namespace std;

const int SIZE = 2;

class Matrix {
private:
	
public:
	array<array<int, SIZE>, SIZE> A;

	void PopulateMatrix() {
		for (int i = 0; i <SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				cout << "Enter element [" << i << "][" << j << "] : ";
				cin >> A[i][j];
			}
		}
	}

	void PrintMatrix() {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				cout << A[i][j];
			}
			cout << endl;
		}
	}

	Matrix& operator*(Matrix matrixB) {
		Matrix matrixC;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				matrixC.A[i][j] = 0;
				for (int k = 0; k < SIZE; k++) {
					matrixC.A[i][j] = matrixC.A[i][j] + A[i][k] * matrixB.A[k][j];
				}
			}
		}
		return matrixC;
	}

	void Square_Matrix_Multiply_Recursive(Matrix matrixB) {
		int n = SIZE;
		Matrix matrixC;
		if (n == 1) {
			matrixC.A[1][1] = A[1][1] * matrixB.A[1][1];
		}
		else {
			
		}
	}
	void printSize() {
		cout << "\n\n\n\nThis is the size of the matrix: " << A.size();
		cout << "\nThis is the other size after passing A[1][1] : " << A[0].size();
		cout << "\nThis is the other size after passing A[2][1] : " << A[1].size();
	}
};

int main()
{
	Matrix matrixA;
	matrixA.PopulateMatrix();
	matrixA.PrintMatrix();
	//Matrix matrixB;
	//matrixB.PopulateMatrix();
	//matrixA = matrixA*matrixB;
	//matrixA.PrintMatrix();
	matrixA.printSize();

	return 0;
}

