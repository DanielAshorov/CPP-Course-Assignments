#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

class Figure2D {
private:
	double x;
	double y;
	double length;
	double height;
	char* name = NULL;//=NULL Needed for compiler of the testing engine
public:
	Figure2D(double l, double h, double x = 0, double y = 0);
	Figure2D(Figure2D& f);
	Figure2D();
	virtual ~Figure2D();
	const Figure2D& operator=(Figure2D& d);
	void setName(const char*);
	double getX() const;
	double getY() const;
	double getLength() const;
	double getHeight() const;
	const char* getName()const;
	virtual double Area();
	virtual double Perimeter();
	virtual void Shift(double dx, double dy);
	virtual	void MoveTo(double newX, double newY);
	virtual void Resize(double newL, double newH);
	virtual void Scale(double kx, double ky);
	virtual bool isInside(Figure2D* P);//Point(P->getX(),P->getY()) lies inside the figure
	virtual void print() = 0;
	friend ostream& operator<<(ostream& o, Figure2D& d);
};