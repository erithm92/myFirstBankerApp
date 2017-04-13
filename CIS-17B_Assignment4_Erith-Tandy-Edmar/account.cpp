#include "Account.h"

//DATA:
// why here ?

//int Account::accounts = 0;

//CONSTRUCTORS:
Account::Account()
{   //
    this->amount = 0;
 //   this-> accounts = 0;
    this->accounts++;
    this->accountNumber = accounts;
}

//Edmar copy constructor added
Account::Account(const Account & right)
{
    this->amount = right.amount;
    this->accountNumber = right.accountNumber;
}

//ACCESSORS (GETTERS):
int Account::getAccountNumber(){return accountNumber;}

double Account::getAmount(){return amount;}

//MUTATORS (SETTERS):
void Account::setAmount(double amount)
{
    this->amount = amount;
}

void Account::setAccountNumber(int AccountNumber)
{
    accountNumber = AccountNumber;
}

/*
//other
virtual char Account::validator(double)
{
    return 0;
}
*/
