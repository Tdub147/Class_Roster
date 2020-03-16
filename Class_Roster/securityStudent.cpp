#include "securityStudent.h"

SecurityStudent::SecurityStudent()
{
	Student _;
	student = _;
	this->student.setDegree(SECURITY);
}

SecurityStudent::~SecurityStudent()
{
	student.~Student();
}

SecurityStudent::SecurityStudent(Student student)
{
	this->student = student;
	this->student.setDegree(SECURITY);
}


Student SecurityStudent::getStudent() const
{
	return student;
}

void SecurityStudent::setStudent(Student student)
{
	this->student = student;
	this->student.setDegree(SECURITY);
}