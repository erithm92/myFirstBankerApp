#ifndef TRANSFERWINDOW_H
#define TRANSFERWINDOW_H

#include <QWidget>
#include <QButtonGroup>
#include <QTextEdit>

class TransferWindow : public QWidget
{
    Q_OBJECT
private:
    QPushButton *transferSavings;
    QPushButton *transferCheckings;

public:
    explicit TransferWindow(QWidget *parent = 0);

signals:

public slots:

};

#endif // TRANSFERWINDOW_H
