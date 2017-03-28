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
//    Savings(Savings &obj); // <Tandy> declaring copy contructor for user.cpp line 10 to fix "attempting to reference a deleted function"
    double getInterest();
    void setInterest(double);
    double annualInterest; // <Tandy> edit to comply with C2248
private:
//    double annualInterest;
   // SavingsWindow myWindow;
//    Savings(Savings &obj); // <Tandy> declaring copy contructor for user.cpp line 10 to fix "attempting to reference a deleted function"
};

#endif // SAVINGS_H
