#include "Circle.h"
#define p 3.1415926535897931 // as requested

Circle :: Circle (const char* n, Point x, double r) : center(x.getX() + r, x.getY()+ r) {
	setName(n);
	radius = r;
	Figure2D :: MoveTo(x.getX(), x.getY());
	Figure2D :: Resize((center.getX() + radius) - x.getX(), (center.getY() + radius) - x.getY());
}

bool Circle::isInside(Figure2D* P) { //P = pie
	double y, x;
	y = pow (P->getY() - center.getY(), 2);
	x = pow (P->getX() - center.getX(), 2);
	if ((sqrt (pow(x, 2) + pow(y, 2))) <=radius)
		return 1;
	return 0;
}

Circle::~Circle()
{
}

double Circle::Area() {
	return (pow(radius, 2) * p);
}

double Circle::Perimeter() {
	return 2 * p * radius;
}

void Circle::print() {
	cout << "Circle " << this->getName() << " with center " << "(" << center.getX() << ", " << center.getY() << ")" 
		<< " and radius = " << radius << endl;
}

void Circle::Resize(double l, double h) {
	center.Shift((l - this->getLength()) / 2 , (h - this->getHeight())/ 2);
	Figure2D::Resize(l, h);
	radius = center.getX() - Figure2D::getX();
}

void Circle :: Shift(double x, double y) {
	Figure2D :: Shift(x, y);
	center.Shift (x,y);
}

void Circle :: Scale ( double k1, double k2) {
	Figure2D :: Scale (k1, k2);
	center.MoveTo (Figure2D :: getX()+ (Figure2D :: getLength() / 2) , Figure2D :: getY() +(Figure2D :: getHeight()/ 2));
	radius = center.getX() - Figure2D :: getX();
}