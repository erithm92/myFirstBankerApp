#include "User.h"
#include <iostream>

//CONSTRUCTORS:
User::User()
{
    //showTransaction(-1);
}

User::User(Checkings& checkings, Savings& savings)
{
    myCheckings = &checkings;
    mySavings = &savings;
    name = "Firstname Lastname";
}

//ACCESSORS (GETTERS):
//User

User::User (const User& right)
{
//    Edmar  - copy constructor added for program stability
//      copy construct creates deep copy
//      usefull for inheritance

    myCheckings = right.myCheckings;
    mySavings = right.mySavings;
    name = right.name;
}

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
Checkings * User::getCheckings()
{
    return myCheckings;
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
Savings * User::getSavings()
{
    return mySavings;
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
//<<<<<<< HEAD
//void User::openTransactions(){}
/*
void User::transferFunds(){}

void User::showTransaction(int transactionDateOrID){ // <Tandy> function to display transaction from date or ID int; *may replace openTransactions()
    if(transactionDateOrID == 4){ // <Tandy> int verified to be an ID


        //qSort(transactionsList.begin(), transactionsList.end()); // <Tandy> pass into qSort being and end iterators for the list
        //QList<transaction>::iterator it = qFind(transactionsList.begin(), transactionsList.end(), transactionDateOrID); // <Tandy>;
        // iterator it is assigned the address of the list item (the transaction struct)
       // transaction temp = *it;
        //std::cout << temp.date;
    } // end if
}
*/
