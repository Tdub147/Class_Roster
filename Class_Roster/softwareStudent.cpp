#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent()
{
	Student _;
	this->student = _;
}

SoftwareStudent::~SoftwareStudent()
{
	student.~Student();
	degree = UNKNOWN;
}

SoftwareStudent::SoftwareStudent(Student student)
{
	this->student = student;
}

Degree SoftwareStudent::getDegreeProgram()
{
	return degree;
}

Student SoftwareStudent::getStudent() const
{
	return student;
}

void SoftwareStudent::setStudent(Student student)
{
	this->student = student;
}