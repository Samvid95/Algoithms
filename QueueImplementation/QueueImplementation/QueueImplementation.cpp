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
	
	
	void Enqueue(T element) {
		if (head == -1 && tail == -1) {
			tail = 0;
			head = 0;
		}
		tail = (tail + 1)%MAX_SIZE;
		my_Array[tail] = element;
	}

	void Print_All() {
		for (int i = tail; i <= tail; i++) {
			cout << my_Array[i] << endl;
		}
	}
	T Dequeue() {
		T element = my_Array[head];
		head = (head + 1) % MAX_SIZE;
		return element;
	}
	
	T HeadPeek() {
		return head;
	}
	
	T TailPeek() {
		return tail;
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
			<< "3: HeadPeek" << endl
			<< "4: TailPeek" << endl
			<< "5: PrintAll" << endl;

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
			int headValue;
			headValue = int_Queue.HeadPeek();
			cout << "The Head is: " << headValue << endl;
			break;
		case 4:
			int tailValue;
			tailValue = int_Queue.TailPeek();
			cout << "The Tail is: " <<tailValue << endl;
			break;
		case 5:
			int_Queue.Print_All();
		default:
			break;
		}
	}
	
	return 0;
}

