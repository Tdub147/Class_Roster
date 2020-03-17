#ifndef ROSTER_H
#define ROSTER_H
using namespace std;

#include <iostream>
#include <string>
#include <array>
#include <iomanip>;
#include "roster.h"
#include "student.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "degree.h"

class Roster
{
public:
	Roster();
	~Roster();

	void printAll();
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(Degree degree);
	void add(Student *student);
	void remove(Student student);
	void remove(string studentID);
	
private:
	Student* classRosterArray[5] = { nullptr };
};
#endif