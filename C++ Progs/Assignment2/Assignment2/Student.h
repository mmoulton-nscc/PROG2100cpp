//Student header file
//Contains student class with big 3
//Created by W0440932
//https://www.youtube.com/watch?v=PXcRe-W2w7s was used as reference

#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student
{
	friend ostream& operator<<(ostream& os, const Student& st);

private:
	string name;
	int capacity;
	int numCourses;
	string* courseList;

public:
	Student(void);//default constructor
	//virtual ~Student(void);//virtual deconstructor

	static const int DEFAULT_CAPACITY = 3;
	
    //constructor taking name
	Student(string n, int cap = DEFAULT_CAPACITY); 
	
	//copy constructor
	Student(const Student& source); 
	
	//overloaded assignment
	Student& operator=(const Student& source); 
	
	//destructor
	~Student();

	//functions
	void setName(string);
	void addCourse(string);
	//string* getCourses();
	void resetCourses();



};
#endif // !STUDENT_H
