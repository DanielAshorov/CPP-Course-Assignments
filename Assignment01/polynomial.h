#pragma once
#include <iostream>

using namespace std;
class Polynomial {
	int i;
public:
	Polynomial(int deg = 0);
	Polynomial(double* arr, int index);
	Polynomial(const Polynomial& index);
	~Polynomial();
	static int maximum;
	void setCoeff(int index, double val);
	int getDegree(bool flag);
	static int getMaxDegree();
	friend ostream& operator<<(ostream& out, const Polynomial& index);
private:
	double* coefficients;
	const int maxDeg;
	int deg;
};