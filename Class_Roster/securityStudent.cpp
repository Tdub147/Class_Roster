#include "securityStudent.h"

SecurityStudent::SecurityStudent()
{
	Student _;
	student = _;
}

SecurityStudent::~SecurityStudent()
{
	student.~Student();
	degree = UNKNOWN;
}

SecurityStudent::SecurityStudent(Student student)
{
	this->student = student;
}

Degree SecurityStudent::getDegreeProgram()
{
	return degree;
}

Student SecurityStudent::getStudent() const
{
	return student;
}

void SecurityStudent::setStudent(Student student)
{
	this->student = student;
}