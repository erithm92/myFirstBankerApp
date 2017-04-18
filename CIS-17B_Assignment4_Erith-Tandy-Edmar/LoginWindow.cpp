#include "LoginWindow.h"
#include <QMessageBox>
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

    login = new QPushButton("Login");
    connect(login, SIGNAL (released()), this, SLOT (loginAttempt()));

    QHBoxLayout *buttonline = new QHBoxLayout;
    buttonline->addWidget(login);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(userLine);
    mainLayout->addLayout(passLine);
    mainLayout->addLayout(buttonline);
    setLayout(mainLayout);
}
void LoginWindow::loginAttempt()
{
    QMessageBox wrongUser;
    wrongUser.setText("No User Exists!");
    QMessageBox wrongPass;
    wrongPass.setText("Wrong Password!");


    QString storedUN = myUser->getUserName();
    QString storedPass = myUser->getPassword();

    int u = QString::compare(storedUN, userField->text(), Qt::CaseInsensitive);
    int p = QString::compare(storedPass, passField->text(), Qt::CaseInsensitive);
    if(u != 0)
    {
        wrongUser.exec();
    }
    else if(p!=0)
    {
        wrongPass.exec();
    }
    else
    {
        mainWindow->show();
        close();
    }

}
void LoginWindow::setMainWindow(Window& win)
{
    mainWindow = &win;
}
