// Fibonacci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Fib {
public:
	long fib_value(int n) {
		if (n == 0) {
			return 0;
		}
		else if (n == 1) {
			return 1;
		}
		else {
			return (fib_value(n - 1) + fib_value(n - 2));
		}
		
	}
};



int main()
{
	Fib fib;
	long Answer;
	int n;
	cout << "Enter value to compute it's Fibonacci value: " << endl ;
	cin >> n;
	Answer = fib.fib_value(n);
	cout << Answer << endl;

	return 0;
}

