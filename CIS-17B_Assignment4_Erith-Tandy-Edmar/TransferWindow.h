#ifndef TRANSFERWINDOW_H
#define TRANSFERWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QMessageBox>
class TransferWindow : public QWidget
{
    Q_OBJECT
private:
    QPushButton *transferSavings;
    QPushButton *transferCheckings;
    QTextEdit *transfer;



public:
    explicit TransferWindow(QWidget *parent = 0);

signals:

public slots:
    void transferWin();


};

#endif // TRANSFERWINDOW_H
