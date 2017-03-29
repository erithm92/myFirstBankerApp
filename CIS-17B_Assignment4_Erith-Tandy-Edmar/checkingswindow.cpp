#include "checkingswindow.h"
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTextEdit>

CheckingsWindow::CheckingsWindow(QWidget *parent) : QWidget(parent)
{
//    accountNumView = new QTextEdit(Savings.getAccountNumber());
}
void CheckingsWindow::setUser(User& user)
{
    myUser = &user;
}
void CheckingsWindow::buildWindow()
{
    QString accountNumQString = QString::number(myUser->getCheckingsAcc());
    QString accString = "account # : " + accountNumQString;
    accountNumView = new QTextEdit(accString);

    QString amountNumQString = QString::number(myUser->getCheckingsAmount());
    QString amString = "amount : $" + amountNumQString;
    amountNumView = new QTextEdit(amString);

    QString overdraftNumQString = QString::number(myUser->getCheckingsOverdraft());
    QString overString = "overdraft fee: $" + overdraftNumQString;
    overdraftView = new QTextEdit(overString);

    showUser = new QTextEdit(myUser->getName());

    accountNumView->setReadOnly(true);
    amountNumView->setReadOnly(true);
    overdraftView->setReadOnly(true);
    showUser->setReadOnly(true);

    QSize accountNumViewSize = accountNumView->document()->size().toSize();
    accountNumViewSize.setWidth(QWIDGETSIZE_MAX);
    accountNumViewSize.setHeight(25);
    accountNumView->setMaximumSize(accountNumViewSize);

    QSize amountNumViewSize = amountNumView->document()->size().toSize();
    amountNumViewSize.setWidth(QWIDGETSIZE_MAX);
    amountNumViewSize.setHeight(25);
    amountNumView->setMaximumSize(amountNumViewSize);

    QSize overdraftViewSize = overdraftView->document()->size().toSize();
    overdraftViewSize.setWidth(QWIDGETSIZE_MAX);
    overdraftViewSize.setHeight(25);
    overdraftView->setMaximumSize(overdraftViewSize);

    QSize showUserSize = showUser->document()->size().toSize();
    showUserSize.setWidth(QWIDGETSIZE_MAX);
    showUserSize.setHeight(25);
    showUser->setMaximumSize(showUserSize);

    QHBoxLayout *textlayout1 = new QHBoxLayout;
    textlayout1->addWidget(accountNumView);
    textlayout1->addWidget(showUser);
     QHBoxLayout *textlayout2 = new QHBoxLayout;
    textlayout2->addWidget(amountNumView);
    textlayout2->addWidget(overdraftView);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(textlayout1);
    mainLayout->addLayout(textlayout2);
    setLayout(mainLayout);
}

