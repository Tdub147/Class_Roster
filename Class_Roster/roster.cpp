// roster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "roster.h"

using namespace std;

Roster::Roster()
{
}
Roster::~Roster()
{
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++)
    {
        classRosterArray[i] = nullptr;
        delete classRosterArray[i];
    }
}

void Roster::printAll()
{
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++)
    {
        int j = i + 1;
        cout << j << "\t";
        classRosterArray[i]->printStudent();
    }
    cout << endl;
}
void Roster::printInvalidEmails()
{
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++)
    {
        string email = classRosterArray[i]->getEmailAddress();
        if (email.find(" ") != string::npos)
        {
            cout << email << endl;
        }
        else if (email.find("@") == string::npos || email.find(".") == string::npos)
        {
            cout << email << endl;
        }
    }
    cout << endl;
}
void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            int days[3];
            memcpy(days, classRosterArray[i]->getNumDaysToCompl(), sizeof(days));
            double ave = 0;
            for (int j = 0; j < 3; j++)
            {
                ave += days[j];
            }
            ave = ave / 3.0;
            cout << setprecision(3) <<"Average days in course for studentID: '" << studentID << "' = " << ave << endl << endl;

        }
    }
}
void Roster::printByDegreeProgram(Degree degree)
{

}
void Roster::add(Student *student)
{
    int i = 0;
    while(classRosterArray[i] != NULL)
    {
        i++;
    }
    classRosterArray[i] = student;
}
void Roster::remove(Student student)
{

}
void Roster::remove(string studentID)
{
    bool found = false;
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++)
    {
        bool empty = classRosterArray[i] == NULL;
        if (classRosterArray[i] != NULL && classRosterArray[i]->getStudentID() == studentID)
        {
            classRosterArray[i] = nullptr;
            delete classRosterArray[i];
            found = true;
            cout << "Student with studentID: '" << studentID << "' was removed from the class roster array." << endl << endl;
        }
    }
    if (!found)
    {
        cout << "A student with studentID: '" << studentID << "' was not found." << endl << endl;
    }
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
    Roster classRoster;

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
        string s = studentAtts[8];
        Degree x = degreeMap()[studentAtts[8]];
        switch (degreeMap()[studentAtts[8]])
        {
        case NETWORK:
        {
            /*NetworkStudent networkStudent{ student };
            classRoster.add(networkStudent.getStudent());*/
            NetworkStudent* ns = new NetworkStudent (student);
            Student* student = new Student(ns->getStudent());
            classRoster.add(student);
            break;
        }
        case SECURITY:
        {
            /*SecurityStudent securityStudent{ student };
            classRoster.add(securityStudent.getStudent());*/
            SecurityStudent* secS = new SecurityStudent(student);
            Student* student = new Student(secS->getStudent());
            classRoster.add(student);
            break;
        }
        case SOFTWARE:
        {
            /*SoftwareStudent softwareStudent{ student };
            classRoster.add(softwareStudent.getStudent());*/
            SoftwareStudent* sofS = new SoftwareStudent(student);
            Student* student = new Student(sofS->getStudent());
            classRoster.add(student);
            break;
        }
        default:
            break;
        }
    }

    cout << "Couse Title: Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 001284276" << endl;
    cout << "Name: Tyler Williams" << endl << endl;

    classRoster.printAll();
    classRoster.printInvalidEmails();
    classRoster.printAverageDaysInCourse("A5");
    classRoster.remove("A3");
    classRoster.remove("A3");
    classRoster.~Roster();

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
