#ifndef ROSTER_H
#define ROSTER_H
using namespace std;

#include <iostream>
#include <string>
#include <array>
#include "roster.h"
#include "student.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "degree.h"

class Roster : public Student
{
public:
	Roster();
	~Roster();
	Roster(NetworkStudent networkStudent);
	Roster(SecurityStudent securityStudent);
	Roster(SoftwareStudent softwareStudent);

private:
	Student student;
	Degree degree;
};

#endif