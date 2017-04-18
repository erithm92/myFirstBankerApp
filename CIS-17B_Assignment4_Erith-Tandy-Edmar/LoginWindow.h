#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include<QObject>
#include <QWidget>
#include<QHBoxLayout>
#include<QTextEdit>
#include<QLineEdit>
#include<QLabel>

#include "User.h"

class LoginWindow : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = 0);
    void buildWindow(User&);
private:
    QLineEdit *userField;
    QLineEdit *passField;
    QLabel *username;
    QLabel *password;
    User *myUser;
signals:

public slots:
};

#endif // LOGINWINDOW_H
