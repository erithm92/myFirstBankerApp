#include "checkingswindow.h"
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTextEdit>

CheckingsWindow::CheckingsWindow(QWidget *parent) : QWidget(parent)
{
//    accountNumView = new QTextEdit(Savings.getAccountNumber());
    accountNumView = new QTextEdit("account#: 123");
    amountNumView = new QTextEdit("amount: $123");
    overdraftView = new QTextEdit("overdraft fee: 12.3%");
    showUser = new QTextEdit("user: Name");

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

    QHBoxLayout *textlayout = new QHBoxLayout;
    textlayout->addWidget(accountNumView);
    textlayout->addWidget(amountNumView);
    textlayout->addWidget(overdraftView);
    textlayout->addWidget(showUser);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(textlayout);
    setLayout(mainLayout);
}
void CheckingsWindow::setUser(User& user)
{
    myUser = &user;
}

