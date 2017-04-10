#ifndef TRANSFERWINDOW_H
#define TRANSFERWINDOW_H

#include "user.h"

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QMessageBox>
#include <QLabel>
#include <QValidator>

class TransferWindow : public QWidget
{
    Q_OBJECT
private:
    QPushButton *transferSavings = NULL;
    QPushButton *transferCheckings = NULL;
    QLabel *transfer = NULL;
    QLineEdit *transferAmt = NULL;
    QTextEdit *savAmountNumView = NULL;
    QTextEdit *checkAmountNumView = NULL;

    User *myUser = NULL;

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
