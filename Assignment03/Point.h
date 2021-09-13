#pragma once
#include "Figure2D.h"

class Point : public Figure2D {
	friend class Segment;
public:
	Point(Point& f);
	virtual void Resize(double l, double h);
	virtual void Scale(double k1, double k2);
	Point(double x, double y);
	Point(const char* name = NULL, double x = 0, double y = 0);
	virtual void print();
	virtual ~Point();
private:
};