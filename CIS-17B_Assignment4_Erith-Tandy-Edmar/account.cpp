#include "account.h"

Account::Account()
{
    accountNumber++;
}
double Account::getAmount(){return amount;}
void Account::setAmount(double amount)
{
    this->amount = amount;
}
int Account::getAccountNumber(){return accountNumber;}
