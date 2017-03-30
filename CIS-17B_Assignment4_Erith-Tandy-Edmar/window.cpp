#include "Window.h"

#include <QPushButton>
#include <QMessageBox>

//CONSTRUCTORS:
Window::Window(QWidget *parent) : QWidget(parent)
{

}

//MUTATORS (SETTERS):
//Checkings
void Window::setCheckWindow(CheckingsWindow& cwindow)
{
    checkingsWindow = &cwindow;
}

//Savings
void Window::setSaveWindow(SavingsWindow& swindow)
{
    savingsWindow = &swindow;
}

//VOID FUNCTIONS:
void Window::buildWindow(User& user)
{
    myUser = &user;

    //Checkings and Savings Amount
    QString amountNumQString2 = QString::number(myUser->getCheckingsAmount());
    QString amString2 = "Checkings : $" + amountNumQString2;
    checkingsAmt = new QTextEdit(amString2);

    QSize checkingsSize = checkingsAmt->document()->size().toSize();
    checkingsSize.setWidth(QWIDGETSIZE_MAX);
    checkingsSize.setHeight(25);
    checkingsAmt->setMaximumSize(checkingsSize);

    QString amountNumQString = QString::number(myUser->getSavingsAmount());
    QString amString = "Savings : $" + amountNumQString;
    savingsAmt = new QTextEdit(amString);

    QSize savingsSize = savingsAmt->document()->size().toSize();
    savingsSize.setWidth(QWIDGETSIZE_MAX);
    savingsSize.setHeight(25);
    savingsAmt->setMaximumSize(savingsSize);

        QHBoxLayout *textlayout = new QHBoxLayout;
            textlayout->addWidget(checkingsAmt);
            textlayout->addWidget(savingsAmt);

        // <Tandy> Set all to true to make text read-only
        savingsAmt->setReadOnly(true);
        checkingsAmt->setReadOnly(true);

    //QPushButton
    switchCheckingButton = new QPushButton("Checking");
    switchSavingsButton = new QPushButton("Savings");
    transferFundsButton = new QPushButton("Transfer Funds");
    showTransHistoryButton = new QPushButton("Transaction History");

    //Signals and Slots
    connect(switchCheckingButton, SIGNAL (released()), this, SLOT (winche()));
    connect(switchSavingsButton, SIGNAL (released()), this, SLOT (winsav()));

    //QHBoxLayout
    QHBoxLayout *buttonlayout = new QHBoxLayout;
        buttonlayout->addWidget(switchCheckingButton);
        buttonlayout->addWidget(switchSavingsButton);
        buttonlayout->addWidget(transferFundsButton);
        buttonlayout->addWidget(showTransHistoryButton);

    QVBoxLayout *mainLayout = new QVBoxLayout();
        mainLayout->addLayout(textlayout);
        mainLayout->addLayout(buttonlayout);
        setLayout(mainLayout);
}

//SLOT EMITTERS:
//Checkings
void Window::winche() //slot emitter created by Edmar
{
    checkingsWindow->show();
}

//Savings
void Window::winsav() //slot emitter created by Edmar
{
    savingsWindow->show();
}
