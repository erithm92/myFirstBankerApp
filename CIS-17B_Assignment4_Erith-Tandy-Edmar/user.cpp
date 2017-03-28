#include "user.h"

User::User()
{

}
User::User(Checkings& checkings, Savings& savings)
{
    myCheckings = &checkings;
    mySavings = &savings;
    name = "defaultUser";
}

void User::setCheckings(Checkings& checkings)
{
    myCheckings = &checkings;
}
void User::setSavings(Savings& Savings)
{
    mySavings = &Savings;
}
void User::openTransactions(){}
void User::transferFunds(){}
double User::getSavingsAmount()
{
    return mySavings->getAmount();
}
int User::getSavingsAcc()
{
    return mySavings->getAccountNumber();
}
double User::getSavingsInterest()
{
    return mySavings->getInterest();
}
double User::getCheckingsAmount()
{
    return myCheckings->getAmount();
}
int User::getCheckingsAcc()
{
    return myCheckings->getAccountNumber();
}
double User::getCheckingsOverdraft()
{
    return myCheckings->getOverdraft();
}
void User::setName(const QString &string)
{
    name = string;
}

QString User::getName() const
{
    return name;
}

