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
    Checkings();
    Checkings(Checkings &obj); // <Tandy> declaring copy contructor for user.cpp line 9 to fix "attempting to reference a deleted function"

    //ACCESSORS (GETTERS):
    double getOverdraft();
};

#endif // CHECKINGS_H
