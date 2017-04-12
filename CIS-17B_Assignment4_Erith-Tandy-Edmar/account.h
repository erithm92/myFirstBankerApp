#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
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

    //other
    //whats the virtual char for ?
    //virtual makes the entire class abstract which prevents it from having an instance
    virtual char validator(double){return 0;}
};

#endif // ACCOUNT_H
