#include "Savings.h"

//CONSTRUCTORS:
Savings::Savings()
{
    annualInterest = .02;
    this->setAmount(100);
}

Savings::Savings(const Savings& right)
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
bool Savings::withdrawl(double amt)
{
    if(this->getAmount() - amt < 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Not enough funds!");
        msgBox.exec();
        return false;
    }
    else
    {
        this->setAmount(this->getAmount()-amt);
        return true;
    }
}
