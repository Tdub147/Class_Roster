#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent()
{
	Student _;
	this->student = _;
	this->student.setDegree(SOFTWARE);
}

SoftwareStudent::~SoftwareStudent()
{
	student.~Student();
}

// Takes a student and sets the degree
SoftwareStudent::SoftwareStudent(Student student)
{
	this->student = student;
	this->student.setDegree(SOFTWARE);
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