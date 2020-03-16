#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <array>
#include <sstream>
#include "degree.h"

using namespace std;
const int NUM_CLASSES = 3;
class Student
{
	public:
		Student();
		~Student();

		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysToCompl[NUM_CLASSES], Degree degree);


		void SetStudentID(string studentID);
		void SetFirstName(string firstName);
		void SetLastName(string lastName);
		void SetEmailAddress(string emailAddress);
		void SetAge(int age);
		void SetAge(string age);
		void SetNumDaysToCompl(int index, int days);
		void SetDegree(Degree degree);


		string GetStudentID() const;
		string GetFirstName() const;
		string GetLastName() const;
		string GetEmailAddress() const;
		int GetAge() const;
		const int* GetNumDaysToCompl() const;
		Degree GetDegree() const;

	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int numDaysToCompl[NUM_CLASSES];
		Degree degree;
	};

#endif

