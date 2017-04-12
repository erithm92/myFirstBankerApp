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

//other
char Savings::validator(double withdraw){ // <Tandy> validate whether withdraw can occur or not
    if (getAmount() - withdraw < 0){
        return 'F';
    }
    else{
        return 'T';
    }
}
