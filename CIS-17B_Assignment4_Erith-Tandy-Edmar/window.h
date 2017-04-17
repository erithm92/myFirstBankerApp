#ifndef WINDOW_H
#define WINDOW_H

#include "CheckingsWindow.h"
#include "SavingsWindow.h"
#include "TransferWindow.h"
#include <QObject>
#include <QWidget>
#include <QTextEdit>

#include <QHBoxLayout>
#include <QPushButton>
#include <QtCore/QCoreApplication>

class Window : public QWidget // <Tandy> Inherit from QWidget so this class can have Qt functionality
{
    Q_OBJECT // <Tandy> for Qt to work with this class

private:
    //QT:
    QPushButton *switchSavingsButton;
    QPushButton *switchCheckingButton;
    QPushButton *transferFundsButton;
    QPushButton *showTransHistoryButton;

    QTextEdit *savingsAmt;
    QTextEdit *checkingsAmt;
    SavingsWindow *savingsWindow;
    CheckingsWindow *checkingsWindow;
    TransferWindow *transWindow;

    User *myUser;

public:
    //QT:
    explicit Window(QWidget *parent = 0);

    //MUTATORS (SETTERS):
    void setCheckWindow(CheckingsWindow&);
    void setSaveWindow(SavingsWindow&);
    void setTransWindow(TransferWindow&);

    //VOID FUNCTIONS:
    void buildWindow(User& user);
    void updateWindow(); // <Tandy> updates the window with current che/sav amounts
    void updateCheckings(); // <Tandy> updates the checkings window with current amount
    void updateSavings(); // <Tandy> updates the savings window with current amount

signals:

public slots:
    //Checkings
    void winche(); // <Tandy> Edmar's slot to create a Checkings window
    //Savings
    void winsav(); // <Tandy> Edmar's slot to create a Savings window
    //Transfer
    void transWin();//
    void transUpdate(); // <Tandy> this will receive a signal emitted from TransferWindow to call update functions
    //Transaction History
    void tranHisWin(); // to be implemented
};

#endif // WINDOW_H
