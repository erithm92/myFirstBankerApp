#include "SavingsWindow.h"

#include <QWidget>
#include <QTextEdit>

#include <QHBoxLayout>
#include <QPushButton>

//CONSTRUCTORS:
SavingsWindow::SavingsWindow(QWidget *parent) : QWidget(parent)
{

}

//MUTATORS (SETTERS):
void SavingsWindow::setUser(User& user)
{
    myUser = &user;
}

//VOID FUNCTIONS:
void SavingsWindow::buildWindow()
{
    //User
    showUser = new QTextEdit(myUser->getName());

    QSize showUserSize = showUser->document()->size().toSize();
        showUserSize.setWidth(QWIDGETSIZE_MAX);
        showUserSize.setHeight(25);
    showUser->setMaximumSize(showUserSize);

    //Account#
    QString accountNumQString = QString::number(myUser->getSavingsAcc());
    QString accString = "Account #: " + accountNumQString;
    accountNumView = new QTextEdit(accString);

    QSize accountNumViewSize = accountNumView->document()->size().toSize();
        accountNumViewSize.setWidth(QWIDGETSIZE_MAX);
        accountNumViewSize.setHeight(25);
    accountNumView->setMaximumSize(accountNumViewSize);

    //Amount
    QString amountNumQString = QString::number(myUser->getSavingsAmount());
    QString amString = "Amount: " + amountNumQString;
    amountNumView = new QTextEdit(amString);

    QSize amountNumViewSize = amountNumView->document()->size().toSize();
        amountNumViewSize.setWidth(QWIDGETSIZE_MAX);
        amountNumViewSize.setHeight(25);
    amountNumView->setMaximumSize(amountNumViewSize);

    //Interest Rate
    QString interestQString = QString::number(myUser->getSavingsInterest());
    QString intString = "Interest Rate: " + interestQString;
    interestView = new QTextEdit(intString);

    QSize interestViewSize = interestView->document()->size().toSize();
        interestViewSize.setWidth(QWIDGETSIZE_MAX);
        interestViewSize.setHeight(25);
    interestView->setMaximumSize(interestViewSize);

    //QHBoxLayout
    QHBoxLayout *textlayout1 = new QHBoxLayout;
        textlayout1->addWidget(showUser); // <Tandy> 1st: display User
        textlayout1->addWidget(accountNumView); // <Tandy> 2nd: display Account#

    QHBoxLayout *textlayout2 = new QHBoxLayout;
        textlayout2->addWidget(amountNumView); // <Tandy> 3rd: display Amount
        textlayout2->addWidget(interestView); // <Tandy> 4th: display Overdraft Fee

    QVBoxLayout *mainLayout = new QVBoxLayout();
        mainLayout->addLayout(textlayout1);
        mainLayout->addLayout(textlayout2);
        setLayout(mainLayout);

    // <Tandy> Set all to true to make text read-only
    accountNumView->setReadOnly(true);
    amountNumView->setReadOnly(true);
    interestView->setReadOnly(true);
    showUser->setReadOnly(true);
}
