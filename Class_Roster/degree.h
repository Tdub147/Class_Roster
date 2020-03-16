#ifndef DEGREE_H
#define DEGREE_H
#include <string>
#include <map>
using namespace std;
enum Degree : short { UNKNOWN = NULL, NETWORKING = 0, SECURITY = 1, SOFTWARE = 2 };
enum responseHeaders
{
    CONTENT_ENCODING,
    CONTENT_LENGTH,
    TRANSFER_ENCODING,
};


struct degreeMap : public map<std::string, Degree>
{
    degreeMap()
    {
        this->operator[]("NETWORKING") = NETWORKING;
        this->operator[]("SECURITY") = SECURITY;
        this->operator[]("SOFTWARE") = SOFTWARE;
    };
    ~degreeMap() {}
};
#endif