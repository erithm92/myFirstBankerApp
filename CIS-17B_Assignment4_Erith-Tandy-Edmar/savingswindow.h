#ifndef SAVINGSWINDOW_H
#define SAVINGSWINDOW_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include "user.h"

class SavingsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SavingsWindow(QWidget *parent = 0);
    void setUser(User&);
    void buildWindow();
    User *myUser = NULL;
private:
    QTextEdit *accountNumView;
    QTextEdit *amountNumView;
    QTextEdit *interestView;
    QTextEdit *showUser;

signals:

public slots:
};

#endif // SAVINGSWINDOW_H
