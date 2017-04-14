#ifndef TRANSFERWINDOW_H
#define TRANSFERWINDOW_H

#include "user.h"

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QMessageBox>
#include <QLabel>
#include <QDoubleSpinBox>



class TransferWindow : public QWidget
{
    Q_OBJECT
private:
    QPushButton *transferSavings = NULL;
    QPushButton *transferCheckings = NULL;
    QLabel *transfer = NULL;
    QDoubleSpinBox *transAmt = NULL;
    QTextEdit *savAmountNumView = NULL;
    QTextEdit *checkAmountNumView = NULL;

    User *myUser = NULL;

public:
    //QT
    explicit TransferWindow(QWidget *parent = 0);

    //VOID FUNCTIONS
    void buildWindow(User&);
    void UpdateWindow();

    //DATA

signals:

public slots:
    void transferWin();
    void savTochec();
    void checTosav();
};

#endif // TRANSFERWINDOW_H
