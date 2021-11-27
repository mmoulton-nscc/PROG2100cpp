// Assignment3.cpp
// Rational Number Calculator
// written by Mark Moulton W0932044;
//
// it's been probably over a decade since I had to deal with fractions so I heavily used resources such as https://www.calculatorsoup.com/calculators/math/fractions.php for math help


#include <iostream>
#include "RationalNumber.h"
using namespace std;


int main()
{
    cout << "Welcome to the big rational number caluclation program" << endl;
    cout << "If at any point you see a 0/0 invalid fraction error, please check your fractions and try again!" << endl;
    RationalNumber ran1;
    RationalNumber ran2(4);
    RationalNumber ran3(4, 12);
    RationalNumber ran4("2");
    RationalNumber ran5("0/2");

    cout << "Default constructor rational:" << endl;
    cout << ran1 << endl;

    cout << "Single int constructor rational:" << endl;
    cout << ran2 << endl;

    cout << "int int constructor rational:" << endl;
    cout << ran3 << endl;

    cout << "String constructor (whole) rational:" << endl;
    cout << ran4 << endl;

    cout << "String constructor (fraction) rational:" << endl;
    cout << ran5 << endl;

    cout << "Addition" << endl;
    cout << ran2 + ran3 << endl;

    cout << "Subtraction" << endl;
    cout << ran2 - ran3 << endl;

    cout << "Multiplication" << endl;
    cout << ran2 * ran3 << endl;

    cout << "Division" << endl;
    cout << ran2 / ran3 << endl;

    cout << "Assignment before" << endl;
    cout << ran1 << endl;
    cout << ran2 << endl;
    ran1 = ran2;
    cout << "Assignment after" << endl;
    cout << ran1 << endl;

    cout << "plusequals:" << endl;
    ran1 += ran2;
    cout << ran1 << endl;

    cout << "ran2 greater than ran3?" << endl;
    cout << (ran2 > ran3 ? "true" : "false") << endl;

    cout << "ran2 less than ran3?" << endl;
    cout << (ran2 < ran3 ? "true" : "false") << endl;

    cout << "ran1 equal to ran2?" << endl;
    cout << (ran1 == ran2 ? "true" : "false") << endl;

}