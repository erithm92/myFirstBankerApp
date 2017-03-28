#ifndef USER_H
#define USER_H

#include <QWidget>
#include<QPushButton>
#include<QHBoxLayout>
#include<QTextEdit>
#include <QtCore/QCoreApplication>
#include <QObject>
#include <QString>

#include "checkings.h"
#include "savings.h"

class User
{
public:
    User();
    User(Checkings&, Savings&); // <Tandy> edit to comply with C2248

    void setSavings(Savings&);
    void setCheckings(Checkings&);
    double getSavingsAmount();
    int getSavingsAcc();
    double getSavingsInterest();
    double getCheckingsAmount();
    int getCheckingsAcc();
    double getCheckingsOverdraft();

    void setName(const QString &string);
    QString getName() const;

    void openTransactions(); //slot for showTransactions
    void transferFunds(); //slot for transferFunds



private:
    Savings *mySavings = NULL;
    Checkings *myCheckings = NULL;
    QString name;

//    static Savings* mySavings; // <Tandy> changing objects to pointers to solve error C2248: "cannot access private member..."
//    static Checkings* myCheckings; // <Tandy> changing objects to pointers to solve error C2248: "cannot access private member..."
};

#endif // USER_H
