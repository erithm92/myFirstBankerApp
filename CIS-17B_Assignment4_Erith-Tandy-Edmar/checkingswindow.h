#ifndef CHECKINGSWINDOW_H
#define CHECKINGSWINDOW_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include "user.h"

class CheckingsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit CheckingsWindow(QWidget *parent = 0);
    User *myUser = NULL;
    void setUser(User&);
    void buildWindow();
private:
    QTextEdit *accountNumView;
    QTextEdit *amountNumView;
    QTextEdit *overdraftView;
    QTextEdit *showUser;
signals:

public slots:
};

#endif // CHECKINGSWINDOW_H
