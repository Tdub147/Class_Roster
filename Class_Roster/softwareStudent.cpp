#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent()
{
	Student _;
	this->student = _;
	this->student.setDegree(SECURITY);
}

SoftwareStudent::~SoftwareStudent()
{
	student.~Student();
}

SoftwareStudent::SoftwareStudent(Student student)
{
	this->student = student;
	this->student.setDegree(SECURITY);
}

Student SoftwareStudent::getStudent() const
{
	return student;
}

void SoftwareStudent::setStudent(Student student)
{
	this->student = student;
	this->student.setDegree(SOFTWARE);
}