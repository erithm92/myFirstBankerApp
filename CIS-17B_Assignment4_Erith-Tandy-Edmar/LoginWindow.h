#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include<QObject>
#include <QWidget>
#include<QHBoxLayout>
#include<QTextEdit>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>

#include "window.h"
#include "user.h"

class LoginWindow : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = 0);
    void buildWindow(User&);
    void setMainWindow(Window&);
private:
    QLineEdit *userField;
    QLineEdit *passField;
    QLabel *username;
    QLabel *password;
    User *myUser;

    QPushButton *login;

    Window *mainWindow;
signals:

public slots:
    void loginAttempt();
};

#endif // LOGINWINDOW_H
