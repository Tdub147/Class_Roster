#include "student.h"


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

// Deconstructor
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


Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysToCompl[NUM_CLASSES], Degree degree)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < NUM_CLASSES; i++)
	{
		this->numDaysToCompl[i] = numDaysToCompl[i];
	}
	this->degree = degree;
}

void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
	return;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
	return;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
	return;
}

void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
	return;
}

void Student::SetAge(string age) {
	stringstream ageStream(age);
	int _age = NULL;
	ageStream >> _age;
	this->age = _age;
	return;
}

void Student::SetAge(int age) {
	this->age = age;
	return;
}

void Student::SetNumDaysToCompl(int index, int days)
{
	this->numDaysToCompl[index] = days;
	return;
}

void Student::SetDegree(Degree degree)
{
	this->degree = degree;
	return;
}

string Student::GetStudentID() const
{
	return studentID;
}

string Student::GetFirstName() const
{
	return firstName;
}

string Student::GetLastName() const
{
	return lastName;
}

string Student::GetEmailAddress() const
{
	return emailAddress;
}

int Student::GetAge() const
{
	return age;
}

const int* Student::GetNumDaysToCompl() const
{
	return numDaysToCompl;
}

Degree Student::GetDegree() const
{
	return degree;
}