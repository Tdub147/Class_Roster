// roster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "roster.h"

using namespace std;

// Default constructor
Roster::Roster()
{
}
// Destructor
Roster::~Roster()
{
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++)
    {
        classRosterArray[i] = nullptr;
        delete classRosterArray[i];
    }
}

// Prints first name, last name, age, days in courses, and degree program for all students in classRosterArray
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

// Prints invalid emails. Contains whitespace, does not have '@', or does not have '.'
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

// Prints the average of the days in course for a student of studentID
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

// Prints first name, last name, age, days in courses, and degree for all students in classRosterArray of supplied degree program
void Roster::printByDegreeProgram(Degree degree)
{
    string d = "UNKNOWN";
    switch (degree)
    {
    case NETWORK:
        d = "NETWORK";
        break;
    case SECURITY:
        d = "SECURITY";
        break;
    case SOFTWARE:
        d = "SOFTWARE";
        break;
    default:
        break;
    }
    cout << "All students in the '" << d << "' degree program:" << endl;
    bool atLeastOne = false;
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++)
    {
        if (classRosterArray[i]->getDegreeProgram() == degree)
        {
            atLeastOne = true;
            classRosterArray[i]->printStudent();
            cout << endl;
        }
    }
    if (!atLeastOne)
    {
        cout<< "No students in the " << d << "' degree program";
    }
    cout << endl;
}

// Adds student to classRosterArray
void Roster::add(Student *student)
{
    int i = 0;
    while(classRosterArray[i] != NULL)
    {
        i++;
    }
    classRosterArray[i] = student;
}

// Removes student from classRosterArray by studentID
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

// Main point of entry
int main()
{
    // Change console size to read the outputs --------------------- //
    HWND consoleHandle = GetConsoleWindow();
    RECT rect;
    GetWindowRect(consoleHandle, &rect);
    MoveWindow(consoleHandle, rect.left, rect.top, 1300, 600, true);
    // ------------------------------------------------------------- //

    // Initial data set.
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
            NetworkStudent ns =  NetworkStudent(student);
            Student* student = new Student(ns.getStudent());
            classRoster.add(student);
            break;
        }
        case SECURITY:
        {
            SecurityStudent secS = SecurityStudent(student);
            Student* student = new Student(secS.getStudent());
            classRoster.add(student);
            break;
        }
        case SOFTWARE:
        {
            SoftwareStudent sofS = SoftwareStudent(student);
            Student* student = new Student(sofS.getStudent());
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
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.remove("A3");
    classRoster.~Roster();

    

}
