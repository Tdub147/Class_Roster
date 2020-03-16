#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include "student.h"
using namespace std;
class SoftwareStudent : public Student
{
public:
	SoftwareStudent();
	~SoftwareStudent();

	SoftwareStudent(Student student);
	void setStudent(Student student);

	Student getStudent() const;

private:
	Student student;
};
#endif