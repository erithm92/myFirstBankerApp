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
  //  savAmountNumView = new QTextEdit("savamString");

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

                connect(transferCheckings, SIGNAL (released()), this, SLOT (checTosav()));
                connect(transferSavings, SIGNAL (released()), this, SLOT (savTochec()));




}

void TransferWindow::transferWin(User& user)
{



}
void TransferWindow::savTochec()
{
    QString savamountNumQString = QString::number(myUser->getSavingsAmount());
    QString savamString = "Savings: $" + savamountNumQString;
   // savAmountNumView = new QTextEdit(savamString);
    savAmountNumView = new QTextEdit("savamString");

    QString checkamountNumQString = QString::number(myUser->getCheckingsAmount());
    QString checkamString = "Checkings: $" + checkamountNumQString;
    checkAmountNumView = new QTextEdit(checkamString);


   /* QSize checkingsSize = checkAmountNumView->document()->size().toSize();
    checkingsSize.setWidth(QWIDGETSIZE_MAX);
    checkingsSize.setHeight(25);
    checkAmountNumView->setMaximumSize(checkingsSize);
*/

   /* QSize savingsSize = savAmountNumView->document()->size().toSize();
//    savingsSize.setWidth(QWIDGETSIZE_MAX);
//    savingsSize.setHeight(25);
//    savAmountNumView->setMaximumSize(savingsSize);
*/
        QHBoxLayout *textlayout = new QHBoxLayout;
            textlayout->addWidget(checkAmountNumView);
            textlayout->addWidget(savAmountNumView);

    transfer = new QLabel("Transfer Ammount");
    transferAmt = new QTextEdit("645");
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
               mainLayout->addLayout(buttonlayout);

/*        setLayout(mainLayout);
                connect(transferCheckings, SIGNAL (released()), this, SLOT (checTosav()));
                connect(transferSavings, SIGNAL (released()), this, SLOT (savTochec()));

*/



}





void TransferWindow::checTosav()
{
      QHBoxLayout *textlayout = new QHBoxLayout;
       textlayout->addWidget(checkAmountNumView);
        textlayout->addWidget(savAmountNumView);
        connect(transferCheckings, SIGNAL (released()), this, SLOT (checTosav()));
        connect(transferSavings, SIGNAL (released()), this, SLOT (savTochec()));
                QVBoxLayout *mainLayout = new QVBoxLayout();

setLayout(mainLayout);
}
