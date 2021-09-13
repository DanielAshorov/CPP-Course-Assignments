#pragma once
#include <iostream>
#include "polynomial.h"

using namespace std;
class Rational {
public:
	Rational();
	void print();
	friend ostream& operator<<(ostream& cout, const Rational& index);
	Rational(const Polynomial& index, const Polynomial& val);
	~Rational();
	Polynomial getNom();
	Polynomial getDenom();
private:
	Polynomial Nom;
	Polynomial Denom;
};