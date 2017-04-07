#include "TransferWindow.h"

TransferWindow::TransferWindow(QWidget *parent) : QWidget(parent)
{

}
void TransferWindow::buildWindow(User& user)
{
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
    transferAmt = new QLineEdit("0.00");
    QDoubleValidator *dv= new QDoubleValidator(0.00, 99999.99,2, this);
    dv->setNotation(QDoubleValidator::StandardNotation);
    transferAmt->setValidator(dv);

    transferSavings = new QPushButton("Savings -> Checkings");
    transferCheckings = new QPushButton("Checkings -> Savings");

        QHBoxLayout *buttonlayout = new QHBoxLayout;
            buttonlayout->addWidget(transferSavings);
            buttonlayout->addWidget(transferCheckings);

        QVBoxLayout *mainLayout = new QVBoxLayout();
            mainLayout->addLayout(textlayout);
            mainLayout->addLayout(buttonlayout);
            setLayout(mainLayout);

}

void TransferWindow::transferWin()
{

}

void TransferWindow::checTosav()
{
    QString amount = transferAmt->text();
    double temp = amount.toDouble();
    Checkings checking = myUser->getCheckings();
    Savings saving = myUser->getSavings();
    myUser->transferFunds(checking, saving, temp);
    update();
}

void TransferWindow::savTochec()
{
       QString amount = transferAmt->text();
       double temp = amount.toDouble();
       Checkings checking = myUser->getCheckings();
       Savings saving = myUser->getSavings();
       myUser->transferFunds(saving, checking, temp);
       update();
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
