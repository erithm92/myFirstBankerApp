#ifndef CHECKINGS_H
#define CHECKINGS_H

#include "Account.h"

class Checkings : public Account
{
private:
    //DATA:
    double overdraftFee;

public:
    //CONSTRUCTORS:
    Checkings();//<- this is the default constructor
    Checkings(Checkings &obj); // <Tandy> declaring copy contructor for user.cpp line 9 to fix "attempting to reference a deleted function"

    //ACCESSORS (GETTERS):
    double getOverdraft();

    //validator
    bool withdrawl(double);

};

#endif // CHECKINGS_H
