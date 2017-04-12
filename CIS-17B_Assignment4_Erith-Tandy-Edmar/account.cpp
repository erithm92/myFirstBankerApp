#include "Account.h"

//DATA:
int Account::accounts = 0;

//CONSTRUCTORS:
Account::Account()
{
    accounts++;
    accountNumber = accounts;
}

//ACCESSORS (GETTERS):
int Account::getAccountNumber(){return accountNumber;}

double Account::getAmount(){return amount;}

//MUTATORS (SETTERS):
void Account::setAmount(double amount)
{
    this->amount = amount;
}

/*
//other
virtual char Account::validator(double)
{
    return 0;
}
*/
