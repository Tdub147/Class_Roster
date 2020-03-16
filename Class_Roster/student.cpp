#include "student.h"
#include <iostream>


// default Constructor
Student::Student()
{
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = -1;
	for (int i = 0; i < NUM_CLASSES; i++)
	{
		numDaysToCompl[i] = -1;
	}
	degree = UNKNOWN;
}

// Destructor
Student::~Student()
{
	studentID.clear();
	firstName.clear();
	lastName.clear();
	emailAddress.clear();
	age = NULL;
	for (int i = 0; i < NUM_CLASSES; i++)
	{
		numDaysToCompl[i] = NULL;
	}
	degree = UNKNOWN;
}


Student::Student(string studentID, string firstName, string lastName, string emailAddress, string age, string days1, string days2, string days3)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = stoi(age);
	this->numDaysToCompl[0] = stoi(days1);
	this->numDaysToCompl[1] = stoi(days2);
	this->numDaysToCompl[2] = stoi(days3);
	this->degree = degree;
}

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
	return;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
	return;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
	return;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
	return;
}

void Student::setAge(string age) {
	stringstream ageStream(age);
	int _age = NULL;
	ageStream >> _age;
	this->age = _age;
	return;
}

void Student::setAge(int age) {
	this->age = age;
	return;
}

void Student::setNumDaysToCompl(int index, int days)
{
	this->numDaysToCompl[index] = days;
	return;
}

void Student::setDegree(Degree degree)
{
	this->degree = degree;
	return;
}

string Student::getStudentID() const
{
	return studentID;
}

string Student::getFirstName() const
{
	return firstName;
}

string Student::getLastName() const
{
	return lastName;
}

string Student::getEmailAddress() const
{
	return emailAddress;
}

int Student::getAge() const
{
	return age;
}

const int* Student::getNumDaysToCompl() const
{
	return numDaysToCompl;
}

Degree Student::getDegreeProgram() const
{
	return degree;
}

void Student::printStudentID()
{
	cout << "student ID: " << studentID;
	return;
}

void Student::printFirstName()
{
	cout << "First Name: " << firstName;
	return;
}

void Student::printLastName()
{
	cout << "Last Name: " << lastName;
	return;
}

void Student::printEmailAddress()
{
	cout << "Email Address: " << emailAddress;
	return;
}

void Student::printAge()
{
	cout << "Age: " << age;
	return;
}

void Student::printDaysInCourse()
{
	string s = "Number of Days to Complete Each Course: {";
	for (int i = 0; i < NUM_CLASSES; i++)
	{
		s += numDaysToCompl[i] + ",";
	}
	s.resize(s.size() - 1);
	s += "}";
	cout << s;
	return;
}

void Student::printDegree() 
{
	cout << degree;
}

void Student::printStudent() 
{
	printFirstName();
	cout << "\t";
	printLastName();
	cout << "\t";
	printAge();
	cout << "\t";
	printDaysInCourse();
	cout << "\t";
	printDegree();
	cout << endl;
}
