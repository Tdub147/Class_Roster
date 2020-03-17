#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
using namespace std;
#include "student.h"
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