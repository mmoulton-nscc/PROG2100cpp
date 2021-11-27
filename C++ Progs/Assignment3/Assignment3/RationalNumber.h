#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <regex>
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
	int getNumerator();
	int getDenominator();
	string getFraction();
	void reduceFraction();
	string reduceFraction(int nume, int denom);
	//vector<string> split(const string& input);


	//overloaded operators
	RationalNumber operator+(const RationalNumber& b);
	RationalNumber operator-(const RationalNumber& b);
	RationalNumber operator*(const RationalNumber& b);
	RationalNumber operator/(const RationalNumber& b);
	void operator=(const RationalNumber& b);
	void operator+=(const RationalNumber& b);

	bool operator>(const RationalNumber& b);
	bool operator<(const RationalNumber& b);
	bool operator==(const RationalNumber& b);

	friend ostream& operator<<(ostream& os, const RationalNumber& a);

};
#endif