#include "window.h"
#include<QPushButton>
#include <QMessageBox>

Window::Window(QWidget *parent) : QWidget(parent)
{


}
void Window::buildWindow(User& user)
{
    myUser = &user;

    switchSavingsButton = new QPushButton("Savings");
    switchCheckingButton = new QPushButton("Checking");
    transferFundsButton = new QPushButton("Transfer Funds");
    showTransHistoryButton = new QPushButton("Transaction History");
   // connect(switchSavingsButton,SIG )
     connect(switchSavingsButton, SIGNAL (released()), this, SLOT (winsav()));
     connect(switchCheckingButton, SIGNAL (released()), this, SLOT (winche()));
     // connect(m_button, SIGNAL (released()), this, SLOT (handleButton()));
     QHBoxLayout *buttonlayout = new QHBoxLayout;
     buttonlayout->addWidget(switchSavingsButton);
     buttonlayout->addWidget(switchCheckingButton);
     buttonlayout->addWidget(transferFundsButton);
     buttonlayout->addWidget(showTransHistoryButton);

     QString amountNumQString = QString::number(myUser->getSavingsAmount());
     QString amString = "Savings : $" + amountNumQString;
     savingsAmt = new QTextEdit(amString);

     QString amountNumQString2 = QString::number(myUser->getCheckingsAmount());
     QString amString2 = "Checkings : $" + amountNumQString2;
     checkingsAmt = new QTextEdit(amString2);

     QSize savingsSize = savingsAmt->document()->size().toSize();
     savingsSize.setWidth(QWIDGETSIZE_MAX);
     savingsSize.setHeight(25);
     savingsAmt->setMaximumSize(savingsSize);

     QSize checkingsSize = checkingsAmt->document()->size().toSize();
     checkingsSize.setWidth(QWIDGETSIZE_MAX);
     checkingsSize.setHeight(25);
     checkingsAmt->setMaximumSize(checkingsSize);


     savingsAmt->setReadOnly(true);
     checkingsAmt->setReadOnly(true);

     QHBoxLayout *textlayout = new QHBoxLayout;
     textlayout->addWidget(savingsAmt);
     textlayout->addWidget(checkingsAmt);




     QVBoxLayout *mainLayout = new QVBoxLayout();
     mainLayout->addLayout(textlayout);
     mainLayout->addLayout(buttonlayout);
     setLayout(mainLayout);
}

void Window::setCheckWindow(CheckingsWindow& cwindow)
{
    checkingsWindow = &cwindow;
}
void Window::setSaveWindow(SavingsWindow& swindow)
{
    savingsWindow = &swindow;
}
//slot emitter created by Edmar
void Window::winche()
{
    checkingsWindow->show();

}

void Window::winsav()
{
    savingsWindow->show();
}
