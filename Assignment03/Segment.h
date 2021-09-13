#pragma once
#include "Figure2D.h"
#include "Point.h"

class Segment: public Figure2D {
public:
	virtual double Perimeter();
	virtual double Area();
	virtual void Resize(double l, double h);
	virtual void Shift(double x, double y);
	virtual void Scale(double k1, double k2);
	virtual void print();
	Segment(const char* name, Point x, Point y);
	virtual ~Segment();

private:
	bool direction;
	Point A, B;
};