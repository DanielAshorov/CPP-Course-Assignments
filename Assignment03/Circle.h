#pragma once
#include "Figure2D.h"
#include "Point.h"

class Circle : public Figure2D {
public:
	Circle(const char* n, Point x, double r);
	virtual ~Circle();
	virtual void print();
	virtual bool isInside(Figure2D* P);
	virtual double Perimeter();
	virtual double Area();
	virtual void Resize(double l, double h);
	virtual void Shift (double x, double y);
	virtual void Scale(double k1, double k2);
private:
	Point center;
	double radius;
};