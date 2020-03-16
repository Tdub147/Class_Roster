#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include "student.h"
using namespace std;
class NetworkStudent : public Student
{
public:
	NetworkStudent();
	~NetworkStudent();

	NetworkStudent(Student student);
	void setStudent(Student student);

	Student getStudent() const;

private:
	Student student;
};
#endif
