// QueueImplementation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#define MAX_SIZE 4
using namespace std;

template <class T>
class My_Queue {
private:
	T my_Array[MAX_SIZE];
	int head, tail;
public:
	My_Queue() {
		head = -1;
		tail = -1;
	}
	
	bool IsFull() {
		if (((tail + 1) % MAX_SIZE) == head) {
			return true;
		}
		return false;
	}
	
	void Enqueue(T element) {
		if (IsFull()) {
			cout << "Queue is Full buddy!!" << endl;
			return;
		}
		if (head == -1 && tail == -1) {
			tail = 0;
			head = 0;
		}
		else {
			tail = (tail + 1) % MAX_SIZE;
		}
		my_Array[tail] = element;
	}

	void Print_All() {
		for (int i = 0; i <= (tail + MAX_SIZE - head)% MAX_SIZE; i++) {
			cout << my_Array[i] << endl;
		}
	}
	T Dequeue() {
		
		if (head == -1 && tail == -1) {
			cout << "Queue is Empty man!! " << endl;
			return 0;
		}
		if (head == tail) {
			head = tail = -1;
		}
		head = (head + 1) % MAX_SIZE;
		T element = my_Array[head];
		return element;
	}
	
};




int main()
{
	My_Queue<int> int_Queue;
	My_Queue<string> string_Queue;
	int midValue;
	int choice;
	while (true) {
		cout << "1: Enqueue" << endl
			<< "2: Dequeue" << endl
			<< "3: PrintAll" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the value: " << endl;
			cin >> midValue;
			int_Queue.Enqueue(midValue);
			break;
		case 2:
			midValue = int_Queue.Dequeue();
			cout << "The value removed is: " << midValue << endl;
			break;
		case 3:
			int_Queue.Print_All();
		default:
			break;
		}
	}
	
	return 0;
}

