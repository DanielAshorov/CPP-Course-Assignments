#include "polynomial.h"

int Polynomial :: maximum = 0;
Polynomial :: Polynomial(int index) : maxDeg(index) {
	deg = 0;
	int i;
	coefficients = new double[index + 1];
	for (i = 0; i <= maxDeg; i++)
		coefficients[i] = 0;
}

Polynomial :: Polynomial (double* arr, int index) : maxDeg(index) {
	deg = index;
	int i;
	coefficients = new double[deg + 1];
	for (i = 0; i <= deg; i++)
		coefficients[i] = arr[i];
	while (coefficients[deg] == 0)
		deg = deg -1;
	if (maximum < deg)
		maximum = deg;
}

Polynomial::~Polynomial() {
	delete[] coefficients;
}

Polynomial :: Polynomial (const Polynomial& index) : maxDeg(index.maxDeg) {
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

int Polynomial :: getMaxDegree() {
	return maximum;
}

void Polynomial :: setCoeff(int index, double val) {
	if (deg <= index + 1)
		deg = index;
	coefficients[index] = val;
	if (maximum < deg)
		maximum = deg;
}

int Polynomial :: getDegree(bool flag) {
	if (!flag)
		return maxDeg;
	return deg;
}

Polynomial Polynomial :: operator + (const Polynomial& index) {
	int size, i;
	if (deg < index.deg)
		size = index.deg;
	else 
		size = deg;
	Polynomial polynom(size);
	for (i = 0; i <= size; i++) {
		if ((i <= deg) && (i <= index.deg))
			polynom.coefficients[i] = (coefficients[i] + index.coefficients[i]);
		else
			if (i <= deg)
				polynom.coefficients[i] = coefficients[i];
			else
				polynom.coefficients[i] = index.coefficients[i];
	}
	polynom.deg = size;
	while (polynom.coefficients[polynom.deg] == 0)
		polynom.deg = polynom.deg - 1;
	return polynom;
}

Polynomial Polynomial :: operator * (const Polynomial& index) {
	int i, j;
	Polynomial r (deg + index.deg);
	for (i = 0; i <= deg; i++) {
		for (j = 0; j <= index.deg; j++)
			r.coefficients[i + j] = r.coefficients[i + j] + (coefficients[i] * index.coefficients[j]);
	}
	r.deg = r.maxDeg;
	while (r.coefficients[r.deg] == 0)
		r.deg = r.deg - 1;
	if (maximum < r.deg)
		maximum = r.deg;
	return r;
}

Polynomial Polynomial :: operator - (const Polynomial& index) {
	int i, size;
	if (index.deg > deg)
		size = index.deg;
	else
		size = deg;
	Polynomial r(size + 1);
	for (i = 0; i <= size; i++) {
		if ((i <= index.deg) && (i <= deg))
			r.coefficients[i] = (coefficients[i] - index.coefficients[i]);
		else
			if (i <= deg)
				r.coefficients[i] = coefficients[i];
			else
				r.coefficients[i] = index.coefficients[i];
	}
	r.deg = size;
	while (r.coefficients[r.deg] == 0)
		r.deg = r.deg - 1;
	if (maximum < deg)
		maximum = deg;
	return r;
}


Polynomial& Polynomial :: operator = (const Polynomial& index) {
	deg = index.deg;
	int i;
	delete[] coefficients;
	coefficients = new double [deg + 1];
	for (i = 0; i <= deg; i++) { 
		coefficients[i] = index.coefficients[i]; 
	}
	if (maximum < deg)
		maximum = deg;
	return *this;
}

double& Polynomial :: operator[] (const int i)
{
	return this->coefficients[i];
}

Polynomial operator * (const double& value, const Polynomial& index) {
	Polynomial polynom(index.deg);
	int i;
	if (value == 0) {
		polynom.deg = 0;
		return polynom;
	}
	for (i = 0; i <= index.deg; i++)
		polynom.coefficients[i] = value * index.coefficients[i];
	polynom.deg = polynom.maxDeg;
	while (polynom.coefficients [polynom.deg] == 0)
		polynom.deg = polynom.deg - 1;
	return polynom;
}

ostream& operator<<(ostream& cout, const Polynomial& index) {
	int val = 0, i;
	cout << "polynomial = ";
	for (i = 0; i <= index.maxDeg; i++)
		if (index.coefficients[i] != 0)
			val = 1;
	if (val == 0) {
		cout << "0" << endl; return cout;
	}
	cout << index.coefficients[0];
	for (i = 1; i <= index.deg; i++)
		cout << "+" << "(" << index.coefficients[i] << ")" << "*" << "X^" << i;
	cout << endl;
	return cout;
}