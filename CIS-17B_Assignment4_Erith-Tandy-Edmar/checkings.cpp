#include "checkings.h"

Checkings::Checkings()
{
    overdraftFee = 35;
}

// <Tandy> defining copy contructor for user.cpp line 9 to fix "attempting to reference a deleted function"
Checkings::Checkings(Checkings &obj){
    overdraftFee = obj.getOverdraft();
}

double Checkings::getOverdraft()
{
    return overdraftFee;
}
