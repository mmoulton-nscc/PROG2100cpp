#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

class RationalNumber
{
private:
	//attributes
	int numerator, denominator;
	string fraction;

public:
	//constructors
	RationalNumber();
	RationalNumber(int whole);
	RationalNumber(int nume, int denom);
	RationalNumber(string number);

	//methods
	void setNumbers(int nume, int denom);
	void fractionifiy();
	void updateNumbers();
	int getNumerator();
	int getDenominator();
	string getFraction();
	void reduceFraction();
	string reduceFraction(int nume, int denom);


	//overloaded operators
	RationalNumber operator+(const RationalNumber& b);
	RationalNumber operator-(const RationalNumber& b);
	RationalNumber operator*(const RationalNumber& b);
	RationalNumber operator/(const RationalNumber& b);

	bool operator>(const RationalNumber& b);
	bool operator<(const RationalNumber& b);
	bool operator==(const RationalNumber& b);

	friend ostream& operator<<(ostream& os, const RationalNumber& a);

};
#endif