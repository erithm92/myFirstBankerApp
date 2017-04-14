#include "CheckingsWindow.h"

#include <QWidget>
#include <QTextEdit>

#include <QHBoxLayout>
#include <QPushButton>

//CONSTRUCTORS:
CheckingsWindow::CheckingsWindow(QWidget *parent) : QWidget(parent)
{
    //accountNumView = new QTextEdit(Savings.getAccountNumber());
}

//MUTATORS (SETTERS):
void CheckingsWindow::setUser(User& user)
{
    myUser = &user;
}

//VOID FUNCTIONS
void CheckingsWindow::buildWindow()
{
    //User
    showUser = new QTextEdit(myUser->getName());

    QSize showUserSize = showUser->document()->size().toSize();
        showUserSize.setWidth(QWIDGETSIZE_MAX);
        showUserSize.setHeight(25);
    showUser->setMaximumSize(showUserSize);

    //Account#
    QString accountNumQString = QString::number(myUser->getCheckingsAcc());
    QString accString = "Account #: " + accountNumQString;
    accountNumView = new QTextEdit(accString);

    QSize accountNumViewSize = accountNumView->document()->size().toSize();
        accountNumViewSize.setWidth(QWIDGETSIZE_MAX);
        accountNumViewSize.setHeight(25);
    accountNumView->setMaximumSize(accountNumViewSize);

    //Amount
    QString amountNumQString = QString::number(myUser->getCheckingsAmount());
    QString amString = "Amount: $" + amountNumQString;
    amountNumView = new QTextEdit(amString);

    QSize amountNumViewSize = amountNumView->document()->size().toSize();
        amountNumViewSize.setWidth(QWIDGETSIZE_MAX);
        amountNumViewSize.setHeight(25);
    amountNumView->setMaximumSize(amountNumViewSize);

    //Overdraft Fee
    QString overdraftNumQString = QString::number(myUser->getCheckingsOverdraft());
    QString overString = "Overdraft Fee: $" + overdraftNumQString;
    overdraftView = new QTextEdit(overString);

    QSize overdraftViewSize = overdraftView->document()->size().toSize();
        overdraftViewSize.setWidth(QWIDGETSIZE_MAX);
        overdraftViewSize.setHeight(25);
    overdraftView->setMaximumSize(overdraftViewSize);

    // <Tandy> Set all to true to make text read-only
    accountNumView->setReadOnly(true);
    amountNumView->setReadOnly(true);
    overdraftView->setReadOnly(true);
    showUser->setReadOnly(true);

    //QHBoxLayout
    QHBoxLayout *textlayout1 = new QHBoxLayout;
        textlayout1->addWidget(showUser); // <Tandy> 1st: display User
        textlayout1->addWidget(accountNumView); // <Tandy> 2nd: display Account#

    QHBoxLayout *textlayout2 = new QHBoxLayout;
        textlayout2->addWidget(amountNumView); // <Tandy> 3rd: display Amount
        textlayout2->addWidget(overdraftView); // <Tandy> 4th: display Overdraft Fee

    QVBoxLayout *mainLayout = new QVBoxLayout(); // <Tandy> put layouts 1 and 2 together to display in one window
        mainLayout->addLayout(textlayout1);
        mainLayout->addLayout(textlayout2);
        setLayout(mainLayout);
}

void CheckingsWindow::updateWindow() // <Tandy> updates the checkings window with current amount
{
    QString amountNumQString = QString::number(myUser->getCheckingsAmount());
    QString amString = "Amount: $" + amountNumQString;
    amountNumView->setText(amString);
}
