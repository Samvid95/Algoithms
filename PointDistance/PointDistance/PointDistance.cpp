// PointDistance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <array>
#include <vector>

#define SIZE 5

#define PI 3.141592653589793238462643383279502884L 

using namespace std;

vector<int> directions;

class Point {
private:
	unsigned short int part16;
public:
	double xCoord, yCoord;
	Point() {

	}
	Point(int x, int y) {
		xCoord = x;
		yCoord = y;
	}

	void findAngle(Point p) {
		double angle = atan2(yCoord - p.yCoord, xCoord - p.xCoord);
		//cout << "The angle in Radian is: "<<angle << endl;
		angle = angle * 180 / PI;
		//cout << "The angle in Degrees is: " << angle << endl;;
		if (angle < 0) {
			angle = angle + 360;
		}
		
		
		if (angle <= 0 && angle <= 22.5) {
			part16 = 1;
		}
		else if (angle < 22.5 && angle <= 45) {
			part16 = 2;
		}
		else if (angle < 45 && angle <= 67.5) {
			part16 = 3;
		}
		else if (angle < 67.5 && angle <= 90) {
			part16 = 4;
		}
		else if (angle < 90 && angle <= 112.5) {
			part16 = 5;
		}
		else if (angle < 112.5 && angle <= 135) {
			part16 = 6;
		}
		else if (angle < 135 && angle <= 157.5) {
			part16 = 7;
		}
		else if (angle < 157.5 && angle <= 180) {
			part16 = 8;
		}
		else if (angle < 180 && angle <= 202.5) {
			part16 = 9;
		}
		else if (angle < 202.5 && angle <= 225) {
			part16 = 10;
		}
		else if (angle < 225 && angle <= 247.5) {
			part16 = 11;
		}
		else if (angle < 247.5 && angle <= 270) {
			part16 = 12;
		}
		else if (angle < 270 && angle <= 292.5) {
			part16 = 13;
		}
		else if (angle < 292.5 && angle <= 315) {
			part16 = 14;
		}
		else if (angle < 315 && angle <= 337.5) {
			part16 = 15;
		}
		else if (angle < 337.5 && angle <= 360) {
			part16 = 16;
		}
		cout << "The angle after compensating everything is(final): " << angle << " and the quadrent will be: " << part16 << endl;
	}

};

void printSequence(Point p) {

}

int main()
{
	array<Point, SIZE> array1;
	for (int i = 0; i < SIZE; i++) {
		Point p;
		cout << "Enter the X-coord for " << i+1 << " : ";
		cin >> p.xCoord;
		cout << "Enter the Y-coord for " << i+1 << " : ";
		cin >> p.yCoord;
		array1[i] = p;
	}
	
	for (int i = 0; i < SIZE - 1; i++) {
		array1[i+1].findAngle(array1[i]);
	}

	for (int i = 0; i < SIZE - 1; i++) {
		printSequence(array1[i]);
	}
	return 0;
}

