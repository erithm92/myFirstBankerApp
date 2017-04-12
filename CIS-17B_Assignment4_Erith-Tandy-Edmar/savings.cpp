#include "Savings.h"

//CONSTRUCTORS:
Savings::Savings():Account()
{
    annualInterest = .02;
    setAmount(100);
}

Savings::Savings(const Savings& right):Account(right)
{
    this->annualInterest = right.annualInterest;

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
