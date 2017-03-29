#include "account.h"

Account::Account()
{
    accountNumber++;
}
int Account::accountNumber = 0;
double Account::getAmount(){return amount;}
void Account::setAmount(double amount)
{
    this->amount = amount;
}
int Account::getAccountNumber(){return accountNumber;}
