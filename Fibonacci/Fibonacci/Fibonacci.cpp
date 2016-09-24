// Fibonacci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Fib {
private:
	unsigned long lookup_array[70] = { 0,1 };
public:
	long fib_value(int n) {
		if (n == 0) {
			return 0;
		}
		else if (n == 1) {
			return 1;
		}
		else if (lookup_array[n] != 0) {
			return lookup_array[n];
		}
		else {
			unsigned long intermidiate = fib_value(n - 1) + fib_value(n - 2);
			lookup_array[n] = intermidiate;
			return intermidiate;
		}
		
	}
};



int main()
{
	Fib fib;
	unsigned long Answer;
	int n;
	cout << "Enter value to compute it's Fibonacci value: " << endl ;
	cin >> n;
	Answer = fib.fib_value(n);
	cout << Answer << endl;

	return 0;
}

