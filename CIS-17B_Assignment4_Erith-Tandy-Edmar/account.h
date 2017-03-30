#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
    //DATA:
    double amount;
    int accountNumber;

public:
    //DATA:
    static int accounts; // <Tandy> edit to comply with C2248; removing const to make value modifiable in account.cpp line 5

    //CONSTRUCTORS:
    Account();

    //ACCESSORS (GETTERS):
    double getAmount();
    int getAccountNumber();

    //MUTATORS (SETTERS):
    void setAmount(double);
};

#endif // ACCOUNT_H
