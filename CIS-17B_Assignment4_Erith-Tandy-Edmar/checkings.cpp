#include "Checkings.h"

//CONSTRUCTORS:
Checkings::Checkings()
{
    this->overdraftFee = 35;
    this->setAmount(1000);
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
bool Checkings::withdrawl(double amt)
{
    if(this->getAmount() - amt < -300)
    {
        QMessageBox msgBox;
        msgBox.setText("Not enough funds!");
        msgBox.exec();
        return false;
    }
    else if(this->getAmount() - amt < 0 && this->getAmount() - amt > -300)
    {
        this->setAmount(this->getAmount() - this->overdraftFee);
        this->setAmount(this->getAmount() - amt);
        return true;
    }
    else
    {
        this->setAmount(this->getAmount() - amt);
        return true;
    }
}
