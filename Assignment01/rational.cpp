#include "rational.h"

ostream& operator<<(ostream& out, const Rational& index) {
	cout << "" << index.Nom;
	cout << "--------------------------" << endl;
	cout << index.Denom;
	return out;
}

Rational::Rational() {
	Nom.setCoeff(0, 0);
	Denom.setCoeff(0, 1);
}

void Rational::print() {
	cout << Nom;
	cout << "--------------------------" << endl;
	cout << Denom;
}

Rational::Rational(const Polynomial& index, const Polynomial& val) : Nom(index), Denom(val)
{
}

Rational::~Rational()
{
}

Polynomial Rational::getNom() {
	return Nom;
}

Polynomial Rational::getDenom() {
	return Denom;
}