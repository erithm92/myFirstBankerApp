#ifndef WINDOW_H
#define WINDOW_H

#include "CheckingsWindow.h"
#include "SavingsWindow.h"

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

    User *myUser;

public:
    //QT:
    explicit Window(QWidget *parent = 0);

    //MUTATORS (SETTERS):
    void setCheckWindow(CheckingsWindow&);
    void setSaveWindow(SavingsWindow&);

    //VOID FUNCTIONS:
    void buildWindow(User& user);

public slots:
    //Checkings
    void winche(); // <Tandy> Edmar's slot to create a Checkings window
    //Savings
    void winsav(); // <Tandy> Edmar's slot to create a Savings window

signals:

};

#endif // WINDOW_H
