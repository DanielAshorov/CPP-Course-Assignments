#pragma once
#include "Figure2D.h"
#include "Point.h"

class Square : public Figure2D {
	friend ostream& operator<<(ostream& o, Square& d);
public:
	virtual void print();
	virtual double Area();
	virtual void Resize(double l, double h);
	virtual void Shift(double x, double y);
	virtual void Scale(double k1, double k2);
	Square(const char* name, Point x, Point y);
	Square();
	Square(const char* name, Point z, float x);
	virtual ~Square();
	virtual double Perimeter();
	Square& operator= (const Square& z);
	Square(Square& f);
	virtual bool isInside(Figure2D* P);

private:
	Point A;
};