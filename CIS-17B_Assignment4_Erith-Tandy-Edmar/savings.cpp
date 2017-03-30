#include "Savings.h"

//CONSTRUCTORS:
Savings::Savings()
{
    annualInterest = .02;
    setAmount(100);
}

//ACCESSORS (GETTERS):
double Savings::getInterest()
{
    return annualInterest;
}

//MUTATORS (SETTERS):
void Savings::setInterest(double interest)
{
    annualInterest = interest;
}
