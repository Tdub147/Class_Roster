#ifndef DEGREE_H
#define DEGREE_H
#include <string>
#include <map>
using namespace std;
enum Degree : short { UNKNOWN = NULL, NETWORK = 1, SECURITY = 2, SOFTWARE = 3 };
struct degreeMap : public map<std::string, Degree>
{
    degreeMap()
    {
        this->operator[]("NETWORK") = NETWORK;
        this->operator[]("SECURITY") = SECURITY;
        this->operator[]("SOFTWARE") = SOFTWARE;
    };
    ~degreeMap() {}
};
#endif