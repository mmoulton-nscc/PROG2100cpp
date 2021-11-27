#include "RationalNumber.h"


//constructors

//default
RationalNumber::RationalNumber()
{
	cout << "Defaut constructor fired" << endl;
	numerator = 0;
	denominator = 1;
	fractionifiy();
}

//whole number
RationalNumber::RationalNumber(int nume)
{
	cout << "Int constructor fired" << endl;
	numerator = nume;
	denominator = 1;
	fractionifiy();

}

//two ints
RationalNumber::RationalNumber(int nume , int denom)
{
	cout << "int int constructor fired" << endl;
	numerator = nume;
	denominator = denom;
	fractionifiy();
}

//string
RationalNumber::RationalNumber(string number)
{
	cout << "String constructor fired" << endl;

	//https://www.rexegg.com/regex-quickstart.html
	regex rex("-?[0-9]+|-?[0-9]+/?[0-9]+");
	//check if its a valid fraction or whole number
	if (regex_match(number, rex))
	{
		//splits x/x into two numbers
		if (number.find("/") != string::npos)
		{
			stringstream numsStr(number);
			string num;
			vector<string> numList;

			while (getline(numsStr, num, '/'))
			{
				numList.push_back(num);
			}

			numerator = stoi(numList[0]);
			denominator = stoi(numList[1]);

		}
		//or if there's no / takes the whole number
		else
		{
			numerator = stoi(number);
			denominator = 1;
		}
	}
	else
	{
		//set to error output type
		numerator = 0;
		denominator = 0;
	}
	

	fractionifiy();

}


//methods
void RationalNumber::setNumbers(int nume, int denom)
{
	//alters the rational number after it exists
	numerator = nume;
	denominator = denom;
	fractionifiy();
}

void RationalNumber::fractionifiy()
{
	//sets string fraction
	fraction = to_string(numerator) + "/" + to_string(denominator);
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

////https://stackoverflow.com/questions/9435385/split-a-string-using-c11
//vector<string> RationalNumber::split(const string& input)
//{
//	// passing -1 as the submatch index parameter performs splitting
//	regex rex("/");
//	sregex_token_iterator first{ input.begin(), input.end(), rex, -1 }, last;
//	return { first, last };
//}


//overloaded operators

RationalNumber RationalNumber::operator+(const RationalNumber& b)
{
	cout << "Overloaded operator+ fired" << endl;

	//https://www.mathsisfun.com/fractions_addition.html
	RationalNumber ran;
	
	//a's numerator, b's numerator, a's denominator, b's denominator
	int an, bn, ad, bd;
	an = this->numerator;
	ad = this->denominator;
	bn = b.numerator;
	bd = b.denominator;

	//creates common denom by multiplying them together, then cross multiplies to keep them the same value, then adds numerators and reduces
	int commondenom = ad * bd;
	an = an * bd;
	bn = bn * ad;
	ran.setNumbers(an + bn, commondenom);
	ran.reduceFraction();
	return ran;

}

RationalNumber RationalNumber::operator-(const RationalNumber& b)
{
	cout << "Overloaded operator- fired" << endl;

	RationalNumber ran;

	int an, bn, ad, bd;
	an = this->numerator;
	ad = this->denominator;
	bn = b.numerator;
	bd = b.denominator;

	//creates common denom by multiplying them together, then cross multiplies to keep them the same value, then subtracts numerators and reduces
	int commondenom = ad * bd;
	an = an * bd;
	bn = bn * ad;
	ran.setNumbers(an - bn, commondenom);
	ran.reduceFraction();
	return ran;
}

RationalNumber RationalNumber::operator*(const RationalNumber& b)
{
	cout << "Overloaded operator* fired" << endl;

	//multiplies straight across
	RationalNumber ran;
	ran.setNumbers(this->numerator * b.numerator, this->denominator * b.denominator);
	ran.reduceFraction();
	return ran;
}

RationalNumber RationalNumber::operator/(const RationalNumber& b)
{
	cout << "Overloaded operator/ fired" << endl;

	//flip and multiply after checking for division by 0
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

void RationalNumber::operator=(const RationalNumber& b)
{
	cout << "Overloaded operator= fired" << endl;
	//this = that
	this->setNumbers(b.numerator, b.denominator);
	this->reduceFraction();
}

void RationalNumber::operator+=(const RationalNumber& b)
{
	cout << "Overloaded operator+= fired" << endl;

	//this = this+that
	RationalNumber ran;

	//a's numerator, b's numerator, a's denominator, b's denominator
	int an, bn, ad, bd;
	an = this->numerator;
	ad = this->denominator;
	bn = b.numerator;
	bd = b.denominator;

	//creates common denom by multiplying them together, then cross multiplies to keep them the same value, then adds numerators and reduces
	int commondenom = ad * bd;
	an = an * bd;
	bn = bn * ad;
	this->setNumbers(an + bn, commondenom);
	this->reduceFraction();
}


bool RationalNumber::operator>(const RationalNumber& b)
{
	cout << "Overloaded operator> fired" << endl;

	//compare decimals because lazy
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
	cout << "Overloaded operator< fired" << endl;

	//compare decimals because lazy
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
	cout << "Overloaded operator== fired" << endl;

	//compare decimals because lazy
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
	cout << "Overloaded operator<< fired" << endl;
	//build output stream
	if (a.fraction == "0/0")
	{
		os << "Not a valid fraction - check input and try again" << endl;
		return os << endl;
	}
	os << a.fraction << endl;
	return os << endl;
}