#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
#include <string>
#include <array>
#include <sstream>
#include "degree.h"

const int NUM_CLASSES = 3;
class Student
{
	public:
		Student();
		~Student();

		Student(string studentID, string firstName, string lastName, string emailAddress, string age, string days1, string days2, string days3);


		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmailAddress(string emailAddress);
		void setAge(int age);
		void setAge(string age);
		void setNumDaysToCompl(int index, int days);
		void setDegree(Degree degree);


		string getStudentID() const;
		string getFirstName() const;
		string getLastName() const;
		string getEmailAddress() const;
		int getAge() const;
		const int* getNumDaysToCompl() const;
		Degree getDegreeProgram() const;

		void printStudentID();
		void printFirstName();
		void printLastName();
		void printEmailAddress();
		void printAge();
		void printDaysInCourse();
		void printDegree();
		void printStudent();

	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int numDaysToCompl[3];
		Degree degree;
	};

#endif

