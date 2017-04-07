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

    transfer = new QLabel("Transfer Ammount");
    transferAmt = new QTextEdit("");
    QSize transSize = transferAmt->document()->size().toSize();
    transSize.setWidth(QWIDGETSIZE_MAX);
    transSize.setHeight(25);
    transferAmt->setMaximumSize(transSize);

        QHBoxLayout *transline = new QHBoxLayout;
            transline->addWidget(transfer);
            transline->addWidget(transferAmt);

    transferSavings = new QPushButton("Savings -> Checkings");
    transferCheckings = new QPushButton("Checkings -> Savings");

        QHBoxLayout *buttonlayout = new QHBoxLayout;
            buttonlayout->addWidget(transferSavings);
            buttonlayout->addWidget(transferCheckings);

        QVBoxLayout *mainLayout = new QVBoxLayout();
            mainLayout->addLayout(textlayout);
            mainLayout->addLayout(transline);
            mainLayout->addLayout(buttonlayout);
            setLayout(mainLayout);

}

void TransferWindow::transferWin()
{

}
void TransferWindow::savTochec()
{

}

void TransferWindow::checTosav()
{

}
