#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include<QPushButton>
#include<QHBoxLayout>
#include<QTextEdit>
#include <QtCore/QCoreApplication>
#include <QObject>

#include "savingswindow.h"
#include "checkingswindow.h"
class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);
    void setCheckWindow(CheckingsWindow&);
    void setSaveWindow(SavingsWindow&);
private:
    QPushButton *switchSavingsButton;
    QPushButton *switchCheckingButton;
    QPushButton *transferFundsButton;
    QPushButton *showTransHistoryButton;

    QTextEdit *savingsAmt;
    QTextEdit *checkingsAmt;
    SavingsWindow *savingsWindow;
    CheckingsWindow *checkingsWindow;


public slots:
    void winche();
    void winsav();
signals:


};

#endif // WINDOW_H
