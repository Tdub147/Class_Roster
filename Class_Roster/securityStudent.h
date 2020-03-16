#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include "student.h"
using namespace std;
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