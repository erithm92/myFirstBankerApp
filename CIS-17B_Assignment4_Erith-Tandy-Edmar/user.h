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
#include <QDate>
class User
{

private:
    //QT:
    Savings *mySavings = NULL;
    Checkings *myCheckings = NULL;
    QString name;

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
    struct transaction
    {
        int transactionID = 0;
        QDate *date = NULL; // <Tandy> 99th day, 99th month, 9999th year
        Account *accountNUmberSource = NULL;
        Account *accountNumDestination = NULL;
    };

    void openTransactions(); //slot for showTransactions
    void transferFunds(); //slot for transferFunds

};

#endif // USER_H
