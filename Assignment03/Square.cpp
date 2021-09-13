#include "Square.h"

bool Square :: isInside (Figure2D* P) {
	double x;
	if (this->getLength() < this->getHeight())
		x = this->getLength();
	else
		x = this->getHeight();
	if ((P->getX() >= A.getX() - (x / 2)) && (P->getX() <= A.getX() + (x / 2)))
		if (P->getY() >= A.getY() - (x / 2) && (P->getY() <= A.getY() + (x / 2)))
			return 1;
	return 0;
}

Square :: Square (const char* name, Point z, float x): Figure2D (x , x , z.getX() , z.getY()) , A (z.getX() + (x/2), z.getY() + (x/2)) {
	setName(name);
}

void Square::Resize(double l, double h) {
	A.Shift(((l - this->getLength()) / 2), 
	((h - this->getHeight()) / 2));
	Figure2D :: Resize (l , h);
}

void Square :: Shift(double x, double y) {
	Figure2D :: Shift(x, y);
	A.Shift (x, y);
}

double Square ::Perimeter() {
	if (this->getLength() < this->getHeight())
		return this->getLength() * 4;
	else
		return this->getHeight() * 4;
}

void Square :: Scale(double k1, double k2) {
	Figure2D :: Scale(k1, k2);
	A.MoveTo (Figure2D :: getX() + ( this->getLength()/ 2), 
	Figure2D :: getY() + (this->getHeight()/ 2));
}

double Square :: Area() {
	if (this->getLength() < this->getHeight())
		return this->getLength() * this->getLength();
	else
		return this->getHeight() * this->getHeight();
}

Square& Square :: operator= (const Square& tmp) {
	this->setName (tmp.getName());
	this->A.MoveTo (tmp.A.getX() , tmp.A.getY());
	this->MoveTo (tmp.getX() , tmp.getY());
	Figure2D :: Resize (tmp.getLength() , tmp.getHeight());
	return *this;
}

Square :: Square (Square& z) {
	this->setName (z.getName());
	this->A.MoveTo (z.A.getX() , z.A.getY());
	Figure2D :: MoveTo (z.getX() , z.getY());
	Figure2D :: Resize (z.getLength() , z.getHeight());
}

Square :: ~Square()
{
}

Square::Square() :Figure2D(), A()
{
}

Square :: Square (const char* name , Point x, Point y) : A( ((x.getX() + y.getX())/2) , ((y.getY() + x.getY())/2) ) {
	if (name != NULL) {
		setName(name);
	}
	if (x.getY() > y.getY()) {
		Figure2D::MoveTo(x.getX(), y.getY());
		Figure2D::Resize(y.getX() - x.getX(), x.getY() - y.getY());
	}
	else {
		Figure2D::MoveTo(x.getX(), x.getY());
		Figure2D::Resize(y.getX() - x.getX(), y.getY() - x.getY());
	}
}
ostream& operator<< (ostream& cout, Square& b) {
	b.print();
	return cout;
}

void Square :: print() {
	double side;
	if (this->getLength() < this->getHeight())
		side = this->getLength();
	else
		side = this->getHeight();
	cout << "Square " << this->getName() << " with center" << " (" << A.getX() << ", "
		<< A.getY() << ") " << "and side = " << side << endl;
}