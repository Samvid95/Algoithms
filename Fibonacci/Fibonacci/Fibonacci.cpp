// Fibonacci.cpp : Defines the entry point for the console application.
//
/**
* Author: Samvid Jhaveri
* Date: Fall 2016
* Partner: I work alone #LONE-RANGER
* Course: Design and Analysis of Algorithm
*
*
*Summary of File:
*	This program is Memoised Fibonacci and it is a faster way to compute the answer of Fibonacci
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

class Fib {
private:
	unsigned long lookup_array[70] = { 0,1 };
public:
	/**
	* long fib_value(int n)
	*
	* Paraeters: int: n
	* Retun Value: long
	*
	* Summary of the pogram:
	*	This function will compute and store Fibonacci values in the array so that it will give the faster output.
	*/
	long Fib_Value(int n) {
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
			unsigned long intermidiate = Fib_Value(n - 1) + Fib_Value(n - 2);
			lookup_array[n] = intermidiate;
			return intermidiate;
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
*	Calls the Fib_Value function of the class and return the output.
*/


int main()
{
	Fib fib;
	unsigned long Answer;
	int n;
	cout << "Enter value to compute it's Fibonacci value: " << endl ;
	cin >> n;
	Answer = fib.Fib_Value(n);
	cout << Answer << endl;

	return 0;
}

