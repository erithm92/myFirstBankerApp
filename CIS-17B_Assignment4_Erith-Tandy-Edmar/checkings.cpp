#include "Checkings.h"

//CONSTRUCTORS:
Checkings::Checkings()
{
    overdraftFee = 35;
    setAmount(1000, true);
}

// <Tandy> defining copy contructor for user.cpp line 9 to fix "attempting to reference a deleted function"
Checkings::Checkings(Checkings &obj){
    overdraftFee = obj.getOverdraft();
}

//ACCESSORS (GETTERS):
double Checkings::getOverdraft()
{
    return overdraftFee;
}

//validator
char validator(double withdraw){ // <Tandy> validator for overdraft
    if ((amount - withdraw) >= 0){
        return 'T';
    }
    else if((amount - withdraw) < 0 && (amount - withdraw) >= -300){
        return 'O';
    }
    else{
        return 'F';
    }
}
