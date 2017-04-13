#ifndef USER_H
#define USER_H

#include "Checkings.h"
#include "Savings.h"

#include <QObject>
#include <QWidget>
#include <QTextEdit>

#include <QHBoxLayout>
#include <QPushButton>
#include <QtCore/QCoreApplication>
#include <QString>
#include <list>
#include <QList>
#include <QDate>

class User
{

private:
    //QT:
    Checkings *myCheckings = NULL;
    Savings *mySavings = NULL;
    QString name;

    struct transaction // <Tandy> Moved transaction struct into private above private QList so it can template that struct to hold a list of them.
    {
        int transactionID = -1;
        int date = -999; // <Tandy> mmddyyyy is 8 digits
        Account *accountNumberSource = NULL;
        Account *accountNumDestination = NULL;
        int transfer = 0; // <Tandy> direction and magnitude of monetary transfer, with respect to Source and Destination;
        // the format is: direction withdraws from the Source to the Destination, and magnitude is the amount of money transferred;
        // example: when Source is a Checkings, Destination is a Savings, and transfer = 150, then: ;
        // 1) $150 is withdrawn from myCheckings (let's say there was $1000 in myCheckings originally);
        // 2) $150 is deposited to mySavings (let's say there was $1 in mySavings originally);
        // 3) after the transfer, there will be: $850 in myCheckings, and $151 in mySavings

    };
    std::list<transaction> transactionsList;

public:
    //CONSTRUCTORS:
    User();
    User(Checkings&, Savings&); // <Tandy> edit to comply with error C2248
//Edmar copy constructor added
    User (const User& );

    //ACCESSORS (GETTERS):
    //Checkings
    int getCheckingsAcc();
    double getCheckingsAmount();
    double getCheckingsOverdraft();
    //Savings
    int getSavingsAcc();
    double getSavingsAmount();
    double getSavingsInterest();
    //User
    QString getName() const;

    //MUTATORS (SETTERS):
    //Checkings
    void setCheckings(Checkings&);
    Checkings getCheckings();
    //Savings
    void setSavings(Savings&);
    Savings getSavings();
    //User


    void setName(const QString &string);

    //VOID FUNCTIONS:
    // this is too ambigious
//myUser->transferFunds(myUser->getSavings(),myUser->getCheckings(), temp);
    void transferFunds(Account source, Account destination, double amount);


    //Transfer

   // void openTransactions(); //slot for showTransactions
   // void transferFunds(); //slot for transferFunds
    //void showTransaction(int transactionDateOrID); /* <Tandy> Accesses User private QList TransactionsList;
   // retrieves transaction struct; displays requested information from struct within QList */

/*    struct transaction
    {
        int transactionID = 0;
        QDate *date = NULL; // <Tandy> 99th day, 99th month, 9999th year
        Account *accountNUmberSource = NULL;
        Account *accountNumDestination = NULL;
    };
*/
//    void openTransactions(); //slot for showTransactions
//    void transferFunds(); //slot for transferFunds

};

#endif // USER_H
