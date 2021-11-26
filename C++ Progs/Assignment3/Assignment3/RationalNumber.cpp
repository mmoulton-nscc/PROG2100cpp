#include "RationalNumber.h"
//constructors
RationalNumber::RationalNumber()
{
	numerator = 0;
	denominator = 1;
	fractionifiy();
}

RationalNumber::RationalNumber(int nume)
{
	numerator = nume;
	denominator = 1;
	fractionifiy();

}

RationalNumber::RationalNumber(int nume , int denom)
{
	numerator = nume;
	denominator = denom;
	fractionifiy();
}


//methods
void RationalNumber::setNumbers(int nume, int denom)
{
	numerator = nume;
	denominator = denom;
	fractionifiy();
}

void RationalNumber::fractionifiy()
{
	fraction = to_string(numerator) + "/" + to_string(denominator);
}

void RationalNumber::updateNumbers()
{
	//numerator = string before /
	//denominator = string after /
}

int RationalNumber::getNumerator()
{
	return numerator;
}

int RationalNumber::getDenominator()
{
	return denominator;
}

string RationalNumber::getFraction()
{
	return fraction;
}


//reduce to lowest common denominator
void RationalNumber::reduceFraction()
{
	int div = gcd(this->numerator, this->denominator); //https://en.cppreference.com/w/cpp/numeric/gcd

	if (div != 0)
	{
		this->setNumbers(this->numerator / div, this->denominator / div);
	}

}

string RationalNumber::reduceFraction(int nume, int denom)
{
	int div = gcd(nume, denom); //https://en.cppreference.com/w/cpp/numeric/gcd

	int newnume, newdenom;

	if (div != 0)
	{
		newnume = nume / div;
		newdenom = denom / div;
		return newnume + "/" + newdenom;
	}
	else
	{
		return nume + "/" + denom;
	}

}

//overloaded operators

RationalNumber RationalNumber::operator+(const RationalNumber& b)
{

	//https://www.mathsisfun.com/fractions_addition.html
	RationalNumber ran;
	
	int an, bn, ad, bd;
	an = this->numerator;
	ad = this->denominator;
	bn = b.numerator;
	bd = b.denominator;

	int commondenom = ad * bd;
	an = an * bd;
	bn = bn * ad;
	ran.setNumbers(an + bn, commondenom);
	ran.reduceFraction();
	return ran;

}

RationalNumber RationalNumber::operator-(const RationalNumber& b)
{
	RationalNumber ran;

	int an, bn, ad, bd;
	an = this->numerator;
	ad = this->denominator;
	bn = b.numerator;
	bd = b.denominator;

	int commondenom = ad * bd;
	an = an * bd;
	bn = bn * ad;
	ran.setNumbers(an - bn, commondenom);
	ran.reduceFraction();
	return ran;
}

RationalNumber RationalNumber::operator*(const RationalNumber& b)
{
	RationalNumber ran;
	ran.setNumbers(this->numerator * b.numerator, this->denominator * b.denominator);
	ran.reduceFraction();
	return ran;
}

RationalNumber RationalNumber::operator/(const RationalNumber& b)
{
	RationalNumber ran;
	if (this->numerator == 0 || b.numerator == 0) //division by 0
	{
		ran.setNumbers(0, 0); //will check and return NaN if fraction = 0/0 at a later point
		return ran;
	}
	ran.setNumbers(this->numerator * b.denominator, this->denominator * b.numerator);
	ran.reduceFraction();
	return ran;
}


bool RationalNumber::operator>(const RationalNumber& b)
{
	if (this->numerator / this->denominator > b.numerator / b.denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool RationalNumber::operator<(const RationalNumber& b)
{
	if (this->numerator / this->denominator < b.numerator / b.denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool RationalNumber::operator==(const RationalNumber& b)
{
	if (this->numerator / this->denominator == b.numerator / b.denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}


ostream& operator<<(ostream& os, const RationalNumber& a)
{
	cout << "<< fired" << endl;
	if (a.fraction == "0/0")
	{
		os << "NaN (divide by 0 error)" << endl;
		return os << endl;
	}
	os << a.fraction << endl;
	return os << endl;
}