#include "TransferWindow.h"

TransferWindow::TransferWindow(QWidget *parent) : QWidget(parent)
{


}

void TransferWindow::buildWindow(User& user)
{   // need to resolve this shallow copy
    //myUser is an instance and user is also another instance

    myUser = &user;


    QString savamountNumQString = QString::number(myUser->getSavingsAmount());
    QString savamString = "Savings: $" + savamountNumQString;
    savAmountNumView = new QTextEdit(savamString);

    QString checkamountNumQString = QString::number(myUser->getCheckingsAmount());
    QString checkamString = "Checkings: " + checkamountNumQString;
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
        QHBoxLayout *transLayout = new QHBoxLayout;
            transLayout->addWidget(transfer);
            transLayout->addWidget(transAmt);

    transferSavings = new QPushButton("Savings -> Checkings");
    transferCheckings = new QPushButton("Checkings -> Savings");

    connect(transferSavings, SIGNAL (released()), this, SLOT (savTochec()));
    connect(transferCheckings, SIGNAL (released()), this, SLOT (checTosav()));

        QHBoxLayout *buttonlayout = new QHBoxLayout;
            buttonlayout->addWidget(transferSavings);
            buttonlayout->addWidget(transferCheckings);

        QVBoxLayout *mainLayout = new QVBoxLayout();
            mainLayout->addLayout(textlayout);
            mainLayout->addLayout(transLayout);
            mainLayout->addLayout(buttonlayout);
            setLayout(mainLayout);

}

void TransferWindow::transferWin()
{

}

void TransferWindow::checTosav()
{
     // i need to know the primitive datatype your trying to access
    // otherwise this is not possible
//   Checkings checking  = myUser->getCheckings();
//    Savings saving = myUser->getSavings();
  //  myUser->transferFunds(checking, saving, transAmt->value());
    UpdateWindow();
}

void TransferWindow::savTochec()
{
    //QString amount = transferAmt->text();
    //double temp = amount.toDouble();
  //  Checkings checking = myUser->getCheckings();
    //Savings saving = myUser->getSavings();
 //   myUser->transferFunds(saving, checking, transAmt->value());
    UpdateWindow();
}
void TransferWindow::UpdateWindow()
{
    QString savamountNumQString = QString::number(myUser->getSavingsAmount());
    QString savamString = "Savings: $" + savamountNumQString;
    savAmountNumView->setText(savamString);
    QString checkamountNumQString = QString::number(myUser->getCheckingsAmount());
    QString checkamString = "Checkings: " + checkamountNumQString;
    checkAmountNumView->setText(checkamString);
}
