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
    Savings(const Savings& );

    //ACCESSORS (GETTERS):
    double getInterest();

    //MUTATORS (SETTERS):
    void setInterest(double);

    //validator
    char validator(double);
};

#endif // SAVINGS_H
