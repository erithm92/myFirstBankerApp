#ifndef SAVINGS_H
#define SAVINGS_H

#include "account.h"
//#include "savingswindow.h"
// #include "user.h" // <Tandy> edit to comply with C2248

class Savings : public Account
{
// friend class User; // <Tandy> edit to comply with C2248
public:
    Savings();
    double getInterest();
    void setInterest(double);
//    Savings(Savings &obj); // <Tandy> declaring copy contructor for user.cpp line 10 to fix "attempting to reference a deleted function"
     // <Tandy> edit to comply with C2248
private:

    double annualInterest;
};

#endif // SAVINGS_H
