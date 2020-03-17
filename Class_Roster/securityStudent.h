#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
using namespace std;
#include "student.h"
class SecurityStudent : public Student
{
public:
	SecurityStudent();
	~SecurityStudent();

	SecurityStudent(Student student);
	void setStudent(Student student);

	Student getStudent() const;


private:
	Student student;
};
#endif