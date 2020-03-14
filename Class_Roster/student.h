#include <string>
#include <array>
#include "degree.h"

using namespace std;
const int NUM_CLASSES = 3;
class Student
{
public:
	Student();
	~Student();

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDaysToCompl[NUM_CLASSES];
	Degree degree;
};

Student::Student()
{
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = -1;
	for(int i = 0; i < NUM_CLASSES; i++)
	{ 
		numDaysToCompl[i] = -1;
	}
	degree = SECURITY;
}

Student::~Student()
{
}