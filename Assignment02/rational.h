#pragma once
#include <iostream>
#include <ostream>
#include "polynomial.h"

using namespace std;
class rational {
public:
	rational(const rational& index);
	rational& operator = (const rational& i);
	rational operator * (const rational& i);
	rational operator + (const rational& i);
	rational();
	void print();
	friend ostream& operator<<(ostream& cout, const rational& index);
	rational(const Polynomial& index, const Polynomial& val);
	~rational();
	Polynomial getNom();
	Polynomial getDenom();
private:
	Polynomial Nom;
	Polynomial Denom;
};