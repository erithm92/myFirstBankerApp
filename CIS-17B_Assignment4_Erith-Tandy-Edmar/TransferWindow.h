#ifndef TRANSFERWINDOW_H
#define TRANSFERWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QMessageBox>
#include <QLabel>
#include "user.h"
#include <QValidator>

class TransferWindow : public QWidget
{
    Q_OBJECT
private:
    QPushButton *transferSavings;
    QPushButton *transferCheckings;
    QLabel *transfer;
    QLineEdit *transferAmt;
    QTextEdit *savAmountNumView;
    QTextEdit *checkAmountNumView;

    User *myUser;

public:
    explicit TransferWindow(QWidget *parent = 0);
    void buildWindow(User&);
    void UpdateWindow();

signals:

public slots:
    void transferWin();
    void savTochec();
    void checTosav();
};

#endif // TRANSFERWINDOW_H
