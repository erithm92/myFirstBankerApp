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
void Window::setTransWindow(TransferWindow& twindow)
{
    transWindow = &twindow;
}

//VOID FUNCTIONS:
void Window::buildWindow(User& user)
{
    myUser = &user;

    //Checkings and Savings Amount
    QString checkAmountNumQString = QString::number(myUser->getCheckingsAmount());
    QString checkAmountString = "Checkings : $" + checkAmountNumQString;
    checkingsAmt = new QTextEdit(checkAmountString);

    QSize checkingsSize = checkingsAmt->document()->size().toSize();
    checkingsSize.setWidth(QWIDGETSIZE_MAX);
    checkingsSize.setHeight(25);
    checkingsAmt->setMaximumSize(checkingsSize);

    QString savAmountNumQString = QString::number(myUser->getSavingsAmount());
    QString savAmountString = "Savings : $" + savAmountNumQString;
    savingsAmt = new QTextEdit(savAmountString);

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
    //transfer
    connect(transferFundsButton, SIGNAL (released()), this, SLOT (transWin()));

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

void Window::updateWindow() // <Tandy> function to update window after transfers from TransferWindow.cpp
{
    QString checkAmountNumQString = QString::number(myUser->getCheckingsAmount());
    QString checkAmountString = "Checkings : $" + checkAmountNumQString;
    checkingsAmt->setText(checkAmountString);

    QString savAmountNumQString = QString::number(myUser->getSavingsAmount());
    QString savAmountString = "Savings : $" + savAmountNumQString;
    savingsAmt->setText(savAmountString);
}

void Window::updateCheckings() // <Tandy> updates the checkings window with current amount
{
    checkingsWindow->updateWindow(); // <Tandy> updates checkings window
}

void Window::updateSavings() // <Tandy> updates the savings window with current amount
{
    savingsWindow->updateWindow(); // <Tandy> updates savings window
}

//PUBLIC SLOTS:
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

//Transfer
void Window::transWin()
{
    transWindow->show();
}

void Window::transUpdate() // <Tandy> this will receive a signal emitted from TransferWindow to call update functions
{
    updateWindow();
    updateCheckings();
    updateSavings();
}

//Transaction History
void Window::tranHisWin()
{

}
