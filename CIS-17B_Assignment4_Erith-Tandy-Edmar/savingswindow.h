#ifndef SAVINGSWINDOW_H
#define SAVINGSWINDOW_H

#include "User.h"

#include <QObject>
#include <QWidget>
#include <QTextEdit>

class SavingsWindow : public QWidget
{
    Q_OBJECT // <Tandy> for Qt to work with this class

private:
    //QT:
    QTextEdit *accountNumView;
    QTextEdit *amountNumView;
    QTextEdit *interestView;
    QTextEdit *showUser;

public:
    //QT:
    explicit SavingsWindow(QWidget *parent = 0);
    User *myUser = NULL;

    //MUTATORS (SETTERS):
    void setUser(User&);

    //VOID FUNCTIONS:
    void buildWindow();

signals:

public slots:

};

#endif // SAVINGSWINDOW_H
