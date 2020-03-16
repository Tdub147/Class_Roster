// roster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "roster.h"

using namespace std;

Roster::Roster()
{
    Student _;
    this->student = _;
    this->degree = UNKNOWN;
}
Roster::~Roster()
{
    student.~Student();
    degree = UNKNOWN;
}
Roster::Roster(NetworkStudent networkStudent)
{
    student = networkStudent.getStudent();
    degree = networkStudent.getDegreeProgram();
}
Roster::Roster(SecurityStudent securityStudent) 
{
    student = securityStudent.getStudent();
    degree = securityStudent.getDegreeProgram();
}
Roster::Roster(SoftwareStudent softwareStudent)
{
    student = softwareStudent.getStudent();
    degree = softwareStudent.getDegreeProgram();
}


int main()
{

    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Tyler,Williams,twi1506@wgu.edu,28,8,30,60,SOFTWARE" };
    const size_t NUM_OF_STUDENTS = sizeof(studentData)/sizeof(studentData[0]);
    Roster* classRosterArray[NUM_OF_STUDENTS];

    for (size_t i = 0; i < NUM_OF_STUDENTS; i++)
    {
        stringstream studentStream(studentData[i]);
        string studentAtts[9];
        string token;
        int j = 0;
        while (getline(studentStream, token, ','))
        {
            studentAtts[j] = token;
            j++;
        }
        Student student{ studentAtts[0], studentAtts[1], studentAtts[2], studentAtts[3], studentAtts[4], studentAtts[5], studentAtts[6], studentAtts[7] };
        switch (degreeMap()[studentAtts[8]])
        {
        case NETWORKING:
        {
            NetworkStudent networkStudent{ student };
            Roster roster{ networkStudent };
            classRosterArray[i] = &roster;
            break;
        }
        case SECURITY:
        {
            SecurityStudent securityStudent{ student };
            Roster roster{ securityStudent };
            classRosterArray[i] = &roster;
            break;
        }
        case SOFTWARE:
        {
            SoftwareStudent softwareStudent{ student };
            Roster roster{ softwareStudent };
            classRosterArray[i] = &roster;
            break;
        }
        default:
            break;
        }
    }

    cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
