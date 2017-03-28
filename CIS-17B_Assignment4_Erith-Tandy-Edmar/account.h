#ifndef ACCOUNT_H
#define ACCOUNT_H

//#include "user.h"

class Account
{
public:
    Account();
    double getAmount();
    void setAmount(double);
    int getAccountNumber();
    int accountNumber = 0; // <Tandy> edit to comply with C2248; removing const to make value modifiable in account.cpp line 5
private:
    //User myUser;
    double amount;
//    static const int accountNumber = 0;
//    static int accountNumber; // <Tandy> removing const to make value modifiable in account.cpp line 5
};

#endif // ACCOUNT_H
