#include "LoginWindow.h"

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent)
{

}
void LoginWindow::buildWindow(User& user)
{
    myUser = &user;
    username = new QLabel("Username:");
    userField = new QLineEdit("");
    QHBoxLayout *userLine = new QHBoxLayout;
    userLine->addWidget(username);
    userLine->addWidget(userField);
    password = new QLabel("Password:");
    passField = new QLineEdit("");
    passField->setEchoMode(QLineEdit::Password);
    QHBoxLayout *passLine = new QHBoxLayout;
    passLine->addWidget(password);
    passLine->addWidget(passField);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(userLine);
    mainLayout->addLayout(passLine);
    setLayout(mainLayout);
}
