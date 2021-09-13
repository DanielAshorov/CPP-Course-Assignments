#include "Segment.h"

void Segment :: Scale (double k1 , double k2) {
	Figure2D :: Resize (k1 * this->getLength() , k2 * this->getHeight());
	if (direction != 1) {
		A.MoveTo(A.getX(), B.getY() + this->getHeight());
		B.MoveTo(A.getX() + this->getLength(), B.getY());
	}
	else
		B.MoveTo(A.getX() + this->getLength(),
			A.getY() + this->getHeight());
}

double Segment :: Perimeter() {
	double y , x;
	y = pow(A.getY() - B.getY(), 2);
	x = pow(A.getX() - B.getX(), 2);
	return sqrt(y + x);
}

void Segment :: Resize (double l, double h) {
	if (direction != 1) {
		A.Shift(0, h - this->getHeight());
		B.Shift(l - this->getLength(), 0);
	}
	else
		B.Shift(l - this->getLength(), h - this->getHeight());
	Figure2D :: Resize (l, h);
}

void Segment :: Shift (double x, double y) {
	Figure2D :: Shift (x, y);
	A.MoveTo (A.getX() + x , A.getY() + y);
	B.MoveTo (B.getX() + x , B.getY() + y);
}

double Segment::Area() {
	return 0;
}

Segment::Segment(const char* name, Point x, Point y) : A(x), B(y) {
	Figure2D::Resize(abs(B.getX() - A.getX()), (abs(A.getY() - B.getY())));
	if (name != NULL)
		setName(name);
	if (0 < (B.getY() - A.getY()) / (B.getX() - A.getX())) {
		direction = 1;
		Figure2D::MoveTo(A.getX(), A.getY());
	}
	else {
		direction = 0;
		Figure2D::MoveTo(A.getX(), B.getY());
	}
}


void Segment::print() {
	cout << this->getName() << ": " << "Point" << "(" << A.getX() << ", " << A.getY()
		<< ")" << "-" << "Point" << "(" << B.getX() << ", " << B.getY() << ")" << endl;
}

Segment::~Segment()
{
}