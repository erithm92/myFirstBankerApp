#ifndef CHECKINGS_H
#define CHECKINGS_H

#include "account.h"
//#include "checkingswindow.h"

class Checkings : public Account
{
public:
    Checkings();
    Checkings(Checkings &obj); // <Tandy> declaring copy contructor for user.cpp line 9 to fix "attempting to reference a deleted function"
    double getOverdraft();
private:
    double overdraftFee;
    //CheckingsWindow myWindow;
};

#endif // CHECKINGS_H
