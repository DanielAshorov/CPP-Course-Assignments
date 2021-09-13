#pragma once
#include <iostream>
using namespace std;

class Polynomial {
	int i;
	friend class Rational;
	friend Polynomial operator * (const double&, const Polynomial&);
public:
	Polynomial(int deg = 0);
	Polynomial(double* arr, int index);
	Polynomial(const Polynomial& index);
	~Polynomial();
	int getDegree(bool flag);
	void setCoeff(int index, double val);
	friend ostream& operator<<(ostream& cout, const Polynomial& index);
	Polynomial& operator = (const Polynomial& i);
	Polynomial operator * (const Polynomial& index);
	Polynomial operator + (const Polynomial& index);
	Polynomial operator - (const Polynomial& index);
	double& operator[](int i);
	static int getMaxDegree();
	static int maximum;
private:
	double* coefficients;
	const int maxDeg;
	int deg;
};