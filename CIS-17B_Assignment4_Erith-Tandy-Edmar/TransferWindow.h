#ifndef TRANSFERWINDOW_H
#define TRANSFERWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QMessageBox>
#include "user.h"

class TransferWindow : public QWidget
{
    Q_OBJECT
private:
    QPushButton *transferSavings;
    QPushButton *transferCheckings;
    QTextEdit *transferAmt;
    QTextEdit *savAmountNumView;
    QTextEdit *checkAmountNumView;

    User *myUser;

public:
    explicit TransferWindow(QWidget *parent = 0);
    void buildWindow(User&);

signals:

public slots:
    void transferWin();

};

#endif // TRANSFERWINDOW_H
