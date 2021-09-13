#include "Figure2D.h"

Figure2D :: Figure2D (double l, double h, double x, double y) {
	this->x = x;
	this->y = y;
	length = l;
	height = h;
}

Figure2D :: Figure2D (Figure2D& f) {
	this->y = f.y;
	this->x = f.x;
	this->length = f.length;
	this->height = f.height;
}

Figure2D :: Figure2D() {
	x = y = length = height = 0;
}

Figure2D :: ~Figure2D() {
	if (name != NULL)
		delete[] name;
}

const Figure2D& Figure2D :: operator = (Figure2D& d) {
	height = d.height;
	length = d.length;
	y = d.y;
	x = d.x;
	return *this;
}

void Figure2D :: setName( const char* name) {
	int i;
	this->name= new char[50];
	for (i = 0; ( this->name[i] = name[i]) != '\0'; i++);
}

double Figure2D :: getY() const {
	return y;
}

double Figure2D :: getX() const {
	return x;
}

const char* Figure2D :: getName() const {
	return name;
}

double Figure2D :: getHeight() const {
	return height;
}

double Figure2D :: getLength() const {
	return length;
}

double Figure2D :: Perimeter() {
	return 2 * length + height * 2;
}

double Figure2D :: Area() {
	return height * length;
}

void Figure2D :: MoveTo (double newX , double newY) {
	y = newY;
	x = newX;
}

void Figure2D :: Shift (double dx , double dy) {
	y = y+ dy;
	x = x + dx;
}

void Figure2D :: Scale (double kx, double ky) {
	height = height * ky;
	length = length * kx;
}

void Figure2D :: Resize ( double newL, double newH) {
	height = newH;
	length = newL;
}

bool Figure2D :: isInside (Figure2D* P) {
	if (x + length >= ( P->getX()) && (P->getX() >= x) )
		if ((P->getY() <= y + height) && (P->getY() >= y))
			return 1;
	return 0;
}

ostream& operator<< (ostream& o, Figure2D& d ) {
	cout << d.name << ": x=" << d.x << ", y=" << d.y << ", length=" 
		<< d.length << ", height=" << d.height;
	return o;
}