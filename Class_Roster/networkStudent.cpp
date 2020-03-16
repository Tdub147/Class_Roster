#include "networkStudent.h"

NetworkStudent::NetworkStudent()
{
	Student _;
	this->student = _;
	student.setDegree(NETWORK);
}

NetworkStudent::~NetworkStudent()
{
	student.~Student();
}

NetworkStudent::NetworkStudent(Student student)
{
	this->student = student;
	this->student.setDegree(NETWORK);
}

Student NetworkStudent::getStudent() const
{
	return student;
}

void NetworkStudent::setStudent(Student student)
{
	this->student = student;
	this->student.setDegree(NETWORK);
}