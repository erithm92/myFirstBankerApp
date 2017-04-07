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
Checkings User::getCheckings()
{
    return *myCheckings;
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
Savings User::getSavings()
{
    return *mySavings;
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
void transferFunds(Account source, Account destination, double funds) // <Tandy> transfer funds from source to destination, for TransferWindow
{
    /*
     * if(source.id = 1) // id 1 for check 2 for save 0 for null
     * source.overdraftcheck
     * else
     * source.normale check
     */
    if(source.validator(funds) != 'F')
    {
        source.setAmount(source.getAmount() - funds); // <Tandy> set source amount to its current amount, minus the funds transferred;
        // source amount will decrease

        if(source.validator(funds) == 'O')
        { // <Tandy> check for overdraft
            source.setAmount(source.getAmount() - 35); // apply extra $35 fee
        }

        destination.setAmount(destination.getAmount() + funds); // <Tandy> set destination amount to its current amount, plus the funds transferred;
        // destination amount will increase
    }
    else
    {
        //display error?
    }
}

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
