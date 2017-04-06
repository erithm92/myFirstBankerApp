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
    //Savings
    void setSavings(Savings&);
    //User
    void setName(const QString &string);

    //VOID FUNCTIONS:
    //Transfer
    void openTransactions(); //slot for showTransactions
    void transferFunds(); //slot for transferFunds
    void showTransaction(int transactionDateOrID); /* <Tandy> Accesses User private QList TransactionsList;
    retrieves transaction struct; displays requested information from struct within QList */
};

#endif // USER_H
