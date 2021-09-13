#include "Rectangle.h"

Rectangle :: Rectangle (const char* name, Point x, Point y) : A (x.getX(), y.getY()), B(y.getX(), x.getY()) {
	if (name != NULL) 
		setName (name);
	Figure2D :: Resize (B.getX() - A.getX(), B.getY() - A.getY());
	Figure2D :: MoveTo (A.getX(), A.getY());
}

void Rectangle::Scale(double k1, double k2) {
	Figure2D::Scale(k1, k2);
	B.MoveTo(A.getX() + this->getLength(), A.getY() + this->getHeight());
}

void Rectangle :: Resize (double l , double h) {
	B.Shift(l - this->getLength() , h - this->getHeight() );
	Figure2D :: Resize (l , h);
}

void Rectangle :: Shift (double x , double y) {
	A.MoveTo ( A.getX() + x, A.getY() + y);
	B.MoveTo (A.getX() + this->getLength(), 
		A.getY() + this->getHeight());
	Figure2D :: MoveTo (A.getX() , A.getY());
}

void Rectangle :: print() {
	cout << this->getName() << ": " << "Point" << "(" << A.getX() << ", " << A.getY()
		<< ")" << "-" << "Point" << "(" << B.getX() << ", " << B.getY() << ")" << endl;
}

Rectangle::~Rectangle()
{
}