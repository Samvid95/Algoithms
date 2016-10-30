// PointDistance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

#define PI 3.141592653589793238462643383279502884L 

using namespace std;

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

	double findAngle(Point p) {
		double angle = atan2(yCoord - p.yCoord, xCoord - p.xCoord);
		cout << "The angle in Radian is: "<<angle << endl;
		angle = angle * 180 / PI;
		cout << "The angle in Degrees is: " << angle << endl;;
		if (angle < 0) {
			angle = angle + 360;
		}
		cout << "The angle after compensating everything is(final): " << angle << endl;
		
		if (angle < 0 && angle <= 22.5) {
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
		cout << part16 << endl;

		return angle;
	}
};

int main()
{
	Point p1(0,0);
	Point p2(-2,-9);

	float answer = p1.findAngle(p2);
	cout << "2nd time:" << endl;;
	answer = p2.findAngle(p1);
	
	return 0;
}

