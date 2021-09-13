#pragma once
#include "Figure2D.h"
#include "Point.h"

class Rectangle : public Figure2D {
public:
	Rectangle (const char* name, Point x, Point y);
	virtual void print();
	virtual ~Rectangle();
	virtual void Scale(double k1, double k2);
	virtual void Resize (double l, double h);
	virtual void Shift (double x, double y);

private:
	Point A, B;
};