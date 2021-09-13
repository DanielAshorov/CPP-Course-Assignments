#include "polynomial.h"

int Polynomial::maximum = 0;
Polynomial::Polynomial(int index) : maxDeg(index) {
	deg = 0;
	int i;
	coefficients = new double[index + 1];
	for (i = 0; i <= maxDeg; i++)
		coefficients[i] = 0;
}

Polynomial::Polynomial(double* arr, int index) : maxDeg(index) {
	deg = index;
	int i;
	coefficients = new double[deg + 1];
	for (i = 0; i <= deg; i++)
		coefficients[i] = arr[i];
	if (maximum < deg)
		maximum = deg;
}

Polynomial::~Polynomial() {
	delete[] coefficients;
}

Polynomial::Polynomial(const Polynomial& index) : maxDeg(index.maxDeg) {
	int size = index.maxDeg, i;
	deg = index.deg;
	coefficients = new double[size + 1];
	for (i = 0; i <= deg; i++)
		coefficients[i] = index.coefficients[i];
	while (i <= maxDeg) {
		coefficients[i] = 0;
		i++;
	}
}

int Polynomial::getMaxDegree() {
	return maximum;
}

void Polynomial::setCoeff(int index, double val) {
	if (deg <= index + 1)
		deg = index;
	coefficients[index] = val;
	if (maximum < deg)
		maximum = deg;
}

int Polynomial::getDegree(bool flag) {
	if (!flag)
		return maxDeg;
	return deg;
}

ostream& operator<<(ostream& cout, const Polynomial& index) {
	int val = 0, i;
	cout << "polynomial = ";
	for (i = 0; i<=index.maxDeg; i++)
		if (index.coefficients[i] != 0)
			val = 1;
	if (val == 0) {
		cout << "0" << endl; return cout;
	}
	cout << index.coefficients[0];
	for (i = 1; i <= index.deg; i++)
		cout << "+" << index.coefficients[i] << "X^" << i; 
	cout << endl;
	return cout;
}