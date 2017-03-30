#include "User.h"

//CONSTRUCTORS:
User::User()
{

}

User::User(Checkings& checkings, Savings& savings)
{
    myCheckings = &checkings;
    mySavings = &savings;
    name = "Firstname Lastname";
}

//ACCESSORS (GETTERS):
//User
QString User::getName() const
{
    return name;
}

//Checkings
int User::getCheckingsAcc()
{
    return myCheckings->getAccountNumber();
}

double User::getCheckingsAmount()
{
    return myCheckings->getAmount();
}

double User::getCheckingsOverdraft()
{
    return myCheckings->getOverdraft();
}

//Savings
int User::getSavingsAcc()
{
    return mySavings->getAccountNumber();
}

double User::getSavingsAmount()
{
    return mySavings->getAmount();
}

double User::getSavingsInterest()
{
    return mySavings->getInterest();
}

//MUTATORS (SETTERS):
//User
void User::setName(const QString &string)
{
    name = string;
}

//Checkings
void User::setCheckings(Checkings& checkings)
{
    myCheckings = &checkings;
}

//Savings
void User::setSavings(Savings& Savings)
{
    mySavings = &Savings;
}

//VOID FUNCTIONS:
void User::openTransactions(){}
void User::transferFunds(){}
