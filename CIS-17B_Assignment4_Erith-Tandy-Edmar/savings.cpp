#include "savings.h"

Savings::Savings()
{
    annualInterest = .02;
    setAmount(100);
}

// <Tandy> defining copy contructor for user.cpp line 10 to fix "attempting to reference a deleted function"
/*Savings::Savings(Savings &obj){
    annualInterest = obj.getInterest();
}*/

double Savings::getInterest()
{
    return annualInterest;
}

void Savings::setInterest(double interest)
{
    annualInterest = interest;
}
