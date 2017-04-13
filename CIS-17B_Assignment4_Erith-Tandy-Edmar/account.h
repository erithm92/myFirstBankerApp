#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QMessageBox>
class Account
{
protected:
    //DATA:
    double amount;
    int accountNumber;
    int accounts;

public:
    //DATA:
   // static int accounts; // <Tandy> edit to comply with C2248; removing const to make value modifiable in account.cpp line 5

    //CONSTRUCTORS:
    Account();
    Account(const Account& );

    //ACCESSORS (GETTERS):
    double getAmount();
    int getAccountNumber();


    //MUTATORS (SETTERS):
    void setAmount(double);
    void setAccountNumber(int);
    void deposit(double);


};

#endif // ACCOUNT_H
