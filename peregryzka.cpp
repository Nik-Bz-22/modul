#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class ComplexClass
{
private:
	double real;
	double imagin;
public:
	ComplexClass(): real(0), imagin(0){}
	ComplexClass(double, double);
	ComplexClass(const ComplexClass& item);

	double getReal();
	void setReal(double);

	double getImagin();
	void setImagin(double);

	void input();

	void print();

	double moduls();

	ComplexClass operator+(const ComplexClass&);

	ComplexClass operator-(const ComplexClass&);

	ComplexClass operator*(const ComplexClass&);

	ComplexClass operator/(ComplexClass&);

	friend istream& operator>>(istream& is, ComplexClass&);

	friend ostream& operator<<(ostream& os, const ComplexClass&);

	ComplexClass operator-();

	ComplexClass operator/(int);


		
};

