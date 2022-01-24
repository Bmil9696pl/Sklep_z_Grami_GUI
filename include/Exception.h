#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <iostream>
#include <string>
using namespace std;

class Exception: public exception{
private:
    string wiadomosc;
public:
    Exception(string msg);
    string what();
};

#endif // EXCEPTION_H
