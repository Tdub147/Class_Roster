#include "networkStudent.h"

NetworkStudent::NetworkStudent()
{
	Student _;
	this->student = _;
}

NetworkStudent::~NetworkStudent()
{
	student.~Student();
	degree = UNKNOWN;
}

NetworkStudent::NetworkStudent(Student student)
{
	this->student = student;
}

Degree NetworkStudent::getDegreeProgram()
{
	return degree;
}

Student NetworkStudent::getStudent() const
{
	return student;
}

void NetworkStudent::setStudent(Student student)
{
	this->student = student;
}