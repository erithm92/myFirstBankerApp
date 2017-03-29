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
    QString accountNumQString = QString::number(myUser->getSavingsAcc());
    QString accString = "account # : " + accountNumQString;
    accountNumView = new QTextEdit(accString);

    QString amountNumQString = QString::number(myUser->getSavingsAmount());
    QString amString = "account # : " + amountNumQString;
    amountNumView = new QTextEdit(amString);

    QString interestQString = QString::number(myUser->getSavingsInterest());
    QString intString = "interest: " + interestQString;
    interestView = new QTextEdit(intString);

    showUser = new QTextEdit(myUser->getName());

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

    QHBoxLayout *textlayout1 = new QHBoxLayout;
    textlayout1->addWidget(showUser);
    textlayout1->addWidget(accountNumView);
    QHBoxLayout *textlayout2 = new QHBoxLayout;
    textlayout2->addWidget(amountNumView);
    textlayout2->addWidget(interestView);


    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(textlayout1);
    mainLayout->addLayout(textlayout2);
    setLayout(mainLayout);
}
