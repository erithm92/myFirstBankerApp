#include "TransferWindow.h"

//CONSTRUCTORS
TransferWindow::TransferWindow(QWidget *parent) : QWidget(parent)
{

}

//VOID FUNCTIONS
void TransferWindow::buildWindow(User& user)
{   // need to resolve this shallow copy
    //myUser is an instance and user is also another instance

    myUser = &user;

    QString savamountNumQString = QString::number(myUser->getSavingsAmount());
    QString savamString = "Savings: $" + savamountNumQString;
    savAmountNumView = new QTextEdit(savamString);

    QString checkamountNumQString = QString::number(myUser->getCheckingsAmount());
    QString checkamString = "Checkings: $" + checkamountNumQString;
    checkAmountNumView = new QTextEdit(checkamString);


    QSize checkingsSize = checkAmountNumView->document()->size().toSize();
    checkingsSize.setWidth(QWIDGETSIZE_MAX);
    checkingsSize.setHeight(25);
    checkAmountNumView->setMaximumSize(checkingsSize);


    QSize savingsSize = savAmountNumView->document()->size().toSize();
    savingsSize.setWidth(QWIDGETSIZE_MAX);
    savingsSize.setHeight(25);
    savAmountNumView->setMaximumSize(savingsSize);

        QHBoxLayout *textlayout = new QHBoxLayout;
            textlayout->addWidget(checkAmountNumView);
            textlayout->addWidget(savAmountNumView);

    transfer = new QLabel("Transfer Amount");
    transAmt = new QDoubleSpinBox;
    transAmt->setDecimals(2);
    transAmt->setRange(0,10000);
        QHBoxLayout *transLayout = new QHBoxLayout;
            transLayout->addWidget(transfer);
            transLayout->addWidget(transAmt);

    transferCheckings = new QPushButton("Checkings -> Savings");
    transferSavings = new QPushButton("Savings -> Checkings");

    connect(transferCheckings, SIGNAL (released()), this, SLOT (checTosav()));
    connect(transferSavings, SIGNAL (released()), this, SLOT (savTochec()));

        QHBoxLayout *buttonlayout = new QHBoxLayout;
            buttonlayout->addWidget(transferCheckings);
            buttonlayout->addWidget(transferSavings);

        QVBoxLayout *mainLayout = new QVBoxLayout();
            mainLayout->addLayout(textlayout);
            mainLayout->addLayout(transLayout);
            mainLayout->addLayout(buttonlayout);
            setLayout(mainLayout);

    // <Tandy> setReadOnly to true for Checkings and Savings amount to make text read-only
    checkAmountNumView->setReadOnly(true);
    savAmountNumView->setReadOnly(true);
}

void TransferWindow::UpdateWindow()
{
    QString checkamountNumQString = QString::number(myUser->getCheckingsAmount());
    QString checkamString = "Checkings: $" + checkamountNumQString;
    checkAmountNumView->setText(checkamString);
    QString savamountNumQString = QString::number(myUser->getSavingsAmount());
    QString savamString = "Savings: $" + savamountNumQString;
    savAmountNumView->setText(savamString);

    emit fundsTransferred(true);
}

//SIGNALS
//void fundsTransferred(bool transferred)

//PUBLIC SLOTS
void TransferWindow::transferWin()
{

}

void TransferWindow::checTosav()
{
    if(myUser->getCheckings()->withdrawl(transAmt->value()))
        myUser->getSavings()->deposit(transAmt->value());
    UpdateWindow();
}

void TransferWindow::savTochec()
{
    if(myUser->getSavings()->withdrawl(transAmt->value()))
        myUser->getCheckings()->deposit(transAmt->value());
    UpdateWindow();
}
