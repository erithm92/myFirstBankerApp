#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class Savings : public Account
{
private:
    //DATA:
    double annualInterest;

public:
    //CONSTRUCTORS:
    Savings();

    //ACCESSORS (GETTERS):
    double getInterest();

    //MUTATORS (SETTERS):
    void setInterest(double);
};

#endif // SAVINGS_H
