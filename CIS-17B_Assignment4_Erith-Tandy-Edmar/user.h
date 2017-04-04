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
#include <QList>
class User
{

private:
    //QT:
    Checkings *myCheckings = NULL;
    Savings *mySavings = NULL;
    QString name;
    struct transaction // <Tandy> Moved transaction struct into private above private QList so it can template that struct to hold a list of them.
    {
        int transactionID = 0;
        Account *accountNumDestination = NULL;
        int date = 0;
        Account *accountNUmberSource = NULL;
    };
    QList<transaction> transactionsList;

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
