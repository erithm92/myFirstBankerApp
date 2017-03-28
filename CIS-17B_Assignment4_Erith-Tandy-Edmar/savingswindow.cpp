#include "savingswindow.h"
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTextEdit>

SavingsWindow::SavingsWindow(QWidget *parent) : QWidget(parent)
{

}
void SavingsWindow::setUser(User& user)
{
    myUser = &user;
}
void SavingsWindow::buildWindow()
{
    accountNumView = new QTextEdit("account#: "/* + savingsAcc*/);
    amountNumView = new QTextEdit("amount: "/* + savingsAm*/);
    double interest = myUser->getSavingsInterest();
    QString interestQString = QString::number(interest);
    QString intString = "interest: " + interestQString;

    interestView = new QTextEdit(intString);
    showUser = new QTextEdit("user: " /* + myUser->getName()*/);

    accountNumView->setReadOnly(true);
    amountNumView->setReadOnly(true);
    interestView->setReadOnly(true);
    showUser->setReadOnly(true);

    QSize accountNumViewSize = accountNumView->document()->size().toSize();
    accountNumViewSize.setWidth(QWIDGETSIZE_MAX);
    accountNumViewSize.setHeight(25);
    accountNumView->setMaximumSize(accountNumViewSize);

    QSize amountNumViewSize = amountNumView->document()->size().toSize();
    amountNumViewSize.setWidth(QWIDGETSIZE_MAX);
    amountNumViewSize.setHeight(25);
    amountNumView->setMaximumSize(amountNumViewSize);

    QSize interestViewSize = interestView->document()->size().toSize();
    interestViewSize.setWidth(QWIDGETSIZE_MAX);
    interestViewSize.setHeight(25);
    interestView->setMaximumSize(interestViewSize);

    QSize showUserSize = showUser->document()->size().toSize();
    showUserSize.setWidth(QWIDGETSIZE_MAX);
    showUserSize.setHeight(25);
    showUser->setMaximumSize(showUserSize);

    QHBoxLayout *textlayout = new QHBoxLayout;
    textlayout->addWidget(accountNumView);
    textlayout->addWidget(amountNumView);
    textlayout->addWidget(interestView);
    textlayout->addWidget(showUser);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(textlayout);
    setLayout(mainLayout);
}
