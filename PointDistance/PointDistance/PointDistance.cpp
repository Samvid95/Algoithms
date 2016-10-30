// PointDistance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

#define PI 3.141592653589793238462643383279502884L 

using namespace std;

class Point {
public:
	double xCoord, yCoord;
	Point() {

	}
	Point(int x, int y) {
		xCoord = x;
		yCoord = y;
	}

	double findAngle(Point p) {
		double angle = atan2(yCoord - p.yCoord, xCoord - p.xCoord);
		cout << "The angle in Radian is: "<<angle << endl;
		angle = angle * 180 / PI;
		cout << "The angle in Degrees is: " << angle << endl;;
		if (angle < 0) {
			angle = angle + 360;
		}
		cout << "The angle after compensating everything is(final): " << angle << endl;
		return angle;
	}
};

int main()
{
	Point p1(4, 5);
	Point p2(7, 5);

	float answer = p1.findAngle(p2);
	cout << "2nd time:" << endl;;
	answer = p2.findAngle(p1);
	
	return 0;
}

