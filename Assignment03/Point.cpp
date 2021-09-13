#include "Point.h"

Point::Point(Point& f) {
	MoveTo(f.getX(), f.getY());
	Resize(0, 0);
	setName(f.getName());
}

Point :: Point(double x, double y) : Figure2D(0, 0, x, y)
{
}

void Point :: Resize ( double l, double h) 
{
	return;
}

void Point :: Scale (double k1, double k2) {
	Figure2D :: MoveTo(this->getX() * (k1), 
		this->getY() * (k2));
}

Point :: Point ( const char* name, double x, double y) : Figure2D(0, 0, x, y) {
	if (name != NULL)
		setName(name);
}

Point::~Point()
{
}

void Point::print() {
	cout << getName() << ": " << "(" << getX() << ", " << getY() << ")" << endl;
}