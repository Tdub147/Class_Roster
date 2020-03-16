#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include "student.h"
using namespace std;
class SoftwareStudent : public Student
{
public:
	SoftwareStudent();
	~SoftwareStudent();

private:

};

#endif


//#ifndef SOFTWARESTUDENT_H
//#define SOFTWARESTUDENT_H
//#include "degree.h"
//#include "student.h"
//class SoftwareStudent : public Student {
//public:
//	//Default Constructor
//	SoftwareStudent();
//	//Overloaded constructor
//	SoftwareStudent(string& studentID, string& firstName, string& lastName, string& emailAddress, int& age, DaysInClass numDays, Degree& degreeType);
//	void print();
//	Degree GetDegreeProgram() const;
//private:
//	Degree degreeType;
//};
//#endif