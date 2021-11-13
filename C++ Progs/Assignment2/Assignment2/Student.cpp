//Student.cpp
//Implementation file
//Created by w0440932
//https://www.youtube.com/watch?v=PXcRe-W2w7s was used as reference


#include <iostream>
#include <conio.h>
#include "Student.h"
using namespace std;

Student::Student() { cout << "DEFAULT constructor fired" << endl; } //default constructor
//Student::~Student() {} //default virtual destructor

//constructor taking name
Student::Student(string n, int cap) 
{ 
	cout << "constructor fired" << endl;
	this->name = n; 
	this->capacity = cap;
	this->numCourses = 0;
	this->courseList = new string[this->capacity];
}

//copy constructor
Student::Student(const Student& source) 
{

	cout << "COPY constructor fired" << endl;
	this->name = source.name;
	this->capacity = source.capacity;
	this->numCourses = source.numCourses;
	this->courseList = new string[source.capacity];
	copy(source.courseList, source.courseList + source.numCourses, this->courseList); 
}

//Overloaded assignment operator
Student& Student::operator=(const Student& source)
{

	cout << "overloaded assignment operator fired" << endl;
	//self assignment returns itself
	if (this == &source)
	{
		return *this;
	}
	this->name = source.name;
	this->numCourses = source.numCourses;
	this->courseList = new string[source.capacity];
	copy(source.courseList, source.courseList + source.numCourses, this->courseList);

	return *this;
}

//destructor
Student::~Student() 
{

	cout << "destructor fired" << endl;
	if (this->courseList != NULL)
	{
		delete[] this->courseList;
	}
}

//functions
void Student::setName(string n)
{
	cout << "set name function" << endl;
	this->name = n;
}
void Student::addCourse(string c)
{
	if (numCourses == capacity)
	{
		int tempCap = capacity + 1;
		string* tempList = new string[tempCap];
		
		copy(courseList, courseList + capacity, tempList);
		
		delete[] courseList;
		courseList = tempList;
		capacity = tempCap;
		cout << "array capacity increased" << endl;
	}
	courseList[numCourses] = c;	
	this->numCourses += 1;
	cout << "course added" << endl;

}

ostream& operator<<(ostream& os, const Student& st)
{

	cout << "<< fired" << endl;
	os << "Student name: " << st.name << endl;
	os << "Courses:" << endl;

	for (int i = 0; i < st.numCourses; i++)
	{
		os << st.courseList[i] + "\n";
	}
	return os << endl;
}


//string* Student::getCourses(){}
void Student::resetCourses() 
{
	cout << "RESET fired" << endl;
	if (this->courseList != NULL)
	{
		delete[] this->courseList;
		this->numCourses = 0;
	}
}