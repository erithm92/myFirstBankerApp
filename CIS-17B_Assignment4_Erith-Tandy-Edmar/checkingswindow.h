#ifndef CHECKINGSWINDOW_H
#define CHECKINGSWINDOW_H

#include "User.h"

#include <QObject>
#include <QWidget>
#include <QTextEdit>

class CheckingsWindow : public QWidget
{
    Q_OBJECT // <Tandy> for Qt to work with this class

private:
    //QT:
    QTextEdit *accountNumView;
    QTextEdit *amountNumView;
    QTextEdit *overdraftView;
    QTextEdit *showUser;

public:
    //QT:
    explicit CheckingsWindow(QWidget *parent = 0);

    //DATA:
    User *myUser = NULL;

    //MUTATORS (SETTERS):
    void setUser(User&);

    //VOID FUNCTIONS:
    void buildWindow();
    void updateWindow(); // <Tandy> updates the checkings window with current amount

signals:

public slots:

};

#endif // CHECKINGSWINDOW_H
