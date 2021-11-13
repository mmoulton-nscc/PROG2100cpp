// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Created by Mark Moulton W0440932
#include <iostream>
#include "Student.h"
using namespace std;


int main()
{
    string input;
    cout << "Welcome to Assignment 2, please enter a name for Student 1: ";
    getline (cin,input);
    Student st1(input);
    
    while (true)
    {
        cout << "Please enter a new course for this student or Q to quit: ";
        getline(cin, input);
        if (input == "Q")
        {
            break;
        }
        else
        {
            st1.addCourse(input);
        }

    }
    cout << "Student 1's information " << endl;
    cout << st1 << endl;

    cout << "Enter Student 2's name: ";
    getline(cin, input);

    Student st2(st1);

    st2.setName(input);

    cout << "Student 2's information via copy constructor" << endl;
    cout << st2 << endl;

    st1.resetCourses();

    cout << "Student 1's information after reset" << endl;

    cout << st1 << endl;

    cout << "Student 2's information again - an example of a deep copy" << endl;

    cout << st2 << endl;

    Student st3;
    st3 = st2;

    cout << "Student 3's information" << endl;
    cout << st3 << endl;

    st2.resetCourses();
    cout << "Student 2's information again again after reset" << endl;

    cout << st2 << endl;

    cout << "Student 3's information again - another example of a deep copy" << endl;

    cout << st3 << endl;
}
