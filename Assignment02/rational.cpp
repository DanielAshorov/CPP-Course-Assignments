#include "rational.h"

ostream& operator<<(ostream& out, const rational& index) {
	cout << "" << index.Nom;
	cout << "--------------------------" << endl;
	cout << index.Denom;
	return out;
}

rational::rational() {
	Nom.setCoeff(0, 0);
	Denom.setCoeff(0, 1);
}

rational::rational(const rational& i) :Nom(i.Nom), Denom(i.Denom)
{
}

rational rational :: operator * (const rational& i) {
	rational Ch(Nom *i.Nom, Denom * i.Denom);
	return Ch;
}

rational rational :: operator + (const rational& i) {
	Polynomial tmpNom(i.Nom);
	Polynomial tmpDenom(i.Denom);
	rational r1 (tmpNom * Denom + tmpDenom * Nom, tmpDenom * Denom);
	return r1;
}

rational& rational :: operator = (const rational& i) {
	Nom = i.Nom;
	Denom = i.Denom;
	return *this;
}

void rational :: print() {
	cout << Nom;
	cout << "--------------------------" << endl;
	cout << Denom;
}

rational :: rational (const Polynomial& index, const Polynomial& val) : Nom(index), Denom(val)
{
}

rational :: ~rational()
{
}

Polynomial rational :: getNom() {
	return Nom;
}

Polynomial rational :: getDenom() {
	return Denom;
}